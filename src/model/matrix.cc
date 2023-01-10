#include "matrix.h"

auto s21::MatrixNetwork::random_weight() -> double {
  double rand = ((int)this->m_generator_() % 10000) * 0.0001;
  return rand;
}

auto s21::MatrixNetwork::feed_init_value(
    const s21::MatrixNetwork::vector_double &values) -> void {
  for (size_t i = 0; i < values.size(); i++) {
    this->m_neurons_[0][i][0] = values[i];
  }
}

auto s21::MatrixNetwork::feed_forward() -> void {
  for (auto i = 0; i < this->m_neurons_.size() - 1; i++) {
    this->m_neurons_[i + 1] = this->m_weights_[i] * this->m_neurons_[i];
    for (auto j = 0; j < this->m_neurons_[i + 1].GetRow(); j++) {
      this->m_neurons_[i + 1](j, 0) = this->activate_function(
          this->m_neurons_[i + 1](j, 0) + this->m_biases_[i]);
    }
  }
}

auto s21::MatrixNetwork::set_layers(std::vector<LayersInfo> info) -> void {
  this->bring_to_zero_all();
  this->change_random_device();
  for (size_t i = 0; i < info.size(); ++i) {
    this->m_topology_.emplace_back(info[i]);
  }
  for (size_t i = 0; i < info.size(); ++i) {
    this->m_neurons_.emplace_back(S21Matrix(info[i], 1));
    this->m_biases_.emplace_back(0);
    if (i != info.size() - 1) {
      this->m_weights_.emplace_back(S21Matrix(info[i + 1], info[i]));
      this->init_weight_matrix(this->m_weights_.back());
    }
  }
}

auto s21::MatrixNetwork::set_layers(std::initializer_list<size_type> items)
    -> void {
  this->bring_to_zero_all();
  this->change_random_device();
  for (auto i = 0; i < this->m_topology_.size(); ++i) {
    this->m_neurons_.emplace_back(S21Matrix(this->m_topology_[i], 1));
    this->m_biases_.emplace_back(0);
    if (i != this->m_topology_.size() - 1) {
      this->m_weights_.emplace_back(
          S21Matrix(this->m_topology_[i + 1], this->m_topology_[i]));
      this->init_weight_matrix(this->m_weights_.back());
    }
  }
}

auto s21::MatrixNetwork::activate_function(double value) -> double {
  return 1.0 / (1.0 + exp(-value));
}

auto s21::MatrixNetwork::activate_function_derivative(double value) -> double {
  return value * (1 - value);
}

auto s21::MatrixNetwork::init_weight_matrix(S21Matrix &matrix) -> void {
  for (auto i = 0; i < matrix.GetRow(); i++) {
    for (auto j = 0; j < matrix.GetColumn(); j++) {
      matrix(i, j) = this->random_weight();
    }
  }
}

auto s21::MatrixNetwork::bring_to_zero_all() -> void {
  this->clear_topology();
  this->clear_neurons();
  this->clear_biases();
}

auto s21::MatrixNetwork::clear_topology() -> void {
  if (!this->m_topology_.empty()) {
    this->m_topology_.clear();
    if (!this->m_topology_.empty()) {
      throw std::bad_alloc();
    }
  }
}

auto s21::MatrixNetwork::clear_biases() -> void {
  if (!this->m_biases_.empty()) {
    this->m_biases_.clear();
    if (!this->m_biases_.empty()) {
      throw std::bad_alloc();
    }
  }
}

auto s21::MatrixNetwork::clear_neurons() -> void {
  if (!this->m_neurons_.empty()) {
    for (auto &m_neuron : this->m_neurons_) {
      m_neuron.clear();
    }
    this->m_neurons_.clear();
    if (!this->m_neurons_.empty()) {
      throw std::bad_alloc();
    }
  }
}

auto s21::MatrixNetwork::change_random_device() -> void {
  std::random_device rd_;
  std::mt19937 temp(rd_());
  this->m_generator_ = temp;
}

namespace s21 {

auto MatrixNetwork::get_local_grads(std::vector<double> &LocalGrads,
                                    const std::vector<double> &ExpectedValues,
                                    size_t layer) -> void {
  if (LocalGrads.empty()) {
    for (size_t i = 0; i < m_neurons_.back().GetRow(); i++) {
      double error = ExpectedValues[i] - m_neurons_.back()[i][0];
      LocalGrads.push_back(
          error * activate_function_derivative(m_neurons_.back()[i][0]));
    }
  } else {
    std::vector<double> NewGrads;

    for (size_t i = 0; i < m_weights_[layer].GetColumn(); i++) {
      double teta = 0.;

      for (size_t j = 0; j < m_weights_[layer].GetRow(); j++) {
        teta += LocalGrads[j] * m_weights_[layer][j][i];
      }
      NewGrads.push_back(teta *
                         activate_function_derivative(m_neurons_[layer][i][0]));
    }
    LocalGrads = NewGrads;
  }
}

auto MatrixNetwork::back_propagation(std::vector<double> &ExpectedValues)
    -> void {
  std::vector<double> localGrads;
  for (int i = m_weights_.size() - 1; i >= 0; i--) {
    get_local_grads(localGrads, ExpectedValues, i + 1);

    for (size_t k = 0; k < m_weights_[i].GetColumn(); k++) {
      for (size_t j = 0; j < m_weights_[i].GetRow(); j++) {
        m_weights_[i][j][k] += step_ * localGrads[j] * m_neurons_[i][k][0];
      }
    }
  }
}

void MatrixNetwork::save_weights(std::string filename) {
  std::fstream file;
  file.open(filename, file.out);
  file << "Network weights" << std::endl;
  for (int i = 0; i < m_topology_.size(); i++) {
    file << m_topology_[i] << ' ';
  }
  file << '\n';
  for (size_t layer = 0; layer < m_weights_.size(); layer++) {
    for (size_t i = 0; i < m_weights_[layer].GetRow(); i++) {
      for (size_t j = 0; j < m_weights_[layer].GetColumn(); j++) {
        file << m_weights_[layer][i][j] << std::endl;
      }
    }
  }
  file.close();
}

auto MatrixNetwork::get_weights(std::string filename) -> bool {
  setlocale(LC_NUMERIC, "C");
  std::fstream file;
  file.open(filename, file.in);
  if (!file.is_open()) return false;

  std::string checkFile;
  std::getline(file, checkFile, '\n');
  if (checkFile != "Network weights") return false;
  std::string num;
  char c = 0;
  std::vector<size_t> topology;
  while (c != '\n' && !file.eof()) {
    c = 0;
    while (c != ' ' && c != '\n' && !file.eof()) {
      file.get(c);
      if (c != ' ' && c != '\n' && !file.eof()) {
        num += c;
      }
    }
    if (c != '\n') topology.push_back(std::stod(num));
    num = "";
  }
  if (check_topology(topology)) {
    for (size_t layer = 0; layer < m_weights_.size(); layer++) {
      for (size_t i = 0; i < m_weights_[layer].GetRow(); i++) {
        for (size_t j = 0; j < m_weights_[layer].GetColumn(); j++) {
          std::getline(file, num, '\n');
          double number = std::stod(num);
          m_weights_[layer][i][j] = number;
        }
      }
    }
  } else {
    return false;
  }
  file.close();
  return true;
}

auto MatrixNetwork::get_result() -> size_t {
  size_t res = 0;
  double max = m_neurons_.back()[0][0];
  for (int i = 0; i < m_neurons_.back().GetRow(); i++) {
    if (max < m_neurons_.back()[i][0]) {
      max = m_neurons_.back()[i][0];
      res = i;
    }
  }
  std::cout << "Where is a sig  " << res << std::endl;
  return res;
}

auto MatrixNetwork::get_result_vector() -> const std::vector<double> {
  std::vector<double> res(m_topology_.back());
  for (int i = 0; i < res.size(); i++) {
    res[i] = m_neurons_.back()[i][0];
  }
  return res;
}
}  // namespace s21

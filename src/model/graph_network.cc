#include "graph_network.h"

std::vector<double> s21::Graph::generation_weights(size_t nOfWeights) {
  std::vector<double> weights(nOfWeights);
  for (size_t i = 0; i < nOfWeights; i++) {
    weights[i] = ((int)m_generator_() % 10000) * 0.0001;
  }
  return weights;
}

auto s21::Graph::set_layers(std::vector<LayersInfo> info) -> void {
  this->bring_to_zero_all();
  this->change_random_device();
  for (size_t i = 0; i < info.size(); ++i) {
    m_topology_.emplace_back(info[i]);
  }
  for (size_t i = 0; i < m_topology_.size(); i++) {
    m_neurons_.push_back(Layer());
    m_biases_.push_back(0);
    for (size_t j = 0; j < m_topology_[i]; j++) {
      Neuron newNeuron;
      if (i != m_topology_.size() - 1)
        newNeuron.set_weights(this->generation_weights(m_topology_[i + 1]));
      m_neurons_[i].push_back(newNeuron);
    }
  }
}

auto s21::Graph::set_layers(std::initializer_list<size_t> items) -> void {
  this->bring_to_zero_all();
  this->change_random_device();
  for (size_t i = 0; i < m_topology_.size(); i++) {
    m_neurons_.push_back(Layer());
    m_biases_.push_back(0);
    for (size_t j = 0; j < m_topology_[i]; j++) {
      Neuron newNeuron;
      if (i != m_topology_.size() - 1)
        newNeuron.set_weights(this->generation_weights(m_topology_[i + 1]));
      m_neurons_[i].push_back(newNeuron);
    }
  }
}

void s21::Graph::feed_init_value(const std::vector<double> &vals) {
  for (size_t i = 0; i < m_neurons_[0].size(); i++) {
    m_neurons_[0][i].set_value(vals[i]);
  }
}
auto s21::Graph::feed_forward() -> void {
  for (size_t layer = 0; layer < m_neurons_.size() - 1; layer++) {
    for (size_t i = 0; i < m_neurons_[layer + 1].size(); i++) {
      double sum = 0.;
      for (size_t j = 0; j < m_neurons_[layer].size(); j++) {
        sum += m_neurons_[layer][j].get_weights(i) *
               m_neurons_[layer][j].get_value();
      }
      m_neurons_[layer + 1][i].set_value(
          this->activate_functions_sigmoid(sum + m_biases_[layer]));
    }
  }
}

auto s21::Graph::activate_functions_sigmoid(double value) -> double {
  return 1.0 / (1.0 + exp(-value));
}

auto s21::Graph::activate_function_derivative(double value) -> double {
  return value * (1 - value);
}

void s21::Graph::get_local_gards(std::vector<double> &LocalGrads,
                                 const std::vector<double> &ExpectedValues,
                                 size_t layer) {
  if (layer == m_neurons_.size() - 1) {
    // ???????????????? ???????????? ?????????????????? ?????????????????? ???? ?????????????? ?????????????????????? ???????????????? ????
    // ???????????????? ???????????????? ?? ???????????????????? ????????????????

    for (size_t i = 0; i < m_neurons_[layer].size(); i++) {
      double error = ExpectedValues[i] - m_neurons_[layer][i].get_value();
      LocalGrads.push_back(error * this->activate_function_derivative(
                                       m_neurons_[layer][i].get_value()));
    }
  } else {
    // ?????????? ???????????????? ?????????? ??????????????????, ?????????????? ???????????? ?????????????????? ???? ????????
    // ?????????????????????? ????????
    std::vector<double> NewGrads;

    for (size_t i = 0; i < m_neurons_[layer].size(); i++) {
      double teta = 0.;

      for (size_t j = 0; j < m_neurons_[layer + 1].size(); j++) {
        teta += LocalGrads[j] * m_neurons_[layer][i].get_weights(j);
      }
      NewGrads.push_back(teta * this->activate_function_derivative(
                                    m_neurons_[layer][i].get_value()));
    }
    LocalGrads = NewGrads;
  }
}

auto s21::Graph::back_propagation(vec_double &expected_values) -> void {
  std::vector<double> localGrads;
  // #pragma omp parallel for
  for (int i = m_neurons_.size() - 2; i >= 0; i--) {
    this->get_local_gards(localGrads, expected_values, i + 1);

    for (size_t j = 0; j < m_neurons_[i].size(); j++) {
      for (size_t k = 0; k < m_neurons_[i + 1].size(); k++) {
        m_neurons_[i][j].get_weights(k) +=
            m_step_ * localGrads[k] * m_neurons_[i][j].get_value();
      }
    }
  }
}

auto s21::Graph::save_weights(std::string filename) -> void {
  std::fstream file;
  file.open(filename, file.out);
  file << "Network weights" << std::endl;
  for (size_t i = 0; i < m_topology_.size(); i++) {
    file << m_topology_[i] << ' ';
  }
  file << '\n';
  for (size_t layer = 0; layer < m_neurons_.size() - 1; layer++) {
    for (size_t j = 0; j < m_neurons_[layer + 1].size(); j++) {
      for (size_t i = 0; i < m_neurons_[layer].size(); i++) {
        file << m_neurons_[layer][i].get_weights(j) << std::endl;
      }
    }
  }
  file.close();
}

//    auto s21::Graph::check_topology(const std::vector<size_t> &topology) ->
//    bool {
//        bool res = true;
//        if (topology.size() != m_topology_.size()) {
//            res = false;
//        } else {
//            for (int i = 0; i < topology.size(); i++) {
//                if (m_topology_[i] != topology[i]) res = false;
//            }
//        }
//        return res;
//    }

auto s21::Graph::get_weights(std::string filename) -> bool {
  std::fstream file;
  file.open(filename, file.in);
  /// ?????????????? ?????????????????? ????????????
  if (!file.is_open()) {
    return false;
  }

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
  if (this->check_topology(topology)) {
    for (size_t layer = 0; layer < m_neurons_.size() - 1; layer++) {
      for (size_t j = 0; j < m_neurons_[layer + 1].size(); j++) {
        for (size_t i = 0; i < m_neurons_[layer].size(); i++) {
          std::getline(file, num, '\n');
          double number = std::stod(num);
          m_neurons_[layer][i].get_weights(j) = number;
        }
      }
    }
  } else {
    return false;
  }
  file.close();
  return true;
}
auto s21::Graph::get_result() -> size_type {
  size_t res = 0;
  double max = m_neurons_.back()[0].get_value();
  for (size_t i = 0; i < m_neurons_.back().size(); i++) {
    if (max < m_neurons_.back()[i].get_value()) {
      max = m_neurons_.back()[i].get_value();
      res = i;
    }
  }
  return res;
}

auto s21::Graph::get_result_vector() -> const_vec_double {
  std::vector<double> res(m_topology_.back());
  for (size_t i = 0; i < res.size(); i++) {
    res[i] = m_neurons_.back()[i].get_value();
  }
  return res;
}

auto s21::Graph::bring_to_zero_all() -> void {
  this->clear_topology();
  this->clear_neurons();
  this->clear_biases();
}

auto s21::Graph::clear_topology() -> void {
  if (!this->m_topology_.empty()) {
    this->m_topology_.clear();
    if (!this->m_topology_.empty()) {
      throw std::bad_alloc();
    }
  }
}

auto s21::Graph::clear_biases() -> void {
  if (!this->m_biases_.empty()) {
    this->m_biases_.clear();
    if (!this->m_biases_.empty()) {
      throw std::bad_alloc();
    }
  }
}

auto s21::Graph::clear_neurons() -> void {
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

auto s21::Graph::change_random_device() -> void {
  std::random_device rd_;
  std::mt19937 temp(rd_());
  this->m_generator_ = temp;
}
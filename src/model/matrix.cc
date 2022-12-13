#include "matrix.h"

auto s21::MatrixNetwork::random_weight() -> double {
    double rand = ((int) this->m_generator_() % 10000) * 0.0001;
    return rand;
}
//
auto s21::MatrixNetwork::feed_init_value(const s21::MatrixNetwork::vector_double &values) -> void {
    for (size_t i = 0; i < values.size(); i++) {
        this->m_neurons_[0][i][0] = values[i];
    }
}
//
auto s21::MatrixNetwork::feed_forward() -> void {
    for (auto i = 0; i < this->m_neurons_.size() - 1; i++) {
        this->m_neurons_[i + 1] = this->m_weights_[i] * this->m_neurons_[i];
        for (auto j = 0; j < this->m_neurons_[i + 1].GetRow(); j++) {
            this->m_neurons_[i + 1](j, 0) = this->activate_function(
                    this->m_neurons_[i + 1](j, 0) + this->m_biases_[i]);
        }
    }
//
//    for (size_t i = 0; i < m_neurons_.size() - 1; i++) {
//        m_neurons_[i + 1] = m_weights_[i] * m_neurons_[i];
//        for (size_t j = 0; j < m_neurons_[i + 1].GetRow(); j++) {
//            m_neurons_[i + 1](j, 0) =
//                    activate_function(m_neurons_[i + 1](j, 0) + m_biases_[i]);
//        }
//    }
}
//
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

auto s21::MatrixNetwork::set_layers(std::initializer_list<size_type> items) -> void {
    this->bring_to_zero_all();
    this->change_random_device();
    for (auto i = 0; i < this->m_topology_.size(); ++i) {
        this->m_neurons_.emplace_back(S21Matrix(this->m_topology_[i], 1));
        this->m_biases_.emplace_back(0);
        if (i != this->m_topology_.size() - 1) {
            this->m_weights_.emplace_back(S21Matrix(this->m_topology_[i + 1], this->m_topology_[i]));
            this->init_weight_matrix(this->m_weights_.back());
        }
    }
}
//
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
//
//
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
        for (auto &m_neuron: this->m_neurons_) {
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

auto s21::MatrixNetwork::get_layers_vector() -> s21::MatrixNetwork::vector_info {
    return this->m_layers_info_;
}

auto s21::MatrixNetwork::set_layers_vector(int number) -> void {
    this->m_layers_info_.emplace_back(s21::LayersInfo::INPUT);
    for (auto i = 0; i < number; i++) {
        this->m_layers_info_.emplace_back(s21::LayersInfo::HIDDEN);
    }
    this->m_layers_info_.emplace_back(s21::LayersInfo::OUTPUT);
}
//
//auto s21::MatrixNetwork::get_local_grads(vector_double &local_grads, const vector_double &expected_values,
//                                         size_type layer) -> void {
//    if (local_grads.empty()) {
//        for (auto i = 0; i < this->m_neurons_.back().GetRow(); i++) {
//            double error_ = expected_values[i] - this->m_neurons_.back()[i][0];
//            local_grads.push_back(error_ * this->activate_function_derivative(this->m_neurons_.back()[i][0]));
//        }
//    } else {
//        vector_double new_grads_;
//        for (auto i = 0; i < this->m_weights_[layer].GetColumn(); i++) {
//            double teta_ = 0.;
//            for (auto j = 0; j < this->m_weights_[layer].GetRow(); j++) {
//                teta_ += local_grads[j] * this->m_weights_[layer][j][i];
//            }
//            new_grads_.push_back(teta_ * activate_function_derivative(this->m_neurons_[layer][i][0]));
//        }
//
//        local_grads = new_grads_;
//    }
//}
//
//auto s21::MatrixNetwork::back_propagation(vector_double &expected_values) -> void {
//    vector_double local_grads_;
//    for (auto i = this->m_weights_.size() - 1; i >= 0; i--) {
//        this->get_local_grads(local_grads_, expected_values, i + 1);
//        for (auto j = 0; j < this->m_weights_[i].GetColumn(); j++) {
//            for (auto k = 0; k < this->m_weights_[i].GetRow(); k++) {
//                this->m_weights_[i][k][j] += s21::MatrixNetwork::step_ * local_grads_[k] * this->m_neurons_[i][j][0];
//            }
//        }
//    }
//}
//
//auto s21::MatrixNetwork::save_weights(std::string file_name) -> void {
//    std::fstream file_;
//    file_.open(file_name, std::fstream::out);
//    if (!file_.is_open()) {
////        throw std::out_of_range("Error with file opening!");
//        std::cout << "Error cant opened file" << std::endl;
//    } else {
//        file_ << "Network weights" << std::endl;
//        for (auto i = 0; i < this->m_topology_.size(); i++) {
//            file_ << m_topology_[i] << ' ';
//        }
//        file_ << '\n';
//        for (auto &m_weight: this->m_weights_) {
//            for (auto i = 0; i < m_weight.GetRow(); i++) {
//                for (auto j = 0; j < m_weight.GetColumn(); j++) {
//                    file_ << m_weight[i][j] << std::endl;
//                }
//            }
//        }
//    }
//    file_.close();
//    file_.open(file_name, std::fstream::in);
//    if (!file_.is_open()) {
//        std::cout << "Where is a file?" << std::endl;
//    } else {
//        std::string check_file_;
//        std::getline(file_, check_file_, '\n');
//        std::cout << check_file_ << std::endl;
//        file_.close();
//    }
//
//}
//
//auto s21::MatrixNetwork::check_topology(const std::vector<size_type> &topology) -> bool {
//    bool result_ = true;
//    if (topology.size() != this->m_topology_.size()) {
//        result_ = false;
//    } else {
//        for (auto i = 0; i < topology.size(); i++) {
//            if (this->m_topology_[i] != topology[i]) {
//                result_ = false;
//            }
//        }
//    }
//    return result_;
//}
//
//auto s21::MatrixNetwork::get_weights(std::string file_name) -> bool {
//    setlocale(LC_NUMERIC, "C");
//    std::fstream file_;
//    file_.open(file_name, std::fstream::in);
//    if (!file_.is_open()) {
//        return false;
//    }
//    std::string check_file_;
//    std::getline(file_, check_file_, '\n');
//    if (check_file_ != "Network weights") {
//        return false;
//    }
//    std::string num_;
//    char c = 0;
//    std::vector<size_type> topology;
//    while (c != '\n' && !file_.eof()) {
//        c = 0;
//        while (c != ' ' && c != '\n' && !file_.eof()) {
//            file_.get(c);
//            if (c != ' ' && c != '\n' && !file_.eof()) {
//                num_ += c;
//            }
//        }
//        if (c != '\n') {
//            topology.push_back(std::stod(num_));
//            num_ = "";
//        }
//    }
//    if (this->check_topology(topology)) {
//        for (size_t layer = 0; layer < this->m_weights_.size(); layer++) {
//            for (size_type i = 0; i < this->m_weights_[layer].GetRow(); i++) {
//                for (size_type j = 0; j < this->m_weights_[layer].GetColumn(); j++) {
//                    std::getline(file_, num_, '\n');
//                    double number = std::stod(num_);
//                    this->m_weights_[layer][i][j] = number;
//                }
//            }
//        }
//    } else {
//        return false;
//    }
//    file_.close();
//    return true;
//}
//
//auto s21::MatrixNetwork::get_result() -> s21::Network::size_type {
//    size_type result_;
//    std::cout << "I am need sig" << std::endl;
//    double max_ = this->m_neurons_.back()[0][0];
//    for (auto i = 0; i < this->m_neurons_.back().GetRow(); i++) {
//        if (max_ < this->m_neurons_.back()[i][0]) {
//            max_ = this->m_neurons_.back()[i][0];
//            result_ = i;
//        }
//    }
//    std::cout << "Where is a sig  " << result_ << std::endl;
//    return result_;
//}
//
//auto s21::MatrixNetwork::get_result_vector() -> s21::MatrixNetwork::const_vec_double {
//    vector_double result_(this->m_topology_.back());
//    for (auto i = 0; i < result_.size(); i++) {
//        result_[i] = this->m_neurons_.back()[i][0];
//    }
//    return result_;
//}
namespace s21 {

    auto Network::GetLayersVector(int number) const
    -> std::vector<LayersInfo> {
        std::vector<LayersInfo> resultVector;
        resultVector.emplace_back(LayersInfo::INPUT);
        for (int i = 0; i < number; ++i) {
            resultVector.emplace_back(LayersInfo::HIDDEN);
        }
        resultVector.emplace_back(LayersInfo::OUTPUT);
        return resultVector;
    }

    auto Network::GetTopology() const -> const std::vector<size_t> & {
        return m_topology_;
    }

//    auto MatrixNetwork::set_layers(std::vector<LayersInfo> info) -> void {
//        m_topology_.clear();
//        for (int i = 0; i < m_neurons_.size(); i++) {
//            m_neurons_[i].clear();
//        }
//        for (int i = 0; i < m_weights_.size(); i++) {
//            m_weights_[i].clear();
//        }
//        m_weights_.clear();
//        m_neurons_.clear();
//        m_biases_.clear();
//        for (size_t i = 0; i < info.size(); ++i) {
//            m_topology_.emplace_back(info[i]);
//        }
//        std::random_device randDevice;
//        std::mt19937 tempGenerator(randDevice());
//        m_generator_ = tempGenerator;
//        for (size_t i = 0; i < info.size(); ++i) {
//            m_neurons_.emplace_back(S21Matrix(info[i], 1));
//            m_biases_.emplace_back(0);
//            if (i != info.size() - 1) {
//                m_weights_.emplace_back(S21Matrix(info[i + 1], info[i]));
//                init_weight_matrix(m_weights_.back());
//            }
//        }
//    }
//
//    auto MatrixNetwork::set_layers(std::initializer_list<size_t> items) -> void {
//        std::vector<size_t> temp_v(items);
//        m_topology_ = temp_v;
//
//        for (int i = 0; i < m_neurons_.size(); i++) {
//            m_neurons_[i].clear();
//        }
//        for (int i = 0; i < m_weights_.size(); i++) {
//            m_weights_[i].clear();
//        }
//        m_weights_.clear();
//        m_neurons_.clear();
//        m_biases_.clear();
//
//        std::random_device randDevice;
//        std::mt19937 tempGenerator(randDevice());
//        m_generator_ = tempGenerator;
//        for (size_t i = 0; i < m_topology_.size(); ++i) {
//            m_neurons_.emplace_back(S21Matrix(m_topology_[i], 1));
//            m_biases_.emplace_back(0);
//            if (i != m_topology_.size() - 1) {
//                m_weights_.emplace_back(S21Matrix(m_topology_[i + 1], m_topology_[i]));
//                init_weight_matrix(m_weights_.back());
//            }
//        }
//    }

//    void MatrixNetwork::init_weight_matrix(S21Matrix &matrix) {
//        for (size_t i = 0; i < matrix.GetRow(); i++) {
//            for (size_t j = 0; j < matrix.GetColumn(); j++) {
//                matrix(i, j) = random_weight();
//            }
//        }
//    }
//    auto MatrixNetwork::random_weight() -> double {
//        double rand = ((int)m_generator_() % 10000) * 0.0001;
//        return rand;
//    }
//
//    auto MatrixNetwork::activate_function(double value) -> double {
//        return 1.0 / (1.0 + exp(-value));
//    }
//
//    auto MatrixNetwork::activate_function_derivative(double value) -> double {
//        return value * (1 - value);
//    }

//    auto MatrixNetwork::feed_init_value(const std::vector<double> &values) -> void {
//        for (size_t i = 0; i < values.size(); i++) {
//            m_neurons_[0][i][0] = values[i];
//        }
//    }
/*--- Проход сигнала от первого слоя до последнего ---*/
//    auto MatrixNetwork::feed_forward() -> void {
//        for (size_t i = 0; i < m_neurons_.size() - 1; i++) {
//            m_neurons_[i + 1] = m_weights_[i] * m_neurons_[i];
//            for (size_t j = 0; j < m_neurons_[i + 1].GetRow(); j++) {
//                m_neurons_[i + 1](j, 0) =
//                        activate_function(m_neurons_[i + 1](j, 0) + m_biases_[i]);
//            }
//        }
//    }

/**
 * @brief Получение локальных градиентов слоя
 * @param LocalGrads текущий вектор локальных градиентов
 * @param ExpectedValues Ожидаемые значения для выходных нейронов
 * @param layer индекс слоя матрицы весов, для которого вычисляются локальные
 * градиенты
 */
    auto MatrixNetwork::get_local_grads(std::vector<double> &LocalGrads,
                                      const std::vector<double> &ExpectedValues,
                                      size_t layer) -> void {
        if (LocalGrads.empty()) {
            // Получаем первые локальные градиенты из разницы полученного значения на
            // выходных нейронах и ожидаемого значения

            for (size_t i = 0; i < m_neurons_.back().GetRow(); i++) {
                double error = ExpectedValues[i] - m_neurons_.back()[i][0];
                LocalGrads.push_back(error *
                                     activate_function_derivative(m_neurons_.back()[i][0]));
            }
        } else {
            // иначе получаем новые градиенты, умножая старые градиенты на веса
            // предыдущего слоя
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

/**
 * @brief Изменение весов пропорциоеально разнице ожидаемых и актуальных
 * значений
 * @param ExpectedValues ожидаемый результат feedForward для входных значений
 */
    auto MatrixNetwork::back_propagation(std::vector<double> &ExpectedValues)
    -> void {
        std::vector<double> localGrads;
        // #pragma omp parallel for
        for (int i = m_weights_.size() - 1; i >= 0; i--) {
            get_local_grads(    localGrads, ExpectedValues, i + 1);

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

    auto MatrixNetwork::check_topology(const std::vector<size_t> &topology) -> bool {
        bool res = true;
        if (topology.size() != m_topology_.size()) {
            res = false;
        } else {
            for (int i = 0; i < topology.size(); i++) {
                if (m_topology_[i] != topology[i]) res = false;
            }
        }
        return res;
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

//    void MatrixNetwork::() {
//        std::cout << "resu/lt matrix:\n";
//        m_neurons.back().show();
//    }

    auto MatrixNetwork::get_result()-> size_t {
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

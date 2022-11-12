#include "matrix.h"

auto s21::MatrixNetwork::random_weight() -> double {
    double rand = ((int)this->m_generator_() % 10000) * 0.0001;
    return rand;
}

auto s21::MatrixNetwork::feed_init_value(const s21::MatrixNetwork::vector_double &values) -> void {
    for (auto i = 0; i < values.size(); i++) {
        this->m_neurons_[0][i][0] = values[i];
    }
    for (auto j : this->m_neurons_) {
        std::cout << j.GetRow() << std::endl;
    }
}

auto s21::MatrixNetwork::feed_forward() -> void {
    for (auto i = 0; i < this->m_neurons_.size() - 1; i++) {
        this->m_neurons_[i + 1] = this->m_weights_[i] * this->m_neurons_[i];
        for (auto j = 0; j < this->m_neurons_[i + 1].GetRow(); j++) {
            this->m_neurons_[i + 1](j, 0) = s21::MatrixNetwork::activate_function(this->m_neurons_[i + 1](j, 0) + this->m_biases_[i]);
        }
    }
}



auto s21::MatrixNetwork::set_layers(std::vector<LayersInfo> info) -> void {
    this->bring_to_zero_all();
    this->change_random_device();
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

auto s21::MatrixNetwork::activate_function(double value) -> double {
    return 1.0 / (1.0 + exp(-value));
}

auto s21::MatrixNetwork::activate_function_derivative(double value) -> double {
    return value * (1 - value);
}

auto s21::MatrixNetwork::init_weight_matrix(S21Matrix &matrix) -> void {
    for (auto i = 0; i < matrix.GetRow(); i++) {
        for (auto j = 0; j < matrix.GetColumn(); j++) {
            matrix(i ,j) = this->random_weight();
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
        if(!this->m_topology_.empty()) {
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
        for (auto & m_neuron : this->m_neurons_) {
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
    std::mt19937  temp(rd_());
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

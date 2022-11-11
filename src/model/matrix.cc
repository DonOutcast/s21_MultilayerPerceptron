#include "matrix.h"

auto s21::MatrixNetwork::random_weight() -> double {
    double rand = ((int)this->m_generator_() % 10000) * 0.0001;
    return rand;
}

auto s21::MatrixNetwork::feed_init_value(const s21::MatrixNetwork::vector_double &values) -> void {
;
}

auto s21::MatrixNetwork::feed_forward() -> void {
;
}

auto s21::MatrixNetwork::set_layers(std::initializer_list<size_type> items) -> void {
;
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
auto s21::MatrixNetwork::activate_function(double value) -> double {
    return 1.0 / (1.0 + exp(-value));
}

auto s21::MatrixNetwork::activate_function_derivative(double value) -> double {
    return value * (1 - value);
}

auto s21::MatrixNetwork::init_weight_matrix(S21Matrix &matrix) -> void {
    for (size_type i = 0; i < matrix.GetRow(); i++) {
        for (size_type j = 0; j < matrix.GetColumn(); j++) {
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
#include "graph_network.h"

auto s21::Graph::generation_weights(size_type number_of_weights_) -> vec_double {
    vec_double weights_(number_of_weights_);
    for (size_type i = 0; i < number_of_weights_; i++) {
        weights_[i] = ((int)this->random_generator_() % 10000) * 0.0001;
    }
    for (auto  j : weights_) {
        std::cout << j  << std::endl;
    }
    return weights_;
}

auto s21::Graph::feed_forward() -> void {
    for (size_type layer_ = 0; layer_ < this->m_neurons_.size() - 1; layer_++) {
        for (size_type i = 0; i < this->m_neurons_[layer_ + 1].size(); i ++) {
            double summary_ = 0;
            for (size_type j = 0; j < m_neurons_[layer_].size(); j++) {
                summary_ += this->m_neurons_[layer_][j].get_weights(i) * this->m_neurons_[layer_][j].get_value();
            }
            m_neurons_[layer_][i].set_value(activate_functions_sigmoid(summary_ + m_biases_[layer_]));
        }
    }
}

auto s21::Graph::activate_functions_sigmoid(double value) -> double {
    return 1.0 / (1.0 + exp(-value));
}
auto s21::Graph::acticate_function_derivative(double value) -> double {
    return value * (1  - value);
}
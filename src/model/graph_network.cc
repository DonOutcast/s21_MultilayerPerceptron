#include "graph_network.h"

auto s21::Graph::generation_weights(size_type number_of_weights_) -> vec_double {
    vec_double weights_(number_of_weights_);
    for (size_type i = 0; i < number_of_weights_; i++) {
        weights_[i] = ((int)this->random_generator_() % 10000) * 0.0001;
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

auto s21::Graph::feed_init_value(const s21::Network::vec_double &values) -> void {
    for (size_type i = 0; i < this->m_neurons_.size(); i++) {
        this->m_neurons_[0][i].set_value(values[i]);
    }
}

auto s21::Graph::bring_to_zero_all() -> void {
    this->clear_topology();
    this->clear_neurons();
    this->clear_biases();
}

auto s21::Graph::clear_topology() -> void {
    if (!this->m_topology_.empty()) {
        this->m_topology_.clear();
        if(!this->m_topology_.empty()) {
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
        for (auto & m_neuron : this->m_neurons_) {
            m_neuron.clear();
        }
        if (!this->m_neurons_.empty()) {
            throw std::bad_alloc();
        }
    }
}


auto s21::Graph::change_random_device() -> void {
    std::random_device rd_;
    std::mt19937  temp(rd_());
    this->random_generator_ = temp;
}

auto s21::Graph::added_neuron_to_m_neurons() -> void {
    for (size_type i = 0; i< m_topology_.size(); i++) {
        this->m_neurons_.push_back(Layer());
        this->m_biases_.push_back(0);
        for (size_type j = 0; j < this->m_topology_[i]; j++) {
            Neuron new_neuron_;
            if (this->m_topology_.size() - 1  != i) {
                new_neuron_.set_weights(this->generation_weights(this->m_topology_[i + 1]));
            }
            this->m_neurons_[i].push_back(new_neuron_);
        }
    }
}

auto s21::Graph::set_layers(std::vector<LayersInfo> info) -> void {
    this->bring_to_zero_all();
    this->change_random_device();
    this->added_neuron_to_m_neurons();


}

auto s21::Graph::set_layers(std::initializer_list<size_type> items) -> void {
    ;
}

auto s21::Graph::back_propagation(s21::Network::vec_double &expected_values) -> void {

}

auto s21::Graph::get_layers_vector() -> s21::Network::vector_info {
    return s21::Network::vector_info();
}

auto s21::Graph::set_layers_vector(int number) -> void {

}

auto s21::Graph::save_weights(std::string) -> void {

}

auto s21::Graph::get_weights(std::string) -> bool {
    return false;
}

auto s21::Graph::get_result() -> s21::Network::size_type {
    return 0;
}

auto s21::Graph::get_result_vector() -> s21::Network::const_vec_double {
    return s21::Network::const_vec_double();
}

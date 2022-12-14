#include "neuron.h"
auto s21::Neuron::set_weights(const vector_double& w) -> void {
  this->m_weights_ = w;
}

auto s21::Neuron::get_weights(size_type index) -> double& {
  return this->m_weights_[index];
}

auto s21::Neuron::set_value(double value) -> void { this->m_value_ = value; }

auto s21::Neuron::get_value() -> double { return this->m_value_; }

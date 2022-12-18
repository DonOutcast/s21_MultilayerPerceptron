#include "facade.h"

#include <utility>

s21::Facade::~Facade() { delete this->m_net_; }

auto s21::Facade::set_net(s21::NetworkType type, int hidden_layers) -> void {
  if (type != this->m_type_ || hidden_layers != this->m_hidden_layers_) {
    if (this->m_net_) {
      delete this->m_net_;
    }
    if (this->m_type_ == s21::NetworkType::MATRIX) {
      this->m_net_ = new s21::MatrixNetwork;
    } else {
      this->m_net_ = new s21::Graph;
    }
    this->m_type_ = type;
    this->m_hidden_layers_ = hidden_layers;
    this->m_net_->set_layers_vector(this->m_hidden_layers_);
    this->m_net_->set_layers(this->m_net_->get_layers_vector());
    //        this->m_net_->set_layers(this->m_net_->GetLayersVector(this->m_hidden_layers_));
  }
}

auto s21::Facade::feed_forward() -> void { this->m_net_->feed_forward(); }
auto s21::Facade::feed_init_values(const vector_double &values) -> void {
  this->m_net_->feed_init_value(values);
}

auto s21::Facade::get_result() -> size_t { return this->m_net_->get_result(); }

auto s21::Facade::load_weights(std::string file_name) -> bool {
  return this->m_net_->get_weights(std::move(file_name));
}

auto s21::Facade::save_weights(std::string file_name) -> void {
  this->m_net_->save_weights(std::move(file_name));
}

auto s21::Facade::train_network(const std::string file_name,
                                const size_t epochs) -> std::vector<double> {
  return this->m_net_->train_network(file_name, epochs);
}

auto s21::Facade::cross_validation(const std::string &file_name, const size_t k)
    -> std::vector<double> {
  return this->m_net_->cross_validation(file_name, k);
}

auto s21::Facade::get_metrics(const std::string &fileName,
                              const double datasetUsage) -> Metrics {
  return m_net_->test_net(fileName, datasetUsage);
}

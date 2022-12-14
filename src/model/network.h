#ifndef SRC_MODEL_NETWORK_H
#define SRC_MODEL_NETWORK_H

#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "../matrix/s21_matrix.h"
#include "data.h"
#include "metric.h"
#include "neuron.h"
#include "reader.h"

namespace s21 {

enum LayersInfo { INPUT = 784, HIDDEN = 140, OUTPUT = 26 };

enum class NetworkType { MATRIX = 0, GRAPH = 1 };

class Network {
 public:
  Network() = default;
  virtual ~Network() = default;

  using size_type = size_t;
  using const_vec_double = const std::vector<double>;
  using vec_double = std::vector<double>;
  using vector_info = std::vector<LayersInfo>;

  virtual auto feed_forward() -> void = 0;
  virtual auto feed_init_value(const vec_double &values) -> void = 0;
  virtual auto back_propagation(vec_double &expected_values) -> void = 0;
  virtual auto save_weights(std::string) -> void = 0;
  virtual auto get_weights(std::string) -> bool = 0;
  virtual auto get_result() -> size_type = 0;
  virtual auto get_result_vector() -> const_vec_double = 0;
  virtual auto set_layers(std::vector<LayersInfo> info) -> void = 0;
  virtual auto set_layers(std::initializer_list<size_type> items) -> void = 0;
  auto get_layers_vector() -> vector_info;
  auto set_layers_vector(int number) -> void;

 public:
  auto test_net(const std::string &fileName, const double DataCoef) -> Metrics;
  auto train_network(const std::string &fileName, const size_t epochs)
      -> std::vector<double>;
  auto cross_validation(const std::string &fileName, const size_t k)
      -> std::vector<double>;

  auto get_topology() const -> const std::vector<size_t> &;
  auto check_topology(const std::vector<size_type> &topology) -> bool;

 protected:
  std::vector<size_type> m_topology_;
  std::mt19937 m_generator_;
  vector_info m_layers_info_;
};

}  // namespace s21

#endif  //  SRC_MODEL_NETWORK_H

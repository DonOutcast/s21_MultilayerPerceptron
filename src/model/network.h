#ifndef SRC_MODEL_NETWORK_H
#define SRC_MODEL_NETWORK_H

#include <cmath>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <iostream>
#include "../matrix/s21_matrix.h"
#include "neuron.h"
#include <chrono>
//#include "network.h"
#include "data.h"
#include "reader.h"

namespace s21 {

    enum LayersInfo {
        INPUT = 784,
        HIDDEN = 140,
        OUTPUT = 26
    };

    enum class NetworkType {
        MATRIX = 0,
        GRAPH = 1
    };

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
//        virtual auto show_result() -> void;
        virtual auto save_weights(std::string) -> void = 0;
        virtual auto get_weights(std::string) -> bool = 0;
        virtual auto get_result() -> size_type = 0;
        virtual auto get_result_vector() -> const_vec_double = 0;
        virtual auto set_layers(std::vector<LayersInfo> info) -> void = 0;
        virtual auto set_layers(std::initializer_list<size_type> items) -> void = 0;
//        auto activate_function(double  value) -> double;
//        auto activate_function_derivative(double value) -> double;
        virtual auto get_layers_vector() -> vector_info = 0;
        virtual auto set_layers_vector(int number) -> void = 0;
    public:
//        auto TestNet(const std::string &fileName, const double DataCoef) -> Metrics;
        auto train_network(const std::string &fileName, const size_t epochs)
        -> std::vector<double>;
        auto cross_validation(const std::string &fileName, const size_t k)
        -> std::vector<double>;

        auto GetLayersVector(int number) const -> std::vector<LayersInfo>;
        auto GetTopology() const -> const std::vector<size_t> &;

    protected:
        std::vector<size_type> m_topology_;
        std::mt19937  m_generator_;
    };



}  // namespace s21



#endif //  SRC_MODEL_NETWORK_H



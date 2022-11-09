#ifndef SRC_MODEL_NETWORK_H
#define SRC_MODEL_NETWORK_H

#include <cmath>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <iostream>

#include "neuron.h"

namespace s21 {

    enum LayersInfo {
        INPUT = 784,
        HIDDEN = 140,
        OUTPUT = 26
    };

    class Network {
    public:
        Network() = default;
        virtual ~Network() = default;
        
        using size_type = size_t;
        using const_vec_double = const std::vector<double>;
        using vec_double = std::vector<double>;

        virtual auto feed_forward() -> void;
//        virtual auto feed_init_values() -> void;
//        virtual auto back_propagation() -> void;
//        virtual auto show_result() -> void;
//        virtual auto save_weights() -> void;
//        virtual auto get_weights() -> bool;
//        virtual auto get_result() -> size_type;
//        virtual auto get_result_vector() -> const_vec_double;
//        virtual auto set_layers(std::vector<LayersInfo> info) -> void;
//        virtual auto set_layers(std::initializer_list<size_type> items) -> void;

    };


}  // namespace s21



#endif //  SRC_MODEL_NETWORK_H



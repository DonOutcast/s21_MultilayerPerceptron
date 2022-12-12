#ifndef SRC_MODEL_NEURON_H
#define SRC_MODEL_NEURON_H

#include "network.h"

namespace s21 {
    class Neuron {
        public:
            Neuron() = default;
            ~Neuron() = default;

            using size_type = size_t;
            using vector_double = std::vector<double>;

            auto set_weights(const vector_double &w) -> void;
            auto get_weights(size_type index) -> double&;
            auto set_value(double value) -> void;
            auto get_value() -> double;
        private:
            vector_double m_weights_;
            double m_value_{};

    };
}  //  namepspace s21

#endif  // SRC_MODEL_NEURON_H

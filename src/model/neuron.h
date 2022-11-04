#ifndef SRC_MODEL_NEURON_H
#define SRC_MODEL_NEURON_H

#include "network.h"

namespace s21 {
    class Neuron : public Network {
        public:
            Neuron() = default;
            ~Neuron() = default;
            auto set_weights(const_vec_double &w) -> void;
            auto get_weights(size_type index) -> double&;
            auto set_value(double value) -> void;
            auto get_value() -> double;
        private:
            vec_double m_weights_;
            auto action() -> void;
            double m_value_{};

    };
}  //  namepspace s21

#endif  // SRC_MODEL_NEURON_H

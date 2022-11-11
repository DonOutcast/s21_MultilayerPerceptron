#ifndef SRC_MODEL_MATRIX_H
#define SRC_MODEL_MATRIX_H
#include "network.h"
namespace s21 {
    class MatrixNetwork : public Network{
    public:
        MatrixNetwork() {;}
        ~MatrixNetwork() override {;}
        using s21_matrix = std::vector<S21Matrix>;
        using vector_double = std::vector<double>;
        using Layer = std::vector<Neuron>;
        using matrix_neuron_ = std::vector<Layer>;

        auto feed_init_value(const vector_double &values) -> void override;
        auto feed_forward() -> void override;
        auto set_layers(std::initializer_list<size_type> items) -> void override;
        auto set_layers(std::vector<LayersInfo> info) -> void override;


    private:

        s21_matrix m_neurons_;
        s21_matrix m_weights_;
        vector_double m_biases_;

        static constexpr double step_ = 0.08;

        auto random_weight() -> double;
        auto change_random_device() -> void;
        auto activate_function(double  value) -> double;
        auto activate_function_derivative(double value) -> double;
        auto init_weight_matrix(S21Matrix &matrix) -> void;

        auto bring_to_zero_all() -> void;
        auto clear_topology() -> void;
        auto clear_neurons() -> void;
        auto clear_biases() -> void;

    };



}

#endif
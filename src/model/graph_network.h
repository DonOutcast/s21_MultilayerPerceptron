#ifndef SRC_MODEL_GRAPH_NETWORK_H
#define SRC_MODEL_GRAPH_NETWORK_H
#include "network.h"
#include "neuron.h"
namespace s21 {
    class Graph : public Network{
    public:
        using Layer = std::vector<Neuron>;
        using matrix_neuron_ = std::vector<Layer>;
        Graph() = default;
        ~Graph() = default;
        auto feed_forward() -> void override;

    private:
        std::mt19937  random_generator_;
        static constexpr double m_step_ = 0.8;
        vec_double  m_biases_;
        matrix_neuron_ m_neurons_;
        auto generation_weights(size_type number_of_weights_) -> vec_double;
        auto activate_functions_sigmoid(double value) -> double;
        auto acticate_function_derivative(double value) -> double;
    };


}


#endif // SRC_MODEL_GRAPH_NETWORK_H
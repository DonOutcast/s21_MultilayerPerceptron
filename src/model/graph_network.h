#ifndef SRC_MODEL_GRAPH_NETWORK_H
#define SRC_MODEL_GRAPH_NETWORK_H
#include "network.h"
#include "neuron.h"
namespace s21 {
    class Graph : public Network{

    public:
        Graph() {;}
        ~Graph() override {;}
        using Layer = std::vector<Neuron>;
        using matrix_neuron_ = std::vector<Layer>;
        auto feed_forward() -> void override;
        auto feed_init_value(const vec_double &values) -> void override;
        auto set_layers(std::vector<LayersInfo> info) -> void override;
        auto set_layers(std::initializer_list<size_type> items) -> void override;
        auto generation_weights(size_type number_of_weights_) -> vec_double;

        auto back_propagation(vec_double &expected_values) -> void override;
        auto get_layers_vector() -> vector_info override;
        auto set_layers_vector(int number) -> void override;
        auto save_weights(std::string) -> void override;
        auto get_weights(std::string) -> bool override;
        auto get_result() -> size_type override;
        auto get_result_vector() -> const_vec_double override;


    private:
        std::mt19937  random_generator_;
        static constexpr double m_step_ = 0.8;
        vec_double  m_biases_;
        matrix_neuron_ m_neurons_;

        static auto activate_functions_sigmoid(double value) -> double;
        static auto acticate_function_derivative(double value) -> double;

        auto change_random_device() -> void;

        auto added_neuron_to_m_neurons() -> void;

        auto bring_to_zero_all() -> void;
        auto clear_topology() -> void;
        auto clear_neurons() -> void;
        auto clear_biases() -> void;
    };


}


#endif // SRC_MODEL_GRAPH_NETWORK_H
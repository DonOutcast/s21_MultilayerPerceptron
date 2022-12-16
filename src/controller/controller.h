#ifndef SRC_CONTROLLER_CONTROLLER_H
#define SRC_CONTROLLER_CONTROLLER_H

#include "../model/network.h"
//#include <QString>
#include "../model/matrix.h"
#include "../model/graph_network.h"

namespace s21 {

    class Controller {
    public:
        Controller() = default;
        ~Controller();

        using vector_double = std::vector<double>;
        using size_type = size_t;

        auto set_net(s21::NetworkType type, int hidden_layers) -> void;
        auto feed_forward() -> void;
        auto feed_init_values(const vector_double & values) -> void;
        auto get_result() -> size_t;
        auto load_weights(std::string file_name) -> bool;
        auto save_weights(std::string file_name) -> void;
        auto train_network(const std::string file_name, const size_t epochs) -> std::vector<double>;
        auto cross_validation(const std::string &file_name, const size_t k) -> std::vector<double>;
        auto get_metrics(const std::string& fileName, const double datasetUsage)
        -> Metrics;
    private:
        Metrics m_metric_{};
        Network* m_net_{};
        NetworkType m_type_{};
        int m_hidden_layers_{};
    };

}

#endif  //  SRC_CONTROLLER_CONTROLLER_H
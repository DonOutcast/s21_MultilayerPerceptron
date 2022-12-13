//
// Created by Lymond Glenda on 12/13/22.
//

#ifndef S21_MULTILAYERPERCEPTRON_METRIC_H
#define S21_MULTILAYERPERCEPTRON_METRIC_H


namespace s21 {
    class Metrics {
        double accuracy;
        double precision;
        double recall;
        double f_measure;
        double ed_time;

    public:
        Metrics() = default;
        ~Metrics() = default;
        auto Calculate(int tp, int fp, int tn, int fn, int data_size) -> void;
    };


}

#endif //S21_MULTILAYERPERCEPTRON_METRIC_H

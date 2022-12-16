//
// Created by Lymond Glenda on 12/13/22.
//

#ifndef S21_MODEL_METRIC_H
#define S21_MODEL_METRIC_H


namespace s21 {
    class Metrics {
    private:
        double accuracy;
        double precision;
        double recall;
        double f_measure;
        double ed_time;

    public:
        Metrics() = default;
        ~Metrics() = default;
        auto Calculate(int tp, int fp, int tn, int fn, int data_size) -> void;

        auto get_accuracy() -> double;
        auto get_precision() -> double;
        auto get_recall() -> double;
        auto get_f_measure() -> double;
        auto get_ed_time() -> double;

        auto set_accuracy(double value) -> void;
        auto set_precision(double value) -> void;
        auto set_recall(double value) -> void;
        auto set_f_measure(double value) -> void;
        auto set_ed_time(double value) -> void;
    };


}

#endif //S21_MODEL_METRIC_H


#include "metric.h"


auto s21::Metrics::Calculate(int tp, int fp, int tn, int fn, int data_size) -> void {
    accuracy = static_cast<double>(accuracy) / data_size;
    precision = static_cast<double>(tp) / static_cast<double>(tp + fp);
    recall = static_cast<double>(tp) / static_cast<double>(tp + fn);
    f_measure = 2 * (precision * recall) / (precision + recall);
}


auto s21::Metrics::get_accuracy() -> double {
    return this->accuracy;
}

auto s21::Metrics::get_precision() -> double {
    return this->precision;
}

auto s21::Metrics::get_recall() -> double {
    return this->recall;
}

auto s21::Metrics::get_f_measure() -> double {
    return this->f_measure;
}

auto s21::Metrics::get_ed_time() -> double {
    return this->ed_time;
}
auto s21::Metrics::set_accuracy(double value) -> void {
    this->accuracy += value;
}

auto s21::Metrics::set_precision(double value) -> void {
    this->precision += value;
}

auto s21::Metrics::set_recall(double value) -> void {
    this->recall += value;
}

auto s21::Metrics::set_f_measure(double value) -> void {
    this->f_measure += value;
}

auto s21::Metrics::set_ed_time(double value) -> void {
    this->ed_time += value;
}

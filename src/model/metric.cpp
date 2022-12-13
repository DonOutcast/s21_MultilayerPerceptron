//
// Created by Lymond Glenda on 12/13/22.
//

#include "metric.h"
auto s21::Metrics::Calculate(int tp, int fp, int tn, int fn, int data_size) -> void {
    accuracy = static_cast<double>(accuracy) / data_size;
    precision = static_cast<double>(tp) / static_cast<double>(tp + fp);
    recall = static_cast<double>(tp) / static_cast<double>(tp + fn);
    f_measure = 2 * (precision * recall) / (precision + recall);
}
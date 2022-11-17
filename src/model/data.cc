#include "data.h"

s21::Data::Data(const std::vector<double> &input, size_t res) {
    this->m_input_ = input;
    this->m_result_ = res;
}
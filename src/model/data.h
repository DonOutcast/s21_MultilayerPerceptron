#ifndef SRC_MODEL_DATA_DATA_H
#define SRC_MODEL_DATA_DATA_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace s21 {
struct Data {
  std::vector<double> m_input_;
  int m_result_;

  Data() = default;
  ~Data() = default;
  Data(const std::vector<double> &input, size_t res);
};

}  // namespace s21
#endif  //  SRC_MODEL_DATA_DATA_H

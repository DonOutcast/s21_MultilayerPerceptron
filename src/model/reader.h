#ifndef SRC_MODEL_READER_H
#define SRC_MODEL_READER_H
#include "data.h"
namespace s21 {
class Reader {
 public:
  using str = std::string;
  using vector_double = std::vector<double>;
  using size_type = size_t;
  auto open_file(str file_name) -> void;
  auto read_line() -> vector_double;
  auto get_file_size() -> size_type;
  auto is_open() -> bool;
  auto close_file() -> void;
  auto get_data() -> Data;
  Reader() = default;
  ~Reader() = default;

 private:
  std::fstream m_file_;
  size_type m_file_size_;
};
}  // namespace s21
#endif
#include "reader.h"

auto s21::Reader::open_file(str file_name) -> void {
  m_file_.close();
  m_file_size_ = 0;
  m_file_.open(file_name);
  if (!m_file_.is_open()) {
    throw std::invalid_argument("Yooooo: File " + file_name + " not found");
  }
  char symbol_;
  while (!this->m_file_.eof()) {
    this->m_file_.get(symbol_);
    if (!this->m_file_.eof() && symbol_ == '\n') {
      this->m_file_size_++;
    }
  }
  m_file_.close();
  m_file_.open(file_name);
}

auto s21::Reader::get_data() -> Data {
  std::vector<double> input_ = this->read_line();
  if (this->is_open()) {
    int result = input_.back();
    input_.pop_back();
    return Data(input_, result);
  } else {
    return Data(input_, 0);
  }
}

auto s21::Reader::read_line() -> vector_double {
  if (!this->m_file_.is_open()) {
    throw std::invalid_argument("File is not opened");
  }
  std::string temp_;
  std::vector<double> out_;
  char symbol = 0;
  double result_ = 0;
  bool first_number = true;
  while (symbol != '\n' && !this->m_file_.eof()) {
    this->m_file_.get(symbol);
    if (symbol != ',' && symbol != '\n' && !this->m_file_.eof()) {
      temp_ += symbol;
    } else if (!this->m_file_.eof()) {
      double res_ = std::stod(temp_);
      if (first_number) {
        result_ = res_;
        first_number = false;
      } else {
        out_.push_back(res_ / 255.0);
      }
      temp_ = "";
    }
  }
  out_.push_back(result_);
  if (this->m_file_.eof()) {
    this->m_file_.close();
  }
  return out_;
}

auto s21::Reader::is_open() -> bool { return this->m_file_.is_open(); }

auto s21::Reader::close_file() -> void { m_file_.close(); }

auto s21::Reader::get_file_size() -> size_type { return this->m_file_size_; }
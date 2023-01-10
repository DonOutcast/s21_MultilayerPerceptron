#include "s21_matrix.h"

void S21Matrix::FillRandom(double fMin, double fMax) {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _columns; j++) {
      this->_matrix[i][j] = fMin + (double)rand() / RAND_MAX * (fMax - fMin);
    }
  }
}

void S21Matrix::show() {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _columns; j++) {
      std::cout << this->_matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "rows " << _rows << " col " << _columns << "\n";
}

bool S21Matrix::IsNormalMatrix() {
  bool res = false;
  if (_rows > 0 && _columns > 0 && this->_matrix != nullptr) res = true;
  return res;
}

bool S21Matrix::IsNull() {
  bool res = false;
  void* ptr = static_cast<void*>(this->_matrix);
  if (ptr == nullptr) {
    res = true;
  }
  return res;
}

double* S21Matrix::operator[](int i) {
  double* out;
  if (i >= _rows) {
    out = nullptr;
    throw std::out_of_range("[]: index is out of range");
  }
  out = _matrix[i];
  return out;
}

void S21Matrix::clear() {
  if (_matrix != nullptr) {
    for (int i = 0; i < _rows; i++) {
      delete _matrix[i];
    }
    delete _matrix;
  }
  _matrix = nullptr;
  _rows = 0;
  _columns = 0;
}

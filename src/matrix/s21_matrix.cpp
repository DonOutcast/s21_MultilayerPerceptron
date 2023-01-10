#include "s21_matrix.h"

// заполняет матрицу нулями
void S21Matrix::allocate_mem(int rows, int columns) {
  _matrix = new double*[rows];
  for (int i = 0; i < rows; i++) {
    _matrix[i] = new double[columns];
  }
}

void S21Matrix::SetZeros() {
  if (this->IsNormalMatrix()) {
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _columns; j++) {
        _matrix[i][j] = 0;
      }
    }
  }
}

S21Matrix::S21Matrix() {
  _rows = 0;
  _columns = 0;
  _matrix = nullptr;
}
// конструктор матрицы по рядам и столбцам
S21Matrix::S21Matrix(int rows, int columns) {
  if (rows <= 0 || columns <= 0) {
    throw std::invalid_argument(
        "S21Matrix construct: cannot initiaize a _matrix with negative number "
        "of rows or columns");
  } else {
    _rows = rows;
    _columns = columns;
    this->allocate_mem(rows, columns);
    this->SetZeros();
  }
}

// конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other) {
  if (this != &other) {
    _rows = other._rows;
    _columns = other._columns;
    this->allocate_mem(other._rows, other._columns);
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _columns; j++) {
        _matrix[i][j] = other._matrix[i][j];
      }
    }
  }
}

// конструктор перемещения
S21Matrix::S21Matrix(S21Matrix&& other) {
  if (this != &other) {
    _rows = other._rows;
    _columns = other._columns;
    _matrix = other._matrix;
    other._matrix = nullptr;
    other._rows = 0;
    other._columns = 0;
  }
}

// деструктор
S21Matrix::~S21Matrix() {
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

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    this->~S21Matrix();
    _rows = other._rows;
    _columns = other._columns;
    allocate_mem(_rows, _columns);
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _columns; j++) {
        _matrix[i][j] = other._matrix[i][j];
      }
    }
  }
  return *this;
}

// getters && setters

double& S21Matrix::operator()(int i, int j) {
  if (i >= _rows || j >= _columns) {
    throw std::out_of_range("(): index is out of range");
  } else {
    return _matrix[i][j];
  }
}

// accessors
int S21Matrix::GetRow() { return _rows; }

int S21Matrix::GetColumn() { return _columns; }

// mutators
void S21Matrix::EditRow(int value) {
  if (value > 0) {
    this->~S21Matrix();
    _rows = value;
    this->allocate_mem(_rows, _columns);
    this->SetZeros();
  } else {
    throw std::invalid_argument("EditRow: row value less or equal to zero");
  }
}

void S21Matrix::EditColumn(int value) {
  if (value > 0) {
    this->~S21Matrix();
    _columns = value;
    this->allocate_mem(_rows, _columns);
    this->SetZeros();
  } else {
    throw std::invalid_argument(
        "EditColumn: column value less or equal to zero");
  }
}

// operators

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res = *this;
  res.sum_matrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res = *this;
  res.sub_matrix(other);
  return res;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->sub_matrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->sum_matrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res = *this;
  res.mul_matrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const double number) {
  S21Matrix res = *this;
  res.mul_number(number);
  return res;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->mul_matrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double number) {
  this->mul_number(number);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  bool res = this->eq_matrix(other);
  return res;
}

/**
 * @brief Записывает в this минор матрицы , через "вырезание" i-ой строки и j-го
 * столбца
 *
 * @param src исходник матрицы минора
 * @param rows номер индекс строки
 * @param column номер индекса столбца
 */
void S21Matrix::GetMinor(const S21Matrix src, int row, int column) {
  if (_rows + 1 == src._rows && _columns + 1 == src._columns) {
    for (int i = 0, flag_i = 0; i < src._rows; i++) {
      if (i == row) {
        flag_i = 1;
      } else {
        for (int j = 0, flag_d = 0; j < src._columns; j++) {
          if (j == column) {
            flag_d = 1;
          } else {
            _matrix[i - flag_i][j - flag_d] = src._matrix[i][j];
          }
        }
      }
    }
  } else {
    throw std::invalid_argument("GetMinor: Incorrect size of _matrix");
  }
}

double S21Matrix::determinant() {
  double D = 0;
  if (_columns == _rows) {
    if (_rows == 1) return _matrix[0][0];
    S21Matrix temp(_rows - 1, _columns - 1);
    for (int i = 0; i < _rows; i++) {
      temp.GetMinor(*this, 0, i);
      int one = 1;
      if (i % 2 == 1) one = -1;
      D += _matrix[0][i] * temp.determinant() * one;
    }
  } else {
    throw std::invalid_argument("determinant: matrix isn't sqare");
  }

  return D;
}

S21Matrix S21Matrix::transpose() {
  S21Matrix res(_columns, _rows);
  for (int i = 0; i < _columns; i++) {
    for (int j = 0; j < _rows; j++) {
      res._matrix[i][j] = _matrix[j][i];
    }
  }
  return res;
}

// вычисляет матрицу алгебраических дополнений
S21Matrix S21Matrix::calc_complements() {
  S21Matrix res(_rows, _columns);
  if (res._rows == res._columns) {
    S21Matrix calc(_rows - 1, _columns - 1);
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _columns; j++) {
        calc.GetMinor(*this, i, j);
        res._matrix[i][j] = calc.determinant();
        if ((i + j) % 2 == 1) res._matrix[i][j] *= -1;
      }
    }
  } else {
    throw std::invalid_argument("calc_complements: _matrix isn't sqare");
  }
  return res;
}

void S21Matrix::sub_matrix(const S21Matrix& other) {
  if (_matrix == nullptr || other._matrix == nullptr)
    throw std::invalid_argument("sub: _matrix is not exist");
  if (_rows == other._rows && _columns == other._columns) {
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _columns; j++) {
        _matrix[i][j] -= other._matrix[i][j];
      }
    }
  } else {
    throw std::invalid_argument("sub: m1 and m2 have different sizes");
  }
}

void S21Matrix::sum_matrix(const S21Matrix& other) {
  if (_matrix == nullptr || other._matrix == nullptr)
    throw std::invalid_argument("sum: _matrix is not exist");
  if (_rows == other._rows && _columns == other._columns) {
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _columns; j++) {
        _matrix[i][j] += other._matrix[i][j];
      }
    }
  } else {
    throw std::invalid_argument("sum: m1 and m2 have different sizes");
  }
}

bool S21Matrix::eq_matrix(const S21Matrix& other) {
  bool res = true;
  if (_rows == other._rows && _columns == other._columns) {
    for (int i = 0; i < _rows && res; i++) {
      for (int j = 0; j < _columns && res; j++) {
        if (fabs(_matrix[i][j] - other._matrix[i][j]) > 0.000001) res = false;
      }
    }
  } else {
    res = false;
  }
  return res;
}

void S21Matrix::mul_number(const double number) {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _columns; j++) {
      _matrix[i][j] = _matrix[i][j] * number;
    }
  }
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
  if (_columns != other._rows) {
    throw std::invalid_argument("Rows from 1st M != cols from 2nd M");
  }
  S21Matrix A(_rows, other._columns);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < other._columns; j++) {
      for (int k = 0; k < _columns; k++) {
        A._matrix[i][j] += _matrix[i][k] * other._matrix[k][j];
      }
    }
  }
  this->~S21Matrix();
  _matrix = new double*[A._rows];
  for (int i = 0; i < A._rows; i++) {
    _matrix[i] = new double[_columns];
  }
  *this = A;
}

S21Matrix S21Matrix::inverse_matrix() {
  S21Matrix res(_rows, _columns);
  if (_rows == _columns && this->IsNormalMatrix()) {
    double D = this->determinant();
    if (D != 0) {
      if (_rows == 1) {
        res[0][0] = 1.0 / D;
      } else {
        res = this->calc_complements();
        res = res.transpose();
        res *= (1 / D);
      }
    } else {
      throw std::invalid_argument("inverse: matrix determinant is equal to 0");
    }
  } else {
    throw std::invalid_argument("inverse: matrix isn't sqare");
  }
  return res;
}

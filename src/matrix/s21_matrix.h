#include <cmath>
#include <exception>
#include <iostream>
#include <string>

class S21Matrix {
 private:
  int _rows = 0;
  int _columns = 0;
  double** _matrix = nullptr;
  void SetZeros();

 public:
  // constructors
  S21Matrix();
  S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix& other);
  // move constructor
  S21Matrix(S21Matrix&& other);

  // destructors
  ~S21Matrix();

  // accessors
  int GetRow();
  int GetColumn();
  // mutators
  void EditRow(int value);
  void EditColumn(int value);

  // get matrix element
  double* operator[](int i);
  double& operator()(int i, int j);
  bool IsNull();

  // ariphmetic
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double number);
  double determinant();
  S21Matrix transpose();
  S21Matrix calc_complements();
  void sub_matrix(const S21Matrix& other);
  void sum_matrix(const S21Matrix& other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix& other);
  S21Matrix inverse_matrix();

  // equating
  S21Matrix& operator=(const S21Matrix& other);

  // equating && ariphmetic
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double number);

  // comparing
  bool operator==(const S21Matrix& other);
  bool eq_matrix(const S21Matrix& other);

  // auxiliary

  void GetMinor(S21Matrix src, int rows, int column);
  void FillRandom(double fMin, double fMax);
  void show();
  void clear();

 private:
  void allocate_mem(int rows, int columns);
  bool IsNormalMatrix();
};

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <stdexcept>
#include <vector>

namespace s21 {
template <typename T>
class Matrix {
 public:
  Matrix() : rows_(0), cols_(0), data_() {}

  Matrix(size_t rows, size_t cols)
      : rows_(rows), cols_(cols), data_(rows * cols) {
    if (rows == 0 || cols == 0) {
      throw std::invalid_argument(
          "Matrix dimensions must be greater than zero.");
    }
  }

  ~Matrix() = default;
  Matrix(const Matrix &other)
      : rows_(other.rows_), cols_(other.cols_), data_(other.data_) {}

  Matrix &operator=(const Matrix &other) {
    if (this != &other) {
      rows_ = other.rows_;
      cols_ = other.cols_;
      data_ = other.data_;
    }
    return *this;
  }

  Matrix(Matrix &&other) noexcept
      : rows_(other.rows_), cols_(other.cols_), data_(std::move(other.data_)) {
    other.rows_ = 0;
    other.cols_ = 0;
  }

  Matrix &operator=(Matrix &&other) noexcept {
    if (this != &other) {
      rows_ = other.rows_;
      cols_ = other.cols_;
      data_ = std::move(other.data_);
      other.rows_ = 0;
      other.cols_ = 0;
    }
    return *this;
  }

  T &operator()(size_t row, size_t col) {
    if (row >= rows_ || col >= cols_) {
      throw std::out_of_range("Matrix subscript out of range.");
    }
    return data_[row * cols_ + col];
  }

  const T &operator()(size_t row, size_t col) const {
    if (row >= rows_ || col >= cols_) {
      throw std::out_of_range("Matrix subscript out of range.");
    }
    return data_[row * cols_ + col];
  }

  size_t getRows() const { return rows_; }
  size_t getCols() const { return cols_; }

 private:
  size_t rows_;
  size_t cols_;
  std::vector<T> data_;
};

template <>
class Matrix<bool> {
 public:
  Matrix() : rows_(0), cols_(0), data_() {}

  Matrix(size_t rows, size_t cols)
      : rows_(rows), cols_(cols), data_(rows * cols) {
    if (rows == 0 || cols == 0) {
      throw std::invalid_argument(
          "Matrix dimensions must be greater than zero.");
    }
  }

  ~Matrix() = default;
  Matrix(const Matrix &other)
      : rows_(other.rows_), cols_(other.cols_), data_(other.data_) {}

  Matrix &operator=(const Matrix &other) {
    if (this != &other) {
      rows_ = other.rows_;
      cols_ = other.cols_;
      data_ = other.data_;
    }
    return *this;
  }

  Matrix(Matrix &&other) noexcept
      : rows_(other.rows_), cols_(other.cols_), data_(std::move(other.data_)) {
    other.rows_ = 0;
    other.cols_ = 0;
  }

  Matrix &operator=(Matrix &&other) noexcept {
    if (this != &other) {
      rows_ = other.rows_;
      cols_ = other.cols_;
      data_ = std::move(other.data_);
      other.rows_ = 0;
      other.cols_ = 0;
    }
    return *this;
  }

  std::vector<bool>::reference operator()(size_t row, size_t col) {
    if (row >= rows_ || col >= cols_) {
      throw std::out_of_range("Matrix subscript out of range.");
    }
    return data_[row * cols_ + col];
  }

  bool operator()(size_t row, size_t col) const {
    if (row >= rows_ || col >= cols_) {
      throw std::out_of_range("Matrix subscript out of range.");
    }
    return data_[row * cols_ + col];
  }

  size_t getRows() const { return rows_; }
  size_t getCols() const { return cols_; }

 private:
  size_t rows_;
  size_t cols_;
  std::vector<bool> data_;
};

}  // namespace s21

#endif
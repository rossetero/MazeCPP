#include "../inc/cave_generator.h"

namespace s21 {

void CaveGenerator::initCaveMatrix(size_t rows, size_t cols) {
  std::srand(time(nullptr));
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      int r = rand() % 99 + 1;
      caveMatrix_(i, j) = (r <= initChance_) ? 1 : 0;
    }
  }
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)
        caveMatrix_(i, j) = 1;
    }
  }
}

int CaveGenerator::countLiveNeighbours(size_t y, size_t x) {
  int cnt = 0;
  for (size_t i = y - 1; i <= y + 1; ++i) {
    for (size_t j = x - 1; j <= x + 1; ++j) {
      if (caveMatrix_(i, j) == 1) ++cnt;
    }
  }
  return cnt;
}

void CaveGenerator::genNext() {
  Matrix<bool> tmp = caveMatrix_;
  for (size_t i = 1; i < caveMatrix_.getRows() - 1; ++i) {
    for (size_t j = 1; j < caveMatrix_.getCols() - 1; ++j) {
      unsigned int c = countLiveNeighbours(i, j);
      if (c < deathLimit_ && caveMatrix_(i, j) == 1) {
        tmp(i, j) = 0;
      }
      if (c > birthLimit_ && caveMatrix_(i, j) == 0) {
        tmp(i, j) = 1;
      }
    }
  }
  caveMatrix_ = tmp;
}

}  // namespace s21

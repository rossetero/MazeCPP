#include "../inc/maze_console_printer.h"

namespace s21 {

void MazeConsolePrinter::print(size_t x, size_t y) {
  printWallsLayout(x, y, m_.getHorizontalWallMatrix(),
                   m_.getVerticalWallMatrix());
}

void MazeConsolePrinter::printWallsLayout(size_t y, size_t x,
                                          const Matrix<bool> &hWMatrix,
                                          const Matrix<bool> &vWMatrix) {
  std::vector<std::vector<char>> output(
      hWMatrix.getRows() * 3 + 1,
      std::vector<char>(hWMatrix.getCols() * 3 + 1, ' '));

  for (size_t i = 0; i < hWMatrix.getRows(); i++) {
    for (size_t j = 0; j < hWMatrix.getCols(); j++) {
      output[i * 3 + 1 + y][x] = '|';
      output[i * 3 + 2 + y][x] = '|';
      if (hWMatrix(i, j)) {
        size_t x0{j * 3 + 1}, y0{(i + 1) * 3};
        output[y + y0][x + x0] = '-';
        output[y + y0][x + x0 + 1] = '-';
      }

      if (vWMatrix(i, j)) {
        size_t x0{(j + 1) * 3}, y0{i * 3 + 1};
        output[y + y0][x + x0] = '|';
        output[y + y0 + 1][x + x0] = '|';
      }
    }
  }

  for (size_t j = 0; j < hWMatrix.getCols(); j++) {
    output[y][x + j * 3 + 1] = '-';
    output[y][x + j * 3 + 2] = '-';
  }

  for (const auto &row : output) {
    for (char ch : row) {
      std::cout << ch;
    }
    std::cout << '\n';
  }
}
}  // namespace s21

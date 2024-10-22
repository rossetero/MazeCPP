#ifndef CONSOLE_MAZE_PRINTER
#define CONSOLE_MAZE_PRINTER

#include <iostream>
#include <vector>

#include "../../model/inc/maze.h"

namespace s21 {
class MazeConsolePrinter {
 public:
  MazeConsolePrinter(const Maze &m) : m_(m){};

  void print(size_t y, size_t x);

 private:
  const Maze &m_;

  void printWallsLayout(size_t y, size_t x, const Matrix<bool> &hWMatrix,
                        const Matrix<bool> &vWMatrix);
};
}  // namespace s21

#endif
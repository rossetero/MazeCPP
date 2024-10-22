#ifndef _MAZE_H_
#define _MAZE_H_

#include <exception>
#include <list>
#include <utility>

#include "matrix.h"

namespace s21 {

class Maze {
 public:
  Maze() : vWallMatrix_(), hWallMatrix_(){};
  Maze(Matrix<bool> &&vWallMatrix, Matrix<bool> &&hWallMatrix)
      : vWallMatrix_(std::move(vWallMatrix)),
        hWallMatrix_(std::move(hWallMatrix)) {
    if (vWallMatrix_.getRows() != hWallMatrix_.getRows() ||
        vWallMatrix_.getCols() != hWallMatrix_.getCols()) {
      throw std::runtime_error("different dimensions of matrices");
    }
  }

  Maze(const Maze &other) = default;
  Maze(Maze &&other) = default;
  ~Maze() = default;

  Maze &operator=(Maze &&other) = default;
  Maze &operator=(Maze &other) = default;

  size_t getRows() const { return vWallMatrix_.getRows(); };
  size_t getCols() const { return vWallMatrix_.getCols(); };

  const Matrix<bool> &getVerticalWallMatrix() const { return vWallMatrix_; };
  const Matrix<bool> &getHorizontalWallMatrix() const { return hWallMatrix_; };

 private:
  Matrix<bool> vWallMatrix_;
  Matrix<bool> hWallMatrix_;
};

class IMazeGenerator {
 public:
  virtual Maze generateMaze() = 0;
};

class IMazeSolver {
 public:
  virtual std::list<std::pair<int, int>> solve() const = 0;
};

class IMazeSaver {
 public:
  virtual void save() const = 0;
};

class IMazeParser {
 public:
  virtual Maze parse() = 0;
};

}  // namespace s21

#endif
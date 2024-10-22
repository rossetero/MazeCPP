#ifndef _ELLER_GENERATOR_H_
#define _ELLER_GENERATOR_H_

#include <fstream>
#include <map>
#include <random>
#include <string>

#include "matrix.h"
#include "maze.h"

namespace s21 {
class EllerGenerator : public IMazeGenerator {
 public:
  EllerGenerator(size_t rows, size_t cols)
      : vWallsMatrix_g(Matrix<bool>(rows, cols)),
        hWallsMatrix_g(Matrix<bool>(rows, cols)),
        setsMatrix_g(Matrix<int>(rows, cols)),
        uniqueIncr(1) {}

  Maze generateMaze() override;

 private:
  Matrix<bool> vWallsMatrix_g;
  Matrix<bool> hWallsMatrix_g;
  Matrix<int> setsMatrix_g;
  unsigned int uniqueIncr;

  void generateRow(int);
  void putVerticalWallsInRow(int);
  void putHorizontalWallsInRow(int);
  void unite(size_t, int, int);
  std::map<int, int> findSetsLengths(size_t currentRow);
  void processLastRow();
};

}  // namespace s21
#endif

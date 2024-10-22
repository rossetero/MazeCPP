#ifndef _MODEL_H_
#define _MODEL_H_

#include "eller_generator.h"
#include "maze_file_parser.h"
#include "maze_wave_solver.h"

namespace s21 {

class Model {
 public:
  void generateMaze(size_t rows, size_t cols);
  const std::list<std::pair<int, int>> solveMaze(std::pair<int, int> start,
                                                 std::pair<int, int> end);
  void openFile(const std::string &path);
  const Maze &getMaze();

 private:
  Maze maze_;
};

}  // namespace s21

#endif

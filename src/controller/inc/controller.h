#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <memory>
#include <utility>

#include "../../model/inc/model.h"

namespace s21 {

class Controller {
 public:
  Controller() : model_(std::make_unique<Model>()) {}

  const std::list<std::pair<int, int>> solveMaze(std::pair<int, int> start,
                                                 std::pair<int, int> end) {
    return model_->solveMaze(start, end);
  };

  void generateMaze(size_t rows, size_t cols) {
    model_->generateMaze(rows, cols);
  };
  const Maze &getMaze() const { return model_->getMaze(); };

  void LoadMazeFromFile(const std::string &path) { model_->openFile(path); };

 private:
  std::unique_ptr<Model> model_;
};

}  // namespace s21

#endif

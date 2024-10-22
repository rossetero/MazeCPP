#include "../inc/model.h"

namespace s21 {

void Model::generateMaze(size_t rows, size_t cols) {
  maze_ = EllerGenerator(rows, cols).generateMaze();
}

const std::list<std::pair<int, int>> Model::solveMaze(std::pair<int, int> start,
                                                      std::pair<int, int> end) {
  return MazeWaveSolver(maze_, start, end).solve();
}

void Model::openFile(const std::string &path) {
    maze_ = MazeFileParser(path).parse();
}

const Maze &Model::getMaze() {
    return maze_;
}
}  // namespace s21

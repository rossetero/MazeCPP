#ifndef _MAZE_PARSER_H_
#define _MAZE_PARSER_H_

#include <exception>
#include <fstream>
#include <string>

#include "maze.h"

namespace s21 {

class MazeFileParser : public IMazeParser {
 public:
  MazeFileParser(const std::string &filePath) : filePath_(filePath){};

  virtual Maze parse() override;

 protected:
  size_t readSize(std::ifstream &file);
  size_t readBool(std::ifstream &file);
  Matrix<bool> readMatrix(std::ifstream &stream, size_t rows, size_t cols);

 private:
  const std::string &filePath_;
};

}  // namespace s21

#endif
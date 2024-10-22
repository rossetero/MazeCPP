#include "../inc/maze_file_parser.h"

namespace s21 {

Maze MazeFileParser::parse() {
  std::ifstream file(filePath_);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file!");
  }

  try {
    size_t rows = readSize(file);
    size_t cols = readSize(file);

    Matrix<bool> vWallMatrix = readMatrix(file, rows, cols);
    Matrix<bool> hWallMatrix = readMatrix(file, rows, cols);

    return Maze(std::move(vWallMatrix), std::move(hWallMatrix));
  } catch (...) {
    throw std::runtime_error("Invalid file type.");
  }
}

size_t MazeFileParser::readSize(std::ifstream& file) {
  size_t size;
  if (!(file >> size)) {
    throw std::runtime_error("Failed to read size from file.");
  }
  return size;
}

size_t MazeFileParser::readBool(std::ifstream& file) {
  bool expr;
  if (!(file >> expr)) {
    throw std::runtime_error("Failed to read bool from file.");
  }
  return expr;
}

Matrix<bool> MazeFileParser::readMatrix(std::ifstream& stream, size_t rows,
                                        size_t cols) {
  Matrix<bool> M(rows, cols);

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      M(i, j) = readBool(stream);
    }
  }

  return M;
}

}  // namespace s21

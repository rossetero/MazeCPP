#include "../inc/maze_file_saver.h"

namespace s21 {

void MazeFileSaver::save() const {
  std::ofstream file(path_);
  if (!file) {
    throw std::runtime_error("Failed to open file");
  }

  size_t h = maze_.getRows();
  size_t w = maze_.getCols();
  const Matrix<bool>& vWallsMatrix = maze_.getVerticalWallMatrix();
  const Matrix<bool>& hWallsMatrix = maze_.getHorizontalWallMatrix();

  file << h << " " << w << std::endl;

  auto writeMatrixToFile = [&file, h, w](const Matrix<bool>& matrix) {
    for (size_t i = 0; i < h; ++i) {
      for (size_t j = 0; j < w; ++j) {
        file << matrix(i, j) << " ";
      }
      file << std::endl;
    }
    file << std::endl;
  };

  writeMatrixToFile(vWallsMatrix);
  writeMatrixToFile(hWallsMatrix);

  file.close();
}
}  // namespace s21
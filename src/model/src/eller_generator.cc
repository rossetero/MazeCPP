#include "../inc/eller_generator.h"

namespace s21 {
Maze EllerGenerator::generateMaze() {
  size_t mazeHeight = setsMatrix_g.getRows();
  srand(time(0));
  for (size_t i = 0; i < mazeHeight; ++i) {
    generateRow(i);
    putVerticalWallsInRow(i);
    putHorizontalWallsInRow(i);
  }
  processLastRow();
  return Maze(std::move(vWallsMatrix_g), std::move(hWallsMatrix_g));
}

void EllerGenerator::generateRow(int rowNum) {
  if (rowNum == 0) {
    for (size_t j = 0; j < setsMatrix_g.getCols(); ++j) {
      setsMatrix_g(rowNum, j) = uniqueIncr;
      ++uniqueIncr;
    }
  } else {
    for (size_t j = 0; j < setsMatrix_g.getCols(); ++j) {
      if (hWallsMatrix_g(rowNum - 1, j) == 1) {
        setsMatrix_g(rowNum, j) = uniqueIncr;
        ++uniqueIncr;
      } else {
        setsMatrix_g(rowNum, j) = setsMatrix_g(rowNum - 1, j);
      }
    }
  }
}

void EllerGenerator::unite(size_t currentRow, int setNumber,
                           int setForMergeNumber) {
  for (size_t j = 0; j < setsMatrix_g.getCols(); ++j) {
    if (setsMatrix_g(currentRow, j) == setForMergeNumber) {
      setsMatrix_g(currentRow, j) = setNumber;
    }
  }
}

void EllerGenerator::putVerticalWallsInRow(int rowNum) {
  for (size_t j = 0; j < setsMatrix_g.getCols() - 1; ++j) {
    bool coin = std::rand() % 2;
    if (coin || setsMatrix_g(rowNum, j) == setsMatrix_g(rowNum, j + 1)) {
      vWallsMatrix_g(rowNum, j) = 1;
    } else {
      unite(rowNum, setsMatrix_g(rowNum, j), setsMatrix_g(rowNum, j + 1));
    }
  }
  vWallsMatrix_g(rowNum, vWallsMatrix_g.getCols() - 1) = 1;
}

std::map<int, int> EllerGenerator::findSetsLengths(size_t currentRow) {
  std::map<int, int> lengths;
  for (size_t j = 0; j < setsMatrix_g.getCols(); ++j) {
    if (lengths.count(setsMatrix_g(currentRow, j)) == 0) {
      lengths[setsMatrix_g(currentRow, j)] = 1;
    } else {
      ++lengths[setsMatrix_g(currentRow, j)];
    }
  }
  return lengths;
}

void EllerGenerator::putHorizontalWallsInRow(int rowNum) {
  std::map<int, int> setLengths = findSetsLengths(rowNum);
  for (size_t j = 0; j < setsMatrix_g.getCols(); ++j) {
    bool coin = std::rand() % 2;
    if (coin && setLengths[setsMatrix_g(rowNum, j)] > 1) {
      --setLengths[setsMatrix_g(rowNum, j)];
      hWallsMatrix_g(rowNum, j) = 1;
    }
  }
}

void EllerGenerator::processLastRow() {
  for (size_t j = 0; j < setsMatrix_g.getCols() - 1; ++j) {
    hWallsMatrix_g(hWallsMatrix_g.getRows() - 1, j) = 1;
    if (setsMatrix_g(setsMatrix_g.getRows() - 1, j) !=
        setsMatrix_g(setsMatrix_g.getRows() - 1, j + 1)) {
      vWallsMatrix_g(vWallsMatrix_g.getRows() - 1, j) = 0;
    }
  }
  hWallsMatrix_g(hWallsMatrix_g.getRows() - 1, hWallsMatrix_g.getCols() - 1) =
      1;
}

}  // namespace s21

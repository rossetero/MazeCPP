#ifndef _CAVE_GENERATOR_H_
#define _CAVE_GENERATOR_H_
#include "matrix.h"

namespace s21 {

class CaveGenerator {
 private:
  unsigned int birthLimit_;
  unsigned int deathLimit_;
  int initChance_;  // percents
  Matrix<bool> caveMatrix_;
  void initCaveMatrix(size_t, size_t);

  int countLiveNeighbours(size_t, size_t);

 public:
  CaveGenerator(size_t rows, size_t cols, unsigned int birthLimit,
                unsigned int deathLimit, int initChance)
      : birthLimit_(birthLimit),
        deathLimit_(deathLimit),
        initChance_(initChance),
        caveMatrix_(Matrix<bool>(rows + 2, cols + 2)) {
    initCaveMatrix(rows + 2, cols + 2);
  }
  void genNext();
  Matrix<bool> getCaveMatrix() { return caveMatrix_; }
};

}  // namespace s21

#endif

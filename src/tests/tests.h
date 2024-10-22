#ifndef _A1_MAZE_TESTS_H_
#define _A1_MAZE_TESTS_H_

#include <gtest/gtest.h>

#include "../model/inc/eller_generator.h"
#include "../model/inc/maze_file_parser.h"
#include "../model/inc/maze_wave_solver.h"

namespace S21Tests {
using namespace s21;

class MazeTest : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

}  // namespace S21Tests

#endif
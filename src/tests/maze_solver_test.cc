#include "tests.h"

namespace S21Tests {

TEST_F(MazeTest, MazeSolver_1) {
  static const std::list<std::pair<int, int>> expectedSolution = {
      {0, 0},   {0, 1},   {0, 2},   {0, 3},   {1, 3},   {1, 2},   {2, 2},
      {3, 2},   {3, 3},   {4, 3},   {4, 4},   {4, 5},   {4, 6},   {5, 6},
      {5, 5},   {5, 4},   {6, 4},   {6, 5},   {6, 6},   {6, 7},   {7, 7},
      {7, 8},   {8, 8},   {8, 9},   {9, 9},   {10, 9},  {10, 10}, {10, 11},
      {10, 12}, {9, 12},  {8, 12},  {8, 13},  {8, 14},  {8, 15},  {7, 15},
      {6, 15},  {6, 16},  {6, 17},  {6, 18},  {6, 19},  {7, 19},  {7, 20},
      {7, 21},  {7, 22},  {7, 23},  {6, 23},  {6, 24},  {6, 25},  {7, 25},
      {8, 25},  {8, 26},  {8, 27},  {9, 27},  {9, 28},  {9, 29},  {8, 29},
      {8, 30},  {8, 31},  {8, 32},  {8, 33},  {7, 33},  {6, 33},  {5, 33},
      {4, 33},  {3, 33},  {2, 33},  {1, 33},  {0, 33},  {0, 34},  {0, 35},
      {0, 36},  {0, 37},  {1, 37},  {1, 36},  {2, 36},  {3, 36},  {3, 37},
      {3, 38},  {3, 39},  {2, 39},  {2, 40},  {2, 41},  {2, 42},  {2, 43},
      {3, 43},  {4, 43},  {5, 43},  {5, 42},  {6, 42},  {6, 43},  {6, 44},
      {7, 44},  {8, 44},  {8, 43},  {9, 43},  {9, 44},  {10, 44}, {10, 45},
      {10, 46}, {10, 47}, {10, 48}, {10, 49}, {11, 49}, {12, 49}, {13, 49},
      {13, 48}, {14, 48}, {14, 49}, {15, 49}, {16, 49}, {17, 49}, {17, 48},
      {18, 48}, {18, 49}, {19, 49}, {20, 49}, {21, 49}, {22, 49}, {23, 49},
      {23, 48}, {23, 47}, {23, 46}, {22, 46}, {21, 46}, {21, 45}, {21, 44},
      {21, 43}, {22, 43}, {23, 43}, {24, 43}, {24, 44}, {25, 44}, {25, 43},
      {26, 43}, {27, 43}, {28, 43}, {28, 44}, {28, 45}, {29, 45}, {30, 45},
      {31, 45}, {32, 45}, {32, 46}, {32, 47}, {33, 47}, {34, 47}, {34, 46},
      {35, 46}, {35, 45}, {36, 45}, {37, 45}, {38, 45}, {38, 46}, {38, 47},
      {38, 48}, {38, 49}, {39, 49}, {40, 49}, {41, 49}, {42, 49}, {43, 49},
      {44, 49}, {45, 49}, {46, 49}, {47, 49}, {48, 49}, {49, 49}};

  std::list<std::pair<int, int>> solution =
      MazeWaveSolver((MazeFileParser("tests/test_maze.txt").parse()),
                     std::pair<int, int>(0, 0), std::pair<int, int>(49, 49))
          .solve();

  EXPECT_EQ(expectedSolution, solution);
}

TEST_F(MazeTest, MazeSolver_2) {
  static const std::list<std::pair<int, int>> expectedSolution = {
      {10, 10}, {10, 11}, {10, 12}, {9, 12},  {8, 12},  {8, 13},  {8, 14},
      {8, 15},  {7, 15},  {6, 15},  {6, 16},  {6, 17},  {6, 18},  {6, 19},
      {7, 19},  {7, 20},  {7, 21},  {7, 22},  {7, 23},  {6, 23},  {6, 24},
      {6, 25},  {7, 25},  {8, 25},  {8, 26},  {8, 27},  {9, 27},  {9, 28},
      {9, 29},  {8, 29},  {8, 30},  {8, 31},  {8, 32},  {8, 33},  {7, 33},
      {6, 33},  {5, 33},  {4, 33},  {3, 33},  {2, 33},  {1, 33},  {0, 33},
      {0, 34},  {0, 35},  {0, 36},  {0, 37},  {1, 37},  {1, 36},  {2, 36},
      {3, 36},  {3, 37},  {3, 38},  {3, 39},  {2, 39},  {2, 40},  {2, 41},
      {2, 42},  {2, 43},  {3, 43},  {4, 43},  {5, 43},  {5, 42},  {6, 42},
      {6, 43},  {6, 44},  {7, 44},  {8, 44},  {8, 43},  {9, 43},  {9, 44},
      {10, 44}, {10, 45}, {10, 46}, {10, 47}, {10, 48}, {10, 49}, {11, 49},
      {12, 49}, {13, 49}, {13, 48}, {14, 48}, {14, 49}, {15, 49}, {16, 49},
      {17, 49}, {17, 48}, {18, 48}, {18, 49}, {19, 49}, {20, 49}, {21, 49},
      {22, 49}, {23, 49}, {23, 48}, {23, 47}, {23, 46}, {22, 46}, {21, 46},
      {21, 45}, {21, 44}, {21, 43}, {22, 43}, {23, 43}, {24, 43}, {24, 44},
      {25, 44}, {25, 43}, {26, 43}, {27, 43}, {28, 43}, {28, 44}, {28, 45},
      {29, 45}, {30, 45}, {31, 45}, {32, 45}, {32, 46}, {32, 47}, {33, 47},
      {34, 47}, {34, 46}, {35, 46}, {35, 45}, {36, 45}, {37, 45}, {38, 45},
      {38, 46}, {38, 47}, {38, 48}, {38, 49}, {39, 49}, {40, 49}, {41, 49},
      {42, 49}, {43, 49}, {44, 49}, {45, 49}, {46, 49}, {47, 49}, {48, 49},
      {49, 49}};

  std::list<std::pair<int, int>> solution =
      MazeWaveSolver((MazeFileParser("tests/test_maze.txt").parse()),
                     std::pair<int, int>(10, 10), std::pair<int, int>(49, 49))
          .solve();

  EXPECT_EQ(expectedSolution, solution);
}

TEST_F(MazeTest, MazeSolver_3) {
  static const std::list<std::pair<int, int>> expectedSolution = {
      {49, 0},  {49, 1},  {48, 1},  {48, 2},  {47, 2},  {47, 3},  {46, 3},
      {46, 4},  {47, 4},  {48, 4},  {49, 4},  {49, 5},  {49, 6},  {49, 7},
      {49, 8},  {49, 9},  {49, 10}, {49, 11}, {48, 11}, {48, 12}, {48, 13},
      {47, 13}, {46, 13}, {46, 14}, {46, 15}, {45, 15}, {45, 14}, {45, 13},
      {45, 12}, {44, 12}, {43, 12}, {42, 12}, {42, 11}, {41, 11}, {40, 11},
      {39, 11}, {39, 12}, {39, 13}, {38, 13}, {37, 13}, {37, 12}, {37, 11},
      {37, 10}, {36, 10}, {35, 10}, {34, 10}, {34, 9},  {34, 8},  {34, 7},
      {34, 6},  {34, 5},  {34, 4},  {34, 3},  {34, 2},  {33, 2},  {33, 3},
      {33, 4},  {33, 5},  {33, 6},  {33, 7},  {32, 7},  {32, 8},  {32, 9},
      {32, 10}, {31, 10}, {31, 11}, {30, 11}, {30, 12}, {30, 13}, {30, 14},
      {29, 14}, {28, 14}, {28, 13}, {28, 12}, {27, 12}, {26, 12}, {26, 13},
      {26, 14}, {26, 15}, {25, 15}, {25, 14}, {24, 14}, {23, 14}, {23, 13},
      {23, 12}, {22, 12}, {21, 12}, {21, 11}, {20, 11}, {20, 10}, {19, 10},
      {19, 11}, {18, 11}, {17, 11}, {16, 11}, {16, 10}, {15, 10}, {15, 11},
      {15, 12}, {15, 13}, {14, 13}, {13, 13}, {12, 13}, {12, 12}, {12, 11},
      {11, 11}, {10, 11}, {10, 12}, {9, 12},  {8, 12},  {8, 13},  {8, 14},
      {8, 15},  {7, 15},  {6, 15},  {6, 16},  {6, 17},  {6, 18},  {6, 19},
      {7, 19},  {7, 20},  {7, 21},  {7, 22},  {7, 23},  {6, 23},  {6, 24},
      {6, 25},  {7, 25},  {8, 25},  {8, 26},  {8, 27},  {9, 27},  {9, 28},
      {9, 29},  {8, 29},  {8, 30},  {8, 31},  {8, 32},  {8, 33},  {7, 33},
      {6, 33},  {5, 33},  {4, 33},  {3, 33},  {2, 33},  {1, 33},  {0, 33},
      {0, 34},  {0, 35},  {0, 36},  {0, 37},  {1, 37},  {1, 36},  {2, 36},
      {3, 36},  {3, 37},  {3, 38},  {3, 39},  {2, 39},  {2, 40},  {2, 41},
      {2, 42},  {2, 43},  {3, 43},  {4, 43},  {5, 43},  {5, 42},  {6, 42},
      {6, 43},  {6, 44},  {7, 44},  {8, 44},  {8, 43},  {9, 43},  {9, 44},
      {10, 44}, {10, 45}, {10, 46}, {10, 47}, {10, 48}, {10, 49}, {9, 49},
      {8, 49},  {7, 49},  {6, 49},  {5, 49},  {4, 49},  {3, 49},  {3, 48},
      {2, 48},  {1, 48},  {1, 49},  {0, 49}};

  std::list<std::pair<int, int>> solution =
      MazeWaveSolver((MazeFileParser("tests/test_maze.txt").parse()),
                     std::pair<int, int>(49, 0), std::pair<int, int>(0, 49))
          .solve();

  EXPECT_EQ(expectedSolution, solution);
}

TEST_F(MazeTest, MazeSolver_4) {
  static const std::list<std::pair<int, int>> expectedSolution = {
      {5, 5},   {5, 4},   {6, 4},   {6, 5},   {6, 6},   {6, 7},   {7, 7},
      {7, 8},   {8, 8},   {8, 9},   {9, 9},   {10, 9},  {10, 10}, {10, 11},
      {10, 12}, {9, 12},  {8, 12},  {8, 13},  {8, 14},  {8, 15},  {7, 15},
      {6, 15},  {6, 16},  {6, 17},  {6, 18},  {6, 19},  {7, 19},  {7, 20},
      {7, 21},  {7, 22},  {7, 23},  {6, 23},  {6, 24},  {6, 25},  {7, 25},
      {8, 25},  {8, 26},  {8, 27},  {9, 27},  {9, 28},  {9, 29},  {8, 29},
      {8, 30},  {8, 31},  {8, 32},  {8, 33},  {7, 33},  {6, 33},  {5, 33},
      {4, 33},  {3, 33},  {2, 33},  {1, 33},  {0, 33},  {0, 34},  {0, 35},
      {0, 36},  {0, 37},  {1, 37},  {1, 36},  {2, 36},  {3, 36},  {3, 37},
      {3, 38},  {3, 39},  {2, 39},  {2, 40},  {2, 41},  {2, 42},  {2, 43},
      {3, 43},  {4, 43},  {5, 43},  {5, 42},  {6, 42},  {6, 43},  {6, 44},
      {7, 44},  {8, 44},  {8, 43},  {9, 43},  {9, 44},  {10, 44}, {10, 45},
      {10, 46}, {10, 47}, {10, 48}, {10, 49}, {11, 49}, {12, 49}, {13, 49},
      {13, 48}, {14, 48}, {14, 47}, {15, 47}, {15, 46}, {15, 45}, {15, 44},
      {14, 44}, {13, 44}, {12, 44}, {11, 44}, {11, 43}, {11, 42}, {11, 41},
      {11, 40}};

  std::list<std::pair<int, int>> solution =
      MazeWaveSolver((MazeFileParser("tests/test_maze.txt").parse()),
                     std::pair<int, int>(5, 5), std::pair<int, int>(11, 40))
          .solve();

  EXPECT_EQ(expectedSolution, solution);
}

}  // namespace S21Tests
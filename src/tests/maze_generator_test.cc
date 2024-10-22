#include "tests.h"

namespace S21Tests {

TEST_F(MazeTest, EllerGenerator_3_3) {
  Maze m = EllerGenerator(3, 3).generateMaze();
  EXPECT_EQ(m.getRows(), 3);
  EXPECT_EQ(m.getCols(), 3);
}

TEST_F(MazeTest, EllerGenerator_4_4) {
  Maze m = EllerGenerator(4, 4).generateMaze();
  EXPECT_EQ(m.getRows(), 4);
  EXPECT_EQ(m.getCols(), 4);
}

TEST_F(MazeTest, EllerGenerator_50_50) {
  Maze m = EllerGenerator(50, 50).generateMaze();
  EXPECT_EQ(m.getRows(), 50);
  EXPECT_EQ(m.getCols(), 50);
}

TEST_F(MazeTest, EllerGenerator_10_2) {
  Maze m = EllerGenerator(10, 2).generateMaze();
  EXPECT_EQ(m.getRows(), 10);
  EXPECT_EQ(m.getCols(), 2);
}

TEST_F(MazeTest, EllerGenerator_2_10) {
  Maze m = EllerGenerator(2, 10).generateMaze();
  EXPECT_EQ(m.getRows(), 2);
  EXPECT_EQ(m.getCols(), 10);
}

TEST_F(MazeTest, EllerGenerator_2_15) {
  Maze m = EllerGenerator(2, 15).generateMaze();
  EXPECT_EQ(m.getRows(), 2);
  EXPECT_EQ(m.getCols(), 15);
}

TEST_F(MazeTest, EllerGenerator_15_2) {
  Maze m = EllerGenerator(15, 2).generateMaze();
  EXPECT_EQ(m.getRows(), 15);
  EXPECT_EQ(m.getCols(), 2);
}

TEST_F(MazeTest, EllerGenerator_11_1) {
  Maze m = EllerGenerator(11, 1).generateMaze();
  EXPECT_EQ(m.getRows(), 11);
  EXPECT_EQ(m.getCols(), 1);
}

}  // namespace S21Tests
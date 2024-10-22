#ifndef _MAZE_WAVE_SOLVER_H_
#define _MAZE_WAVE_SOLVER_H_

#include <limits>
#include <set>

#include "maze.h"

namespace s21 {

class MazeWaveSolver : public IMazeSolver {
 public:
  MazeWaveSolver(const Maze &maze, std::pair<int, int> start,
                 std::pair<int, int> end)
      : maze_(maze),
        start_(start.first, start.second),
        end_(end.first, end.second) {}

  std::list<std::pair<int, int>> solve() const override;

 private:
  struct Coordinate {
    int x, y;
    explicit Coordinate(size_t x, size_t y) : x(x), y(y) {}

    bool operator==(const Coordinate &other) const {
      return x == other.x && y == other.y;
    }

    bool operator!=(const Coordinate &other) const { return !(*this == other); }

    bool operator<(const Coordinate &other) const {
      if (x != other.x) {
        return x < other.x;
      }
      return y < other.y;
    }

    bool operator<=(const Coordinate &other) const {
      return *this < other || *this == other;
    }
  };

  enum class Direction { kUp, kDown, kRight, kLeft };
  static constexpr int kDirectionCount = 4;

  void propagateWave(Matrix<int> &pathMatrix, Coordinate current, Direction dir,
                     int prevValue) const;

  bool isWall(Coordinate current, Direction dir) const;
  static bool isOppositeDirection(Direction first, Direction second);

  Coordinate getNextPosition(Coordinate current, Direction dir) const;

  Coordinate getNearestNeumann(const Matrix<int> &pathMatrix,
                               Coordinate point) const;

  std::list<std::pair<int, int>> pickPath(const Matrix<int> &pathMatrix,
                                          Coordinate start,
                                          Coordinate end) const;

  const Maze &maze_;
  const Coordinate start_;
  const Coordinate end_;
};

}  // namespace s21

#endif

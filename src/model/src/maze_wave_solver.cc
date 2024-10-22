#include "../inc/maze_wave_solver.h"

namespace s21 {

std::list<std::pair<int, int>> MazeWaveSolver::solve() const {
  Matrix<int> pathMatrix(maze_.getRows(), maze_.getCols());
  pathMatrix(start_.y, start_.x) = 0;
  for (int d = 0; d < kDirectionCount; ++d) {
    Direction newDir = static_cast<Direction>(d);
    Coordinate nextPos = getNextPosition(start_, newDir);
    if (!isWall(start_, newDir)) {
      propagateWave(pathMatrix, nextPos, newDir,
                    pathMatrix(start_.y, start_.x));
    }
  }
  return pickPath(pathMatrix, start_, end_);
}

void MazeWaveSolver::propagateWave(Matrix<int>& pathMatrix, Coordinate current,
                                   Direction dir, int prevValue) const {
  pathMatrix(current.y, current.x) = prevValue + 1;

  for (int d = 0; d < kDirectionCount; ++d) {
    Direction newDir = static_cast<Direction>(d);
    if (!isOppositeDirection(dir, newDir)) {
      Coordinate nextPos = getNextPosition(current, newDir);
      if (!isWall(current, newDir) &&
          (pathMatrix(nextPos.y, nextPos.x) > prevValue + 1 ||
           pathMatrix(nextPos.y, nextPos.x) == 0)) {
        propagateWave(pathMatrix, nextPos, newDir,
                      pathMatrix(current.y, current.x));
      }
    }
  }
}

bool MazeWaveSolver::isOppositeDirection(Direction first, Direction second) {
  int sum = static_cast<int>(first) + static_cast<int>(second);
  return sum == 1 || sum == 5;
}

bool MazeWaveSolver::isWall(Coordinate current, Direction dir) const {
  switch (dir) {
    case Direction::kRight:
      return maze_.getVerticalWallMatrix()(current.y, current.x);
    case Direction::kLeft:
      return current.x == 0 ||
             maze_.getVerticalWallMatrix()(current.y, current.x - 1);
    case Direction::kUp:
      return current.y == 0 ||
             maze_.getHorizontalWallMatrix()(current.y - 1, current.x);
    case Direction::kDown:
      return maze_.getHorizontalWallMatrix()(current.y, current.x);
  }
  return true;  // Default return to satisfy compiler, though it should never
                // reach here
}

MazeWaveSolver::Coordinate MazeWaveSolver::getNextPosition(
    Coordinate current, Direction dir) const {
  switch (dir) {
    case Direction::kUp:
      return Coordinate(current.x, current.y - 1);
    case Direction::kDown:
      return Coordinate(current.x, current.y + 1);
    case Direction::kRight:
      return Coordinate(current.x + 1, current.y);
    case Direction::kLeft:
      return Coordinate(current.x - 1, current.y);
  }
  return current;  // Default return to satisfy compiler, though it should never
                   // reach here
}

MazeWaveSolver::Coordinate MazeWaveSolver::getNearestNeumann(
    const Matrix<int>& pathMatrix, Coordinate point) const {
  int minValue = std::numeric_limits<int>::max();
  Coordinate nearestCoord(point.x, point.y);

  for (int d = 0; d < kDirectionCount; ++d) {
    Direction dir = static_cast<Direction>(d);
    Coordinate neighbor = getNextPosition(point, dir);

    if (!isWall(point, dir) && neighbor.x >= 0 &&
        neighbor.x < static_cast<int>(pathMatrix.getCols()) && neighbor.y >= 0 &&
        neighbor.y < static_cast<int>(pathMatrix.getRows())) {
      int neighborValue = pathMatrix(neighbor.y, neighbor.x);
      if (neighborValue < minValue) {
        minValue = neighborValue;
        nearestCoord = neighbor;
      }
    }
  }

  return nearestCoord;
}

std::list<std::pair<int, int>> MazeWaveSolver::pickPath(
    const Matrix<int>& pathMatrix, Coordinate start, Coordinate end) const {
  std::list<std::pair<int, int>> path;
  Coordinate step = end;

  std::set<Coordinate> visited;

  while (step != start) {
    if (visited.count(step)) {
      break;
    }
    visited.insert(step);
    path.push_front(std::pair<int, int>(step.x, step.y));
    step = getNearestNeumann(pathMatrix, step);
  }

  path.push_front(std::pair<int, int>(start.x, start.y));

  return path;
}

}  // namespace s21

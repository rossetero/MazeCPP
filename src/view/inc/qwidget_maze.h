#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <list>
#include <utility>

#include "../../controller/inc/controller.h"
#include "../../model/inc/maze.h"

namespace s21 {

class QWidgetMaze : public QWidget {
 public:
  static QWidgetMaze *getInstance(Controller &controller, const s21::Maze *maze,
                                  QWidget *parent = nullptr) {
    if (!instance) {
      instance = new QWidgetMaze(controller, maze, parent);
      instance->move(40, 40);
    }
    return instance;
  }

  static void releaseInstance() {
    if (instance) {
      delete instance;
      instance = nullptr;
    }
  }

  void setMaze(const s21::Maze *newMaze) {
    if (maze != newMaze) {
      maze = newMaze;
    }
    startCell = QPoint(0, 0);
    endCell = QPoint(0, 0);
    update();
  }

  void paintPath(const std::list<std::pair<int, int>> &path) {
    pathToDraw = path;
    update();
  }

 protected:
  void paintEvent([[maybe_unused]] QPaintEvent *event) override {
    if (!maze) return;

    QPainter painter(this);
    QPen pen(Qt::gray, 1);
    painter.setPen(pen);

    const int rows = maze->getRows();
    const int cols = maze->getCols();
    const int cellSize = 500 / std::max(rows, cols);

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        int x = j * cellSize;
        int y = i * cellSize;

        if (maze->getHorizontalWallMatrix()(i, j)) {
          painter.drawLine(x, y + cellSize, x + cellSize, y + cellSize);
        }

        if (maze->getVerticalWallMatrix()(i, j)) {
          painter.drawLine(x + cellSize, y, x + cellSize, y + cellSize);
        }
      }
    }

    painter.drawRect(0, 0, cols * cellSize, rows * cellSize);

    if (isValidPoint(startCell) && isValidPoint(endCell)) {
      painter.drawPoint(QPoint(startCell.x() * cellSize + cellSize / 2,
                               startCell.y() * cellSize + cellSize / 2));
      painter.drawPoint(QPoint(endCell.x() * cellSize + cellSize / 2,
                               endCell.y() * cellSize + cellSize / 2));

      pathToDraw = controller.solveMaze(
          std::pair<int, int>(startCell.x(), startCell.y()),
          std::pair<int, int>(endCell.x(), endCell.y()));
    }

    if (!pathToDraw.empty()) {
      drawPath(painter, cellSize);
    }
  }

  void mousePressEvent(QMouseEvent *event) override {
    if (!maze) return;

    const int rows = maze->getRows();
    const int cols = maze->getCols();
    const int cellSize = 500 / std::max(rows, cols);

    int x = event->pos().x() / cellSize;
    int y = event->pos().y() / cellSize;

    if (x >= 0 && x < cols && y >= 0 && y < rows) {
      if (event->button() == Qt::LeftButton) {
        startCell = QPoint(x, y);
      } else if (event->button() == Qt::RightButton) {
        endCell = QPoint(x, y);
      }

      if (isValidPoint(startCell) && isValidPoint(endCell)) {
        update();
      }
    }
  }

  void drawPath(QPainter &painter, int cellSize) {
    painter.setPen(QPen(Qt::green, 1));
    auto it = pathToDraw.begin();
    int x1 = it->first * cellSize + cellSize / 2;
    int y1 = it->second * cellSize + cellSize / 2;

    for (++it; it != pathToDraw.end(); ++it) {
      int x2 = it->first * cellSize + cellSize / 2;
      int y2 = it->second * cellSize + cellSize / 2;
      painter.drawLine(x1, y1, x2, y2);
      x1 = x2;
      y1 = y2;
    }
  }

  bool isValidPoint(const QPoint &point) {
    return point.x() >= 0 && point.y() >= 0;
  }

  QSize sizeHint() const override { return QSize(500, 500); }

  QSize minimumSizeHint() const override { return QSize(500, 500); }

 private:
  QWidgetMaze(Controller &controller, const s21::Maze *maze = nullptr,
              QWidget *parent = nullptr)
      : QWidget(parent), maze(maze), controller(controller) {
    setFixedSize(500, 500);
  }

  ~QWidgetMaze() = default;

  static QWidgetMaze *instance;
  const s21::Maze *maze;
  QPoint startCell;
  QPoint endCell;
  std::list<std::pair<int, int>> pathToDraw;
  Controller &controller;

  QWidgetMaze(const QWidgetMaze &) = delete;
  QWidgetMaze &operator=(const QWidgetMaze &) = delete;
};

}  // namespace s21

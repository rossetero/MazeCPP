#ifndef VIEW_H
#define VIEW_H

#include <QFileDialog>
#include <QLineEdit>
#include <QMainWindow>
#include <QPainter>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <memory>

#include "../../controller/inc/controller.h"
#include "maze_console_printer.h"
#include "qwidget_maze.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(QWidget *parent = nullptr);
  ~View();

 private slots:

  void on_pushButton_MGenerate_clicked();

  void on_pushButton_MLoad_clicked();

  void on_lineEdit_Rows_editingFinished();

  void on_lineEdit_Cols_editingFinished();

 private:
  Ui::View *ui;
  std::unique_ptr<s21::Controller> controller_;

  bool validateInput(QLineEdit *lineEdit, const QRegularExpression &re);
  void printMaze();
};
#endif  // VIEW_H

#include <QApplication>

#include "view/inc/view.h"

s21::QWidgetMaze* s21::QWidgetMaze::instance = nullptr;

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  View w;
  w.show();
  return a.exec();
}

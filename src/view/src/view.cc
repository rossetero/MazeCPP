#include "../inc/view.h"

#include "ui_view.h"

View::View(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::View),
      controller_(std::make_unique<s21::Controller>()) {
  ui->setupUi(this);
  s21::QWidgetMaze::getInstance(*controller_, nullptr,
                                ui->stackedWidget->widget(0));
}

View::~View() { delete ui;
              s21::QWidgetMaze::releaseInstance();}

bool View::validateInput(QLineEdit *lineEdit, const QRegularExpression &re = QRegularExpression("^[1-9]$|^[1-4][0-9]$|^50$")) {
    QString text = lineEdit->text();
    QRegularExpressionMatch match = re.match(text);
    if (!match.hasMatch()) {
        lineEdit->setText("1");
        return false;
    }
    return true;
}

void View::on_pushButton_MGenerate_clicked() {
    validateInput(ui->lineEdit_Rows);
    validateInput(ui->lineEdit_Cols);
    size_t rows = ui->lineEdit_Rows->text().toULong();
    size_t cols = ui->lineEdit_Cols->text().toULong();
      controller_->generateMaze(rows, cols);
      printMaze();
}

void View::on_pushButton_MLoad_clicked() {
  QString fileName =
      QFileDialog::getOpenFileName(this, tr("Load maze"), "/Users");

  if (!fileName.isEmpty()) {
      try {
          controller_->LoadMazeFromFile(fileName.toStdString());
      } catch (...) {
          return;
      }

    s21::QWidgetMaze::getInstance(*controller_, nullptr,
                                  ui->stackedWidget->widget(0))
        ->setMaze(&controller_->getMaze());
    s21::MazeConsolePrinter(controller_->getMaze()).print(0, 0);
  } else {
    qDebug() << "No file selected.";
  }
}


void View::printMaze() {
    if (validateInput(ui->lineEdit_Cols) && validateInput(ui->lineEdit_Rows)) {
        s21::QWidgetMaze::getInstance(*controller_, nullptr, ui->stackedWidget->widget(0))
            ->setMaze(&controller_->getMaze());
        s21::MazeConsolePrinter(controller_->getMaze()).print(0, 0);
    }
}

void View::on_lineEdit_Rows_editingFinished() {
    validateInput(ui->lineEdit_Rows);
}

void View::on_lineEdit_Cols_editingFinished() {
    validateInput(ui->lineEdit_Cols);
}


#include "mainwindow.h"

#include <math.h>

#include "./ui_mainwindow.h"
#include "SmartCalc.h"
#include "credit_calc.h"
#include "deposit_calc.h"

QString input_str;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(push_button()));

  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(push_dot_button()));

  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(push_x_button()));

  connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this,
          SLOT(push_button_open_bracket()));
  connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this,
          SLOT(push_button_close_bracket()));

  connect(ui->pushButton_power, SIGNAL(clicked()), this,
          SLOT(push_button_operation()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this,
          SLOT(push_button_operation()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this,
          SLOT(push_button_operation()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(push_button_operation()));

  connect(ui->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(push_button_operation_un()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(push_button_operation_un()));

  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(push_button_operation_fn()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(push_button_operation_fn()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(push_button_operation_fn()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(push_button_operation_fn()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(push_button_operation_fn()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(push_button_operation_fn()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(push_button_operation_fn()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(push_button_operation_fn()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(push_button_operation_fn()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::push_button() {
  QPushButton *button = (QPushButton *)sender();
  if (input_str.isEmpty() == 0) {
    if (input_str.back() != ')' || input_str.back() != 'x') {
      input_str = (ui->label->text() + button->text());
    }
  } else {
    input_str = (ui->label->text() + button->text());
  }
  ui->label->setText(input_str);
}

void MainWindow::push_dot_button() {
  QPushButton *button = (QPushButton *)sender();
  if (input_str.isEmpty() == 0) {
    if (input_str.back() >= '0' && input_str.back() <= '9') {
      input_str = (ui->label->text() + button->text());
    }
  }
  ui->label->setText(input_str);
}

void MainWindow::push_x_button() {
  QPushButton *button = (QPushButton *)sender();
  if (input_str.isEmpty() == 0) {
    if (input_str.back() == ')' || input_str.back() == 'x' ||
        (input_str.back() >= '0' && input_str.back() <= '9') ||
        input_str == '.') {
    } else {
      input_str = (ui->label->text() + button->text());
    }
  } else {
    input_str = (ui->label->text() + button->text());
  }
  ui->label->setText(input_str);
}

void MainWindow::push_button_operation() {
  QPushButton *button = (QPushButton *)sender();
  if (input_str.isEmpty() == 0) {
    if ((input_str.back() >= '0' && input_str.back() <= '9') ||
        input_str.back() == ')' || input_str.back() == 'x') {
      input_str = (ui->label->text() + button->text());
      ui->label->setText(input_str);
    }
  }
}

void MainWindow::push_button_operation_un() {
  QPushButton *button = (QPushButton *)sender();
  if (input_str.isEmpty() == 0) {
    if ((input_str.back() >= '0' && input_str.back() <= '9') ||
        input_str.back() == ')' || input_str.back() == '(' ||
        input_str.back() == 'x') {
      input_str = (ui->label->text() + button->text());
    }
  } else {
    input_str = (ui->label->text() + button->text());
  }
  ui->label->setText(input_str);
}

void MainWindow::push_button_close_bracket() {
  QPushButton *button = (QPushButton *)sender();
  if (input_str.isEmpty() == 0) {
    if ((input_str.back() >= '0' && input_str.back() <= '9') ||
        input_str.back() == ')' || input_str.back() == 'x') {
      input_str = (ui->label->text() + button->text());
    }
  }
  ui->label->setText(input_str);
}

void MainWindow::push_button_open_bracket() {
  QPushButton *button = (QPushButton *)sender();
  if (input_str.isEmpty() == 0) {
    if (!(input_str.back() >= '0' && input_str.back() <= '9' ||
          input_str.back() == '.' || input_str.back() == 'x')) {
      input_str = (ui->label->text() + button->text());
    }
  } else {
    input_str = (ui->label->text() + button->text());
  }
  ui->label->setText(input_str);
}

void MainWindow::push_button_operation_fn() {
  QPushButton *button = (QPushButton *)sender();
  if (input_str.isEmpty() == 0) {
    if (input_str.back() == '+' || input_str.back() == '-' ||
        input_str.back() == '(' || input_str.back() == '*' ||
        input_str.back() == '/' || input_str.back() == 'd' ||
        input_str.back() == '^') {
      input_str = (ui->label->text() + button->text());
    }
  } else {
    input_str = (ui->label->text() + button->text());
  }
  ui->label->setText(input_str);
}

void MainWindow::on_pushButton_equal_clicked() {
  int len = input_str.size();
  if (len < 256) {
    QByteArray ba = input_str.toLocal8Bit();
    char *str = ba.data();
    double result = 0;
    double x_value = ui->x_value->text().toDouble();
    int ex_code = 0;
    ex_code = main_for_calc(str, &result, x_value);
    input_str.clear();
    ui->label->clear();

    if (ex_code == 0) {
      QString str_res = QString::number(result, 'g', 7);
      ui->label->setText(str_res);
    } else {
      ui->label->setText("INCORRECT INPUT");
    }
  } else {
    ui->label->setText("Too long string");
  }
}

void MainWindow::on_pushButton_all_clean_clicked() {
  input_str.clear();
  ui->label->clear();
  ui->widget->clearGraphs();
}

void MainWindow::on_pushButton_clean_clicked() {
  if (input_str.isEmpty() == 0) {
    if (input_str.back() == 'd' || input_str.back() == 'g') {
      input_str.chop(3);
    } else if (input_str.back() == 't') {
      input_str.chop(4);
    } else if (input_str.back() == 's') {
      input_str.chop(3);
      if (input_str.isEmpty() == 0 && input_str.back() == 'a') {
        input_str.chop(1);
      }
    } else if (input_str.back() == 'n') {
      input_str.chop(2);
      if (input_str.isEmpty() == 0 &&
          (input_str.back() == 's' || input_str.back() == 't')) {
        input_str.chop(1);
        if (input_str.isEmpty() == 0 && input_str.back() == 'a') {
          input_str.chop(1);
        }
      }
    } else {
      input_str.chop(1);
    }
    ui->label->setText(input_str);
  }
}

void MainWindow::on_pushButton_graph_clicked() {
  ui->widget->clearGraphs();
  double x_max = ui->input_xmax->text().toDouble();
  double x_min = ui->input_xmin->text().toDouble();
  double y_max = ui->input_ymax->text().toDouble();
  double y_min = ui->input_ymin->text().toDouble();

  double x_range = 10000;
  double x_step = abs(x_max - x_min) / x_range;

  QVector<double> x(x_range), y(x_range);

  int ex_code = 0;
  QByteArray ba = input_str.toLocal8Bit();
  char *str = ba.data();

  for (int i = 0; i < x_range && ex_code == 0; ++i) {
    x[i] = x_min + x_step * i;
    double result = 0;
    ex_code = main_for_calc(str, &result, x[i]);
    y[i] = result;
  }

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);

  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");

  ui->widget->xAxis->setRange(x_min, x_max);
  ui->widget->yAxis->setRange(y_min, y_max);

  ui->widget->replot();
}

void MainWindow::on_credit_calc_clicked() {
  credit_calc window;
  window.setModal(true);
  window.exec();
}

void MainWindow::on_deposit_calc_clicked() {
  deposit_calc window;
  window.setModal(true);
  window.exec();
}

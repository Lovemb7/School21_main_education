#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef __cplusplus
extern "C" {
#endif
#include "SmartCalc.h"
#ifdef __cplusplus
}
#endif

#include <QMainWindow>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;

 private slots:
  void push_button();
  void push_dot_button();
  void push_x_button();
  void push_button_operation();
  void push_button_operation_un();
  void push_button_operation_fn();
  void push_button_close_bracket();
  void push_button_open_bracket();
  void on_pushButton_equal_clicked();
  void on_pushButton_clean_clicked();
  void on_pushButton_all_clean_clicked();
  void on_pushButton_graph_clicked();
  void on_credit_calc_clicked();
  void on_deposit_calc_clicked();
};
#endif  // MAINWINDOW_H

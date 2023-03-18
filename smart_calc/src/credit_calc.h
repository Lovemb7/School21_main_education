#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QDialog>

#ifdef __cplusplus
extern "C" {
#endif
#include "SmartCalc.h"
#ifdef __cplusplus
}
#endif

namespace Ui {
class credit_calc;
}

class credit_calc : public QDialog {
  Q_OBJECT

 public:
  explicit credit_calc(QWidget *parent = nullptr);
  ~credit_calc();

  double credit_sum;
  int credit_term;
  float credit_percent;
  double monthly_payment;
  int type = 0;

 private slots:
  void on_make_calc_clicked();
  void on_make_table_clicked();

 private:
  Ui::credit_calc *ui;
};

#endif  // CREDIT_CALC_H

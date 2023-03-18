#ifndef DEPOSIT_CALC_H
#define DEPOSIT_CALC_H

#include <QDialog>

#ifdef __cplusplus
extern "C" {
#endif
#include "SmartCalc.h"
#ifdef __cplusplus
}
#endif

namespace Ui {
class deposit_calc;
}

class deposit_calc : public QDialog {
  Q_OBJECT

 public:
  explicit deposit_calc(QWidget *parent = nullptr);
  ~deposit_calc();
  int deposit_term;

 private slots:
  void on_pushButton_clicked();
  void on_checkBox_add_stateChanged(int arg1);

 private:
  Ui::deposit_calc *ui;
};

#endif  // DEPOSIT_CALC_H

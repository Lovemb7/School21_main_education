#include "deposit_calc.h"

#include "ui_deposit_calc.h"

deposit_calc::deposit_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::deposit_calc) {
  ui->setupUi(this);
}

deposit_calc::~deposit_calc() { delete ui; }

void deposit_calc::on_pushButton_clicked() {
  double deposit_sum;
  float deposit_percent;
  float tax_percent;
  int type_cap = 0;
  int type_pay = 0;

  ui->interest_income->setText("");
  ui->total_deposit_sum->setText("");
  ui->tax_sum->setText("");
  ui->error_label->setText("");

  deposit_sum = ui->deposit_sum->text().toDouble();
  deposit_percent = ui->deposit_percent->text().toFloat();
  tax_percent = ui->tax_percent->text().toFloat();
  deposit_term = ui->deposit_term->text().toInt();

  if (ui->radioB_mon_cap->isChecked()) {
    type_cap = 1;
  } else if (ui->radioB_end_cap->isChecked()) {
    type_cap = 2;
  }

  if (ui->radioB_mon_pay->isChecked()) {
    type_pay = 1;
  } else if (ui->radioB_end_pay->isChecked()) {
    type_pay = 2;
  }

  if (type_cap == 0 || type_pay == 0 || deposit_sum < 0.01 ||
      deposit_percent < 0 || deposit_percent > 100 || tax_percent < 0 ||
      tax_percent > 100 || deposit_term < 1 || deposit_term > 600) {
    ui->error_label->setText("INCORRECT INPUT");
  } else {
    double add_sum[deposit_term];

    if (ui->checkBox_add->isChecked()) {
      for (int i = 0; i < deposit_term; i++) {
        QTableWidgetItem *itm = ui->tableWidget->item(i, 0);
        if (itm != NULL) {
          add_sum[i] = itm->text().toDouble();
        } else {
          add_sum[i] = 0;
        }
      }
    }

    double interest_income = 0;
    double total_deposit_sum = 0;
    double tax_sum = 0;
    int ex_code = 0;

    ex_code = deposit_calc_fn(deposit_sum, deposit_term, deposit_percent,
                              tax_percent, type_cap, type_pay, add_sum,
                              &interest_income, &total_deposit_sum, &tax_sum);
    if (interest_income >= 0 && total_deposit_sum >= 0 && ex_code == 0) {
      QString int_income = QString::number(interest_income, 'f', 2);
      ui->interest_income->setText(int_income);
      QString total_dep_sum = QString::number(total_deposit_sum, 'f', 2);
      ui->total_deposit_sum->setText(total_dep_sum);
      QString total_tax_sum = QString::number(tax_sum, 'f', 2);
      ui->tax_sum->setText(total_tax_sum);
    } else {
      ui->error_label->setText("INCORRECT INPUT");
    }
  }
}

void deposit_calc::on_checkBox_add_stateChanged(int arg1) {
  if (ui->checkBox_add->isChecked()) {
    deposit_term = ui->deposit_term->text().toInt();
    ui->tableWidget->setRowCount(deposit_term);
    ui->tableWidget->setColumnCount(1);
  } else {
    ui->tableWidget->clear();
  }
}

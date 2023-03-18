#include "credit_calc.h"

#include <QTableWidgetItem>

#include "QtWidgets/qtableview.h"
#include "ui_credit_calc.h"

credit_calc::credit_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::credit_calc) {
  ui->setupUi(this);
}

credit_calc::~credit_calc() { delete ui; }

void credit_calc::on_make_calc_clicked() {
  ui->label_error->setText("");
  ui->monthly_payment->setText("");
  ui->overpayment->setText("");
  ui->total_sum->setText("");

  credit_sum = ui->credit_sum->text().toDouble();
  credit_term = ui->credit_term->text().toInt();
  credit_percent = ui->credit_percent->text().toFloat();

  if (ui->radioButton->isChecked()) {
    type = 1;
  } else if (ui->radioButton_2->isChecked()) {
    type = 2;
  }

  if (type == 0 || credit_sum < 10000 || credit_sum > 100000000 ||
      credit_term < 1 || credit_term > 600 || credit_percent < 0.01 ||
      credit_percent > 100) {
    ui->label_error->setText("Incorrect input");
  } else {
    double overpayment;
    double total_sum;

    credit_calc_fn(credit_sum, credit_term, credit_percent, type,
                   &monthly_payment, &overpayment, &total_sum);

    QString mon_pay = QString::number(monthly_payment, 'f', 2);
    ui->monthly_payment->setText(mon_pay);
    QString overpay = QString::number(overpayment, 'f', 2);
    ui->overpayment->setText(overpay);
    QString tot_sum = QString::number(total_sum, 'f', 2);
    ui->total_sum->setText(tot_sum);
  }
}

void credit_calc::on_make_table_clicked() {
  ui->tableWidget->setRowCount(credit_term);
  ui->tableWidget->setColumnCount(1);

  if (type == 1) {
    for (int i = 0; i < credit_term; i++) {
      QTableWidgetItem *itm =
          new QTableWidgetItem(QString::number(monthly_payment));
      ui->tableWidget->setItem(i, 0, itm);
    }
  } else if (type == 2) {
    for (int i = 0; i < credit_term; i++) {
      double month_pay_count;
      month_pay_count =
          credit_sum / credit_term +
          (credit_sum - monthly_payment * i) * credit_percent / 1200;
      QTableWidgetItem *itm =
          new QTableWidgetItem(QString::number(month_pay_count));
      ui->tableWidget->setItem(i, 0, itm);
    }
  }
}

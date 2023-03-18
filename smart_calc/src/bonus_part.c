#include "SmartCalc.h"

int credit_calc_fn(double credit_sum, int credit_term, float credit_percent,
                   int type, double *monthlty_payment, double *overpayment,
                   double *total_sum) {
  int ex_code = 0;
  if (type == 1) {
    credit_percent = credit_percent / 100 / 12;
    *monthlty_payment = credit_sum * credit_percent *
                        pow(1. + credit_percent, credit_term) /
                        (pow(1. + credit_percent, credit_term) - 1.);
    *total_sum = *monthlty_payment * credit_term;
    *overpayment = *total_sum - credit_sum;
  } else if (type == 2) {
    double mon_loan = credit_sum / credit_term;
    *total_sum = 0;
    for (int i = 0; i < credit_term; i++) {
      *total_sum +=
          mon_loan + (credit_sum - mon_loan * i) * credit_percent / 1200;
    }
    *overpayment = *total_sum - credit_sum;
    *monthlty_payment = mon_loan + credit_sum * credit_percent / 1200;
  }
  return ex_code;
}

int deposit_calc_fn(double deposit_sum, int deposit_term, float deposit_percent,
                    float tax_percent, int type_cap, int type_pay,
                    const double *add_sum, double *interest_income,
                    double *total_deposit_sum, double *tax_sum) {
  int ex_code = 0;
  if (type_cap == 2) {
    *interest_income = 0;
    for (int i = 0; i < deposit_term && ex_code == 0; i++) {
      deposit_sum = deposit_sum + add_sum[i];
      if (deposit_sum < 0) ex_code = 1;
      double monthly_percent = deposit_sum * deposit_percent / 1200;
      *interest_income = *interest_income + monthly_percent;
    }
    *total_deposit_sum = deposit_sum + *interest_income;
    *tax_sum = *interest_income * tax_percent / 100;

  } else if (type_cap == 1 && type_pay == 2) {
    *interest_income = 0;
    double monthly_percent = 0;
    for (int i = 0; i < deposit_term && ex_code == 0; i++) {
      deposit_sum = deposit_sum + add_sum[i] + monthly_percent;
      if (deposit_sum < 0) ex_code = 1;
      monthly_percent = deposit_sum * deposit_percent / 1200;
      *interest_income = *interest_income + monthly_percent;
    }
    *total_deposit_sum = deposit_sum + monthly_percent;
    *tax_sum = *interest_income * tax_percent / 100;

  } else if (type_cap == 1 && type_pay == 1) {
    *interest_income = 0;
    for (int i = 0; i < deposit_term && ex_code == 0; i++) {
      deposit_sum = deposit_sum + add_sum[i];
      if (deposit_sum < 0) ex_code = 1;
      double monthly_percent = deposit_sum * deposit_percent / 1200;
      *interest_income = *interest_income + monthly_percent;
    }
    *total_deposit_sum = deposit_sum + *interest_income;
    *tax_sum = *interest_income * tax_percent / 100;
  }
  return ex_code;
}

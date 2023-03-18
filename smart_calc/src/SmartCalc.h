#ifndef SmartCalc_h
#define SmartCalc_h

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct token {
  double value;
  int type;
  int precedence;
  struct token *next;
} token;

enum fn_type {
  type_number = 0,
  type_open_bracket = 1,
  type_close_bracket = 2,
  type_sum = 3,
  type_minus = 4,
  type_mult = 5,
  type_div = 6,
  type_power = 7,
  type_mod = 8,
  type_cos = 11,
  type_sin = 12,
  type_tan = 13,
  type_acos = 14,
  type_asin = 15,
  type_atan = 16,
  type_sqrt = 17,
  type_ln = 18,
  type_log = 19,
  type_x = 20
};

int main_for_calc(char *input_str, double *result, double x_value);

int parcer(char *input_str, token **head);
void shunting_yard(token **head, token **output);
double calc_rpn(token **output, double x_value);
double unary_fn_calc(double number1, int type);
double binary_fn_calc(double number1, double number2, int type);

void push(token **head, double value, int type, int precedence);
int pop(token **head);
void copy_token(token **input, token **output);
void flip_stack(token **input, token **output);

int credit_calc_fn(double credit_sum, int credit_term, float credit_percent,
                   int type, double *monthlty_payment, double *overpayment,
                   double *total_sum);
int deposit_calc_fn(double deposit_sum, int deposit_term, float deposit_percent,
                    float tax_percent, int type_cap, int type_pay,
                    const double *add_sum, double *interest_income,
                    double *total_deposit_sum, double *tax_sum);

#endif /* SmartCalc_h */

#include "SmartCalc.h"

int main_for_calc(char *input_str, double *result, double x_value) {
  int ex_code = 0;
  token *head = NULL;
  token *output = NULL;
  token *input = NULL;
  ex_code = parcer(input_str, &head);
  if (ex_code == 0) {
    shunting_yard(&head, &output);
    flip_stack(&output, &input);
    *result = calc_rpn(&input, x_value);
  } else {
    while (head != NULL) {
      pop(&head);
    }
  }
  return ex_code;
}

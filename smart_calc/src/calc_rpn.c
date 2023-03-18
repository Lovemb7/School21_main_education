#include "SmartCalc.h"

double calc_rpn(token **input, double x_value) {
  double result = 0;
  token *stack = NULL;
  while (*input != NULL) {
    if ((*input)->type == type_number) {
      copy_token(input, &stack);
      pop(input);
    } else if ((*input)->type == type_x) {
      (*input)->value = x_value;
      copy_token(input, &stack);
      pop(input);
    } else if ((*input)->type >= type_sum && (*input)->type <= type_mod &&
               stack != NULL) {
      double number2 = stack->value;
      pop(&stack);
      result = binary_fn_calc(stack->value, number2, (*input)->type);
      pop(&stack);
      pop(input);
      push(&stack, result, type_number, 1);
    } else if ((*input)->type >= type_cos && stack != NULL) {
      result = unary_fn_calc(stack->value, (*input)->type);
      pop(&stack);
      pop(input);
      push(&stack, result, type_number, 1);
    }
  }
  if (stack != NULL) result = stack->value;
  pop(&stack);
  return result;
}

double unary_fn_calc(double number1, int type) {
  double result = 0;
  if (type == type_cos) result = cos(number1);
  if (type == type_sin) result = sin(number1);
  if (type == type_tan) result = tan(number1);
  if (type == type_acos) result = acos(number1);
  if (type == type_asin) result = asin(number1);
  if (type == type_atan) result = atan(number1);
  if (type == type_sqrt) result = sqrt(number1);
  if (type == type_ln) result = log(number1);
  if (type == type_log) result = log10(number1);
  return result;
}

double binary_fn_calc(double number1, double number2, int type) {
  double result = 0;
  if (type == type_sum) result = number1 + number2;
  if (type == type_minus) result = number1 - number2;
  if (type == type_mult) result = number1 * number2;
  if (type == type_div) result = number1 / number2;
  if (type == type_power) result = pow(number1, number2);
  if (type == type_mod) result = fmod(number1, number2);
  return result;
}

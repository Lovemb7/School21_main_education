#include "SmartCalc.h"

int parcer(char *input_str, token **head) {
  int ex_code = 0;
  int len = (int)strlen(input_str);
  if (len == 0) ex_code = 1;
  double number = 0;
  int dot_qty = 0;
  int open_bracket_qty = 0;
  int close_bracket_qty = 0;
  for (int i = len - 1;
       i >= 0 && ex_code == 0 && open_bracket_qty <= close_bracket_qty;) {
    switch (input_str[i]) {
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '0':
      case '.':
        dot_qty = 0;
        while (i >= 0 && ((input_str[i] > 47 && input_str[i] < 58) ||
                          input_str[i] == '.')) {
          if (input_str[i] == '.') dot_qty += 1;
          if (dot_qty > 1) {
            ex_code = 1;
            break;
          }
          i--;
        }
        i++;
        number = strtod(&input_str[i], NULL);
        push(head, number, type_number, 1);
        i--;
        break;
      case '(':
        open_bracket_qty += 1;
        push(head, 0, type_open_bracket, 0);
        i--;
        break;
      case ')':
        close_bracket_qty += 1;
        push(head, 0, type_close_bracket, 0);
        i--;
        break;
      case '+':
        if (i == 0 || input_str[i - 1] == '(') {
          push(head, 0, type_number, 1);
        }
        push(head, 0, type_sum, 6);
        i--;
        break;
      case '-':
        if (i == 0 || input_str[i - 1] == '(') {
          push(head, 0, type_number, 1);
        }
        push(head, 0, type_minus, 6);
        i--;
        break;
      case '*':
        push(head, 0, type_mult, 8);
        i--;
        break;
      case '/':
        push(head, 0, type_div, 8);
        i--;
        break;
      case '^':
        push(head, 0, type_power, 9);
        i--;
        break;
      case 'd':
        push(head, 0, type_mod, 8);
        i = i - 3;
        break;
      case 's':
        if (i > 2 && input_str[i - 3] == 'a') {
          push(head, 0, type_acos, 8);
          i = i - 4;
        } else {
          push(head, 0, type_cos, 8);
          i = i - 3;
        }
        break;
      case 'n':
        if (i > 0 && input_str[i - 1] == 'l') {
          push(head, 0, type_ln, 8);
          i = i - 2;
        } else if (i > 0 && input_str[i - 1] == 'a') {
          if (i > 2 && input_str[i - 3] == 'a') {
            push(head, 0, type_atan, 8);
            i = i - 4;
          } else {
            push(head, 0, type_tan, 8);
            i = i - 3;
          }
        } else if (i > 0 && input_str[i - 1] == 'i') {
          if (i > 2 && input_str[i - 3] == 'a') {
            push(head, 0, type_asin, 8);
            i = i - 4;
          } else {
            push(head, 0, type_sin, 8);
            i = i - 3;
          }
        }
        break;
      case 't':
        push(head, 0, type_sqrt, 8);
        i = i - 4;
        break;
      case 'g':
        push(head, 0, type_log, 8);
        i = i - 3;
        break;
      case 'x':
        push(head, 0, type_x, 1);
        i--;
        break;
    }
  }
  if (open_bracket_qty != close_bracket_qty) ex_code = 1;
  return ex_code;
}

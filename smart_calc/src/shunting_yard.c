#include "SmartCalc.h"

void shunting_yard(token **head, token **output) {
  token *stack = NULL;
  while (*head != NULL) {
    if ((*head)->type == type_number || (*head)->type == type_x) {
      copy_token(head, output);
      pop(head);
    } else if ((*head)->type == type_open_bracket) {
      copy_token(head, &stack);
      pop(head);
    } else if ((*head)->type == type_close_bracket) {
      while (stack != NULL && (*stack).type != type_open_bracket) {
        copy_token(&stack, output);
        pop(&stack);
      }
      pop(&stack);
      if (stack != NULL && (*stack).type > 10) {
        copy_token(&stack, output);
        pop(&stack);
      }
      pop(head);
    } else if ((*head)->type >= type_sum && (*head)->type <= type_mod &&
               (*head)->type != type_power) {
      while (stack != NULL && ((*stack).precedence >= (*head)->precedence)) {
        copy_token(&stack, output);
        pop(&stack);
      }
      copy_token(head, &stack);
      pop(head);
    } else if ((*head)->type == type_power) {
      while (stack != NULL && ((*stack).precedence > (*head)->precedence)) {
        copy_token(&stack, output);
        pop(&stack);
      }
      copy_token(head, &stack);
      pop(head);
    } else if ((*head)->type >= type_cos) {
      copy_token(head, &stack);
      pop(head);
    }
  }
  while (stack != NULL) {
    copy_token(&stack, output);
    pop(&stack);
  }
}

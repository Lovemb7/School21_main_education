#include "SmartCalc.h"

void push(token **head, double value, int type, int precedence) {
  token *tmp = (token *)malloc(sizeof(token));
  tmp->value = value;
  tmp->type = type;
  tmp->precedence = precedence;
  tmp->next = *head;
  *head = tmp;
}

int pop(token **head) {
  int ex_code = 0;
  if (*head == NULL) {
    ex_code = 1;
  } else {
    token *prev = NULL;
    prev = *head;
    *head = (*head)->next;
    free(prev);
  }
  return ex_code;
}

void copy_token(token **input, token **output) {
  push(output, (*input)->value, (*input)->type, (*input)->precedence);
}

void flip_stack(token **input, token **output) {
  while (*input != NULL) {
    copy_token(input, output);
    pop(input);
  }
}

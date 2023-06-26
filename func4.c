#include "monty.h"

/**
 * sub - sub opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void sub(stack_t **stack, unsigned int line_number) {
    stack_t *temp;
    int val1, val2, valsub;
    if (lenStack(stack) < 2) {
        fprintf(stderr,"L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    val1 = temp->n;
    val2 = (*stack)->n;
    valsub = val1 - val2;
    (*stack)->n = valsub;
    free(temp);
    temp = NULL;
}

/**
 * op_div - div opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void op_div(stack_t **stack, unsigned int line_number) {
    stack_t *temp;
    int val1, val2, valdiv;
    if (lenStack(stack) < 2) {
        fprintf(stderr,"L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    val1 = temp->n;
    val2 = (*stack)->n;
    if (val1 == 0) {
        fprintf(stderr,"L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    valdiv = val2 / val1;
    (*stack)->n = valdiv;
    free(temp);
    temp = NULL;
}

/**
 * mul - mul opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void mul(stack_t **stack, unsigned int line_number) {
    stack_t *temp;
    int val1, val2, valmul;
    if (lenStack(stack) < 2) {
        fprintf(stderr,"L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    val1 = temp->n;
    val2 = (*stack)->n;
    valmul = val2 * val1;
    (*stack)->n = valmul;
    free(temp);
    temp = NULL;
}

/**
 * mod - mod opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void mod(stack_t **stack, unsigned int line_number) {
    stack_t *temp;
    int val1, val2, valmod;
    if (lenStack(stack) < 2) {
        fprintf(stderr,"L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    val1 = temp->n;
    val2 = (*stack)->n;
    if (val1 == 0) {
        fprintf(stderr,"L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    valmod = val2 % val1;
    (*stack)->n = valmod;
    free(temp);
    temp = NULL;
}

/**
 * pchar - pchar opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void pchar(stack_t **stack, unsigned int line_number) {
    int val;
    if (isempty(stack)) {
        fprintf(stderr,"L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    val = (*stack)->n;
    if (val < 0 || val > 127) {
        fprintf(stderr,"L%u: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", val);
}

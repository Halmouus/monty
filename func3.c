#include "monty.h"

/**
 * isempty - check if stack is empty
 * @stack: the stack to operate
 * Return : 1 if empty, 0 if not
 */
int isempty(stack_t **stack) {
    if (*stack == NULL)
        return 1;
    return 0;
}

/**
 * lenStack - returns the number of elements of a stack
 * @stack: the stack to operate
 * Return : number of elements in the stack
 */
int lenStack(stack_t **stack) {
    int len = 0;
    stack_t *temp;
    temp = *stack;
    while (temp) {
        len++;
        temp = temp->next;
    }
    return len;
}

/**
 * swap - swap opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void swap(stack_t **stack, unsigned int line_number) {
    stack_t *temp;
    int tempVal;
    if (lenStack(stack) < 2) {
        fprintf(stderr,"L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = (*stack)->next;
    tempVal = (*stack)->n;
    (*stack)->n = temp->n;
    temp->n = tempVal;
}

/**
 * add - add opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void add(stack_t **stack, unsigned int line_number) {
    stack_t *temp;
    int val1, val2, valSum;
    if (lenStack(stack) < 2) {
        fprintf(stderr,"L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    val1 = temp->n;
    val2 = (*stack)->n;
    valSum = val1 + val2;
    (*stack)->n = valSum;
    free(temp);
    temp = NULL;
}

/**
 * nop - nop opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void nop(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number) {
}

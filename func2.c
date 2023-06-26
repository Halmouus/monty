#include "monty.h"

stack_t *stack = NULL;

/**
 * push - push opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 * @data : data to be pushed to the stack
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number, int data) {
    stack_t *new_insert = malloc(sizeof(stack_t));
    if (new_insert == NULL) {
        perror("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_insert->n = data;
    new_insert->next = *stack;
    new_insert->prev = NULL;
    if (*stack != NULL)
        (*stack)->prev = new_insert;
    *stack = new_insert;
}

/**
 * pop - pop opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void pop(stack_t **stack, unsigned int line_number) {
    stack_t *temp;
    if (isempty(stack)) {
        fprintf(stderr,"L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    temp = NULL;
}

/**
 * pint - pint opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void pint(stack_t **stack, unsigned int line_number) {
    if (isempty(stack)) {
        fprintf(stderr,"L%u: can't pint an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pall - pall opcode
 * @stack: the stack to operate
 * @line_number : line number of the monty file
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number) {
    int i = 0;
    stack_t *temp;
    if (isempty(stack))
        return;
    temp = *stack;
    while (temp) {
        printf("%d\n", temp->n);
        i++;
        temp = temp->next;
    }
    
}

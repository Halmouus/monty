#include "monty.h"

/**
 * isInteger - checks if integer
 * @str: string to be checked
 * Return: 1 if integer, 0 if not or if str is NULL or empty
 */
int isInteger(char *str) {
    int i = 0;
    if (str == NULL || strlen(str) == 0)
        return 0;
    while(str[i]) {
        if (str[i] < 48 || str[i] > 57)
            return 0;
        i++;
    }
    return 1;
}

/**
 * isValidCommand - checks if str as a valid opcode
 * @str: string to be checked
 * Return: 1 if valid, 0 if not
 */
int isValidCommand(char *str) {
    char *cmd_vector[] = {"push", "pall", "pint", "pop", "swap", "add", "nop", "mul", "div", "sub", "mod", NULL};
    int i = 0;
    while (cmd_vector[i]) {
        if (strcmp(str, cmd_vector[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

/**
 * get_instruction - gets the upcode instruction
 * @str: opcode instruction
 * Return: pointer to the appropriate function, NULL otherwise
 */
void (*get_instruction(const char *str))(stack_t **, unsigned int) {
    int i = 0;
    instruction_t instrucs[] = {
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"add", add},
        {"swap", swap},
        {"nop", nop},
        {"sub", sub},
        {"div", op_div},
        {"mul", mul},
        {"mod", mod},
        {NULL, NULL},
    };
    while(instrucs[i].opcode) {
        if (!strcmp(str, instrucs[i].opcode)) {
            return (instrucs[i].f);
        }
        i++;
    }
    return NULL;
}

/**
 * read_monty - reads a monty file
 * @filename: name of the file
 */
void read_monty(const char *filename) {

    FILE *file;
    int r;
    size_t len;
    unsigned int m_line = 0;
    char *buff = NULL, *token, *arg;
    if (filename == NULL)
        return;
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((r = getline(&buff, &len, file)) != -1) {
        m_line++;
        token = strtok(buff, " \n\t");
        if (!token) {
            continue;
        }
        else if (isValidCommand(token)) {
            if (strcmp(token,"push") == 0) {
                arg = strtok(NULL, " \n\t");
                if (isInteger(arg)) {
                    push(&stack, m_line, atoi(arg));
                    continue;
                }
                else {
                    fprintf(stderr,"L%u: usage: push integer\n", m_line);
                    fclose(file);
                    free(buff);
                    exit(EXIT_FAILURE);
                }
            }
            get_instruction(token)(&stack, m_line);
        }
        else {
            fprintf(stderr,"L%u: unknown instruction %s\n", m_line, token);
            fclose(file);
            free(buff);
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);
    free(buff);
}

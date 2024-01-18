#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int element;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        stack_t *(*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_stack(stack_t **stack);
stack_t *_div(stack_t **stack, unsigned int line_number);
stack_t *sub(stack_t **stack, unsigned int line_number);
stack_t *pint(stack_t **stack, unsigned int line_number);
stack_t *push(stack_t **stack, unsigned int line_number);
stack_t *pall(stack_t **stack, unsigned int line_number);
stack_t *nop(stack_t **stack , unsigned int line_number);
stack_t *pop(stack_t **stack, unsigned int line_number);
stack_t *add(stack_t **stack, unsigned int line_number);
stack_t *_mul(stack_t **stack, unsigned int line_number);
int main(int argc, char *argv[]);
stack_t *rotl(stack_t **stack, unsigned int line_number);
stack_t *rotr(stack_t **stack, unsigned int line_number);
stack_t *swap(stack_t **stack, unsigned int line_number);
stack_t *pstr(stack_t **stack, unsigned int line_number);
stack_t *pchar(stack_t **stack, unsigned int line_number);
stack_t *mod(stack_t **stack, unsigned int line_number);
stack_t *(*opcode_(char *p, stack_t **stack, unsigned int line_number))(stack_t
									**stack, unsigned int line_number);
#endif

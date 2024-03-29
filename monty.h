#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



void f_push(stack_t **stack, int value);
void f_pall(stack_t **stack, unsigned int line_number);
void find_func(char *opcode, stack_t **stack,
		size_t line_number, FILE *fd, char *line);
void free_stack(stack_t *stack);
void process_file(FILE *fd);
void push_usage_error(size_t line_number,
		FILE *fd, char *line, stack_t **stack);
void unknown_ins(size_t line_number, char *opcode,
		FILE *fd, char *line, stack_t *stack);
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);
void f_add(stack_t **stack, unsigned int line_number);
#endif /*MONTY_H*/

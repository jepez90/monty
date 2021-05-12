#ifndef MONTY
#define MONTY

#define BUFFER_SIZE 512
extern char optcode_arg[];
typedef unsigned int uns;

/*****************************************/
/******* include standart libraries ******/
/*****************************************/
/* include standart libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> /* flags for open file */
#include <string.h> /* strtok */

/*****************************************/
/************ include structs ************/
/*****************************************/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*****************************************/
/*********** include Functions ***********/
/*****************************************/
void execute(stack_t **stack, char *optcode, uns line_number);

void open_file(FILE **file, char **argv);
int read_file(FILE *file, char *optcode);


void push_optcode(stack_t **stack, uns line_number);
void pall_optcode(stack_t **stack, uns line_number);
void pint_optcode(stack_t **stack, uns line_number);
void pop_optcode(stack_t **stack, uns line_number);


size_t stack_print(const stack_t *h, int index);
stack_t *stack_push(stack_t **head, const int n);
int stack_pop(stack_t **head);
void free_stack(stack_t *head);


void copy_buffer(char *origin, char *dest);



#endif

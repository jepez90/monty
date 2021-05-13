#ifndef MONTY
#define MONTY

/*****************************************/
/******* include standart libraries ******/
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> /* flags for open file */
#include <string.h> /* strtok */


/*****************************************/
/************* define macros *************/
/*****************************************/
#define BUFFER_SIZE 512
#define EMPTY_STACK_ERR "L%u: can't %s, stack empty\n"
#define OUT_OF_RANGE_ERR "L%u: can't %s, value out of range\n"
#define SHORT_STACK_ERR "L%u: can't %s, stack too short\n"
#define UNUSED __attribute__((unused))
typedef unsigned int uns;


/*****************************************/
/************* define structs ************/
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


/**
 * struct data_s - opcode and its argument
 * @opcode: the opcode
 * @arg: the argument
 *
 * Description: this struct store info for all program
 */
typedef struct data_s
{
		char opcode[BUFFER_SIZE];
		char arg[BUFFER_SIZE];
} data_t;

extern data_t data;

/*****************************************/
/*********** include Functions ***********/
/*****************************************/

/*------ monty.c ------*/
void execute(stack_t **stack, uns line_number);

/*------ file.c ------*/
void open_file(FILE **file, char **argv);
int read_file(FILE *file);

/*------ handle_optocodes_1.c ------*/
void handle_push(stack_t **stack, uns line_number);
void handle_pall(stack_t **stack, uns line_number);
void handle_pint(stack_t **stack, uns line_number);
void handle_pop(stack_t **stack, uns line_number);
void handle_swap(stack_t **stack, uns line_number);

/*------ handle_optocodes_2.c ------*/
void handle_math(stack_t **stack, uns line_number);
void handle_pchar(stack_t **stack, uns line_number);
void handle_pstr(stack_t **stack, uns line_number);
void handle_rotl(stack_t **stack, uns line_number);

/*------ stack.c ------*/
size_t stack_print(const stack_t *h, int index);
stack_t *stack_push(stack_t **head, const int n);
int stack_pop(stack_t **head);
void stack_free(stack_t *head);
stack_t *stack_get_top(stack_t *head);


#endif

#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

#define NB_FUNCTIONS 17

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct		stack_s
{
	int				n;
	struct stack_s	*prev;
	struct stack_s	*next;
}					stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct		instruction_s
{
	char		*opcode;
	void		(*f)(stack_t **stack, unsigned int line_number);
}					instruction_t;

/**
 * struct instruction_list_s - List of instructions
 * @id: Index of corresponding function
 * @line: Line number for instruction
 * @argument: Argument string
 * @next: Next element in list
 */
typedef struct		instruction_list_s
{
	int							id;
	int							line;
	char						*argument;
	struct instruction_list_s	*next;
}					instruction_list_t;

/**
 * struct data_s - Global struct
 * @stack: Stack list
 * @functions: Functions corresponding to instructions
 * @instructions: List of instructions
 * @is_stack: State to interpret as stack or queue
 */
typedef struct		data_s
{
	stack_t				*stack;
	instruction_t		functions[NB_FUNCTIONS];
	instruction_list_t	*instructions;
	int					is_stack;
}					data_t;

void	_memdel(void **ptr);
int		parse_file(char *filename);
void	add_node(stack_t **stack, unsigned int line_number);
void	print_list(stack_t **stack, unsigned int line_number);
void	print_head(stack_t **stack, unsigned int line_number);
void	delete_head(stack_t **stack, unsigned int line_number);
void	reverse_value(stack_t **stack, unsigned int line_number);
int		initialize_data(void);
void	free_all(void);
int		execute_instructions(void);
void	op_add(stack_t **stack, unsigned int line_number);
void	op_sub(stack_t **stack, unsigned int line_number);
void	op_div(stack_t **stack, unsigned int line_number);
void	op_mul(stack_t **stack, unsigned int line_number);
void	op_mod(stack_t **stack, unsigned int line_number);

void	pchar(stack_t **stack, unsigned int line_number);
void	pstr(stack_t **stack, unsigned int line_number);
void	rotl(stack_t **stack, unsigned int line_number);
void	rotr(stack_t **stack, unsigned int line_number);
void	change_into_stack(stack_t **stack, unsigned int line_number);
void	change_into_queue(stack_t **stack, unsigned int line_number);
int		malloc_perror(int ret);

data_t data;

#endif /* MONTY_H */

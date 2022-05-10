#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define NB_FUNCTIONS 3

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
 * @brief
 *
 */
typedef struct		instruction_list_s
{
	int							id;
	char						*argument;
	struct instruction_list_s	*next;
}					instruction_list_t;

/**
 * @brief
 *
 */
typedef struct		data_s
{
	stack_t				*stack;
	instruction_t		functions[NB_FUNCTIONS];
	instruction_list_t	*instructions;
}					data_t;

void	_memdel(void **ptr);
int		parse_file(data_t *data, char *filename);
void	add_node(stack_t **stack, unsigned int line_number);
void	print_list(stack_t **stack, unsigned int line_number);
void	print_head(stack_t **stack, unsigned int line_number);
void	delete_head(stack_t **stack, unsigned int line_number);
int	initialize_data(data_t *data);

#endif /* __MAIN_H__ */

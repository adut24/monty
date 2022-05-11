#include "main.h"

/**
 * free_functions - Frees function opcode string
 * @functions: Array of function pointers with their opcodes
 */
void	free_functions(instruction_t *functions)
{
	int	i;

	for (i = 0; i < NB_FUNCTIONS; i++)
		_memdel((void **)&functions->opcode);
}

/**
 * free_instructions - Frees list
 * @list: Adress to head of list
 */
void	free_instructions(instruction_list_t **list)
{
	instruction_list_t	*ptr;

	while (*list)
	{
		ptr = *list;
		*list = (*list)->next;
		_memdel((void **)&ptr->argument);
		free(ptr);
	}
}

/**
 * free_stack - Frees stack
 * @stack: Adress of Stack list
 */
void	free_stack(stack_t **stack)
{
	stack_t	*ptr;

	while (*stack)
	{
		ptr = *stack;
		*stack = (*stack)->next;
		free(ptr);
	}
}

/**
 * free_all - Frees everything
 */
void	free_all(void)
{
	free_functions(data.functions);
	free_instructions(&data.instructions);
	free_stack(&data.stack);
}

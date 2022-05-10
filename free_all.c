#include "main.h"

void	free_functions(instruction_t *functions)
{
	int	i;

	for (i = 0; i < NB_FUNCTIONS; i++)
		_memdel((void **)&functions->opcode);
}

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

void	free_all(data_t	*data)
{
	free_functions(data->functions);
	free_instructions(&data->instructions);
	free_stack(&data->stack);
}

#include "main.h"

void	change_into_stack(stack_t **stack, unsigned int line_number)
{
	data.is_stack = 0;
	(void)stack;
	(void)line_number;
}

void	change_into_queue(stack_t **stack, unsigned int line_number)
{
	data.is_stack = 1;
	(void)stack;
	(void)line_number;
}

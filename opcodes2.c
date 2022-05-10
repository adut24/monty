#include "main.h"

void	add(stack_t **stack, unsigned int line_number)
{
	stack_t	*ptr;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	(*stack)->n += ptr->n;
	(*stack)->prev = NULL;
	free(ptr);
}

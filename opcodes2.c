#include "main.h"

/**
 * op_add - add the two top elements of the stack/queue
 * @stack: list to print the head
 * @line_number: number of the line of the command
 */
void	op_add(stack_t **stack, unsigned int line_number)
{
	stack_t	*ptr;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	(*stack)->n += ptr->n;
	(*stack)->prev = NULL;
	free(ptr);
}

/**
 * op_sub - subtract the two top elements of the stack/queue
 * @stack: list to print the head
 * @line_number: number of the line of the command
 */
void	op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t	*ptr;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= ptr->n;
	(*stack)->prev = NULL;
	free(ptr);
}

/**
 * op_div - divide the second top element by the first of the stack/queue
 * @stack: list to print the head
 * @line_number: number of the line of the command
 */
void	op_div(stack_t **stack, unsigned int line_number)
{
	stack_t	*ptr;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->n)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= ptr->n;
	(*stack)->prev = NULL;
	free(ptr);
}

/**
 * op_mul - multiply the two top elements of the stack/queue
 * @stack: list to print the head
 * @line_number: number of the line of the command
 */
void	op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t	*ptr;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= ptr->n;
	(*stack)->prev = NULL;
	free(ptr);
}

/**
 * op_mod - divide the second top element by the first and take the rest
 * @stack: list to print the head
 * @line_number: number of the line of the command
 */
void	op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t	*ptr;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->n)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	(*stack)->n %= ptr->n;
	(*stack)->prev = NULL;
	free(ptr);
}

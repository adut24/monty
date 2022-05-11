#include "monty.h"

/**
 * pchar - Prints top of stack as a char
 * @stack: Adress to top of stack
 * @line_number: Instruction line number in file
 */
void	pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints stack as a string
 * @stack: Adress to top of stack
 * @line_number: Instruction line number in file
 */
void	pstr(stack_t **stack, unsigned int line_number)
{
	stack_t	*ptr;

	(void)line_number;
	ptr = *stack;
	while (ptr && ptr->n > 0 && ptr->n <= 255)
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates stack to the left
 * @stack: Adress to top of stack
 * @line_number: Instruction line number in file
 */
void	rotl(stack_t **stack, unsigned int line_number)
{
	stack_t	*ptr, *tmp;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = tmp;
	tmp->prev = ptr;
	tmp->next = NULL;
}

/**
 * rotr - Rotates stack to the right
 * @stack: Adress to top of stack
 * @line_number: Instruction line number in file
 */
void	rotr(stack_t **stack, unsigned int line_number)
{
	stack_t	*ptr, *tmp;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	ptr = *stack;
	while (ptr->next && ptr->next->next)
		ptr = ptr->next;
	tmp = ptr->next;
	ptr->next = NULL;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}

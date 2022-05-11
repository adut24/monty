#include "main.h"

/**
 * change_into_stack - make the doubly linked list in stack mode
 * @stack: doubly linked list
 * @line_number: number to add to the node
 */
void	change_into_stack(stack_t **stack, unsigned int line_number)
{
	data.is_stack = 0;
	(void)stack;
	(void)line_number;
}

/**
 * change_into_queue - make the doubly linked list in queue mode
 * @stack: doubly linked list
 * @line_number: number to add to the node
 */
void	change_into_queue(stack_t **stack, unsigned int line_number)
{
	data.is_stack = 1;
	(void)stack;
	(void)line_number;
}

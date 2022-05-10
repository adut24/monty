#include "main.h"

/**
 * add_node - add a node at the beginning of a doubly linked list
 * @stack: doubly linked list
 * @line_number: number to add to the node
 */
void	add_node(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!stack || !node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (*stack)
		(*stack)->prev = node;
	else
		node->prev = NULL;
	node->n = line_number;
	node->next = *stack;
	*stack = node;
}

/**
 * print_list - print all the nodes
 * @stack: list to print
 * @line_number: number of the line of the command
 */
void	print_list(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;

	if (*stack)
	{
		cur = *stack;
		while (cur)
		{
			printf("%d\n", cur->n);
			cur = cur->next;
		}
	}
	(void)line_number;
}

/**
 * print_head - print the value at the top of the stack
 * @stack: list to print the head
 * @line_number: number of the line of the command
 */
void	print_head(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * delete_head - delete the top element of the stack
 * @stack: doubly linked list
 * @line_number: number of the line of the command
 */
void	delete_head(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * reverse_value - swap the value of the first 2 nodes
 * @stack: doubly linked list
 * @line_number: number of the line of the command
 */
void	reverse_value(stack_t **stack, unsigned int line_number)
{
	stack_t *cur, *t;
	int tmp;

	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	t = cur->next;
	tmp = t->n;
	t->n = cur->n;
	cur->n = tmp;
}

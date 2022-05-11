#include "monty.h"

/**
 * initialize_data3 - initialize the data structure
 * @i: Array index
 * Return: EXIT_FAILURE or 0 in case of success
 */
int	initialize_data3(int i)
{
	data.functions[i].opcode = strdup("rotl");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = rotl;

	data.functions[i].opcode = strdup("rotr");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = rotr;

	data.functions[i].opcode = strdup("stack");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = change_into_stack;

	data.functions[i].opcode = strdup("queue");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = change_into_queue;
	return (0);
}

/**
 * initialize_data2 - initialize the data structure
 * @i: Array index
 * Return: EXIT_FAILURE or 0 in case of success
 */
int	initialize_data2(int i)
{
	data.functions[i].opcode = strdup("add");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = op_add;

	data.functions[i].opcode = strdup("sub");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = op_sub;

	data.functions[i].opcode = strdup("div");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = op_div;

	data.functions[i].opcode = strdup("mul");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = op_mul;

	data.functions[i].opcode = strdup("mod");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = op_mod;

	data.functions[i].opcode = strdup("pchar");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = pchar;

	data.functions[i].opcode = strdup("pstr");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = pstr;
	return (initialize_data3(i));
}

/**
 * initialize_data - initialize the data structure
 * Return: EXIT_FAILURE or 0 in case of success
 */
int	initialize_data(void)
{
	int i = 0;

	data.stack = NULL;
	data.instructions = NULL;
	data.is_stack = 0;

	data.functions[i].opcode = strdup("push");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = add_node;

	data.functions[i].opcode = strdup("pall");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = print_list;

	data.functions[i].opcode = strdup("pint");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = print_head;

	data.functions[i].opcode = strdup("pop");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = delete_head;

	data.functions[i].opcode = strdup("swap");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = reverse_value;

	data.functions[i].opcode = strdup("nop");
	if (!data.functions[i].opcode)
		return (EXIT_FAILURE);
	data.functions[i++].f = NULL;
	return (initialize_data2(i));
}

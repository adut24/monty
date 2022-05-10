#include "main.h"

/**
 * initialize_data - initialize the data structure
 * @data: pointer to the data_t struct
 * Return: EXIT_FAILURE or 0 in case of success
 */
int	initialize_data(data_t *data)
{
	int i = 0;
	data->stack = NULL;
	data->instructions = NULL;

	data->functions[i].opcode = strdup("push");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = add_node;

	data->functions[i].opcode = strdup("pall");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = print_list;

	data->functions[i].opcode = strdup("pint");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = print_head;

	data->functions[i].opcode = strdup("pop");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = delete_head;

	data->functions[i].opcode = strdup("swap");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = reverse_value;

	data->functions[i].opcode = strdup("nop");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = NULL;

	data->functions[i].opcode = strdup("add");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = op_add;

	data->functions[i].opcode = strdup("sub");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = op_sub;

	data->functions[i].opcode = strdup("div");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = op_div;

	data->functions[i].opcode = strdup("mul");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = op_mul;

	data->functions[i].opcode = strdup("mod");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = op_mod;

	data->functions[i].opcode = strdup("pchar");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = pchar;

	data->functions[i].opcode = strdup("pstr");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = pstr;

	data->functions[i].opcode = strdup("rotl");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = rotl;

	data->functions[i].opcode = strdup("rotr");
	if (!data->functions[i].opcode)
		return (EXIT_FAILURE);
	data->functions[i++].f = rotr;
	return (0);
}

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

	return (0);
}

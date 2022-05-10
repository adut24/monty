#include "main.h"

/**
 * initialize_data - initialize the data structure
 * @data: pointer to the data_t struct
 * Return: EXIT_FAILURE or 0 in case of success
 */
int	initialize_data(data_t *data)
{
	data->stack = NULL;
	data->instructions = NULL;

	data->functions[0].opcode = strdup("push");
	if (!data->functions[0].opcode)
		return (EXIT_FAILURE);
	data->functions[0].f = add_node;

	data->functions[1].opcode = strdup("pall");
	if (!data->functions[1].opcode)
		return (EXIT_FAILURE);
	data->functions[1].f = print_list;

	data->functions[2].opcode = strdup("pint");
	if (!data->functions[2].opcode)
		return (EXIT_FAILURE);
	data->functions[2].f = print_head;

	data->functions[2].opcode = strdup("pop");
	if (!data->functions[2].opcode)
		return (EXIT_FAILURE);
	data->functions[2].f = delete_head;

	data->functions[3].opcode = strdup("swap");
	if (!data->functions[3].opcode)
		return (EXIT_FAILURE);
	data->functions[3].f = reverse_value;

	return (0);
}

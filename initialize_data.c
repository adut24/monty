#include "main.h"

/**
 * initialize_data - initialize the data structure
 */
void	initialize_data(data_t *data)
{
	data->stack = NULL;
	data->instructions = NULL;

	data->functions[0].opcode = strdup("push");
	if (!data->functions[0].opcode)
		exit(EXIT_FAILURE);
	data->functions[0].f = add_node;

	data->functions[1].opcode = strdup("pall");
	if (!data->functions[1].opcode)
		exit(EXIT_FAILURE);
	data->functions[1].f = print_list;

	data->functions[2].opcode = strdup("pint");
	if (!data->functions[2].opcode)
		exit(EXIT_FAILURE);
	data->functions[2].f = print_head;
}

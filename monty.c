#include "main.h"

int	execute_instructions(data_t *data)
{
	instruction_list_t	*ptr;

	ptr = data->instructions;
	while (ptr)
	{
/* 		printf("%s:", data->functions[ptr->id].opcode);
		if (ptr->argument)
			printf("%c", ptr->argument[0]);
		printf("\n"); */
		if (ptr->id == 0)
		{
			if (!ptr->argument
			|| ptr->argument[0] < '0' || ptr->argument[0] > '9')
			{
				dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ptr->line);
				return (1);
			}
			data->functions[ptr->id].f(&data->stack, atoi(ptr->argument));
		}
		else
			data->functions[ptr->id].f(&data->stack, ptr->line);
		ptr = ptr->next;
	}
	return (0);
}

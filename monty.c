#include "monty.h"

/**
 * execute_instructions - execute the command
 * Return: 0 for success or 1 for failure
 */
int	execute_instructions(void)
{
	instruction_list_t	*ptr;

	ptr = data.instructions;
	while (ptr)
	{
		if (ptr->id == 0)
		{
			if (!ptr->argument
			|| ptr->argument[0] < '0' || ptr->argument[0] > '9')
			{
				dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ptr->line);
				return (1);
			}
			data.functions[ptr->id].f(&data.stack, atoi(ptr->argument));
		}
		else if (data.functions[ptr->id].f)
			data.functions[ptr->id].f(&data.stack, ptr->line);
		ptr = ptr->next;
	}
	return (0);
}

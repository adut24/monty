#include "main.h"

/**
 * free_list - Frees list
 * @list: Pointer to list
 */
void	free_list(instruction_list_t	*list)
{
	instruction_list_t	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

/**
 * check_instruction - Checks if the instruction exists
 * @data: Pointer to data structure
 * @content: Instruction
 * Return: Id to instruction function, -1 if error
 */
int		check_instruction(data_t *data, char *content)
{
	int	i;

	for (i = 0; data->functions[i].f; i++)
	{
		if (!strcmp(data->functions[i].opcode, content))
			return (i);
	}
	return (-1);
}

/**
 * add_instruction - Adds new instructions to list
 * @data: Pointer to data structure
 * @head: Adress to head of list
 * @content: Instruction
 * @line_num: Line in file
 * Return: 0 if Success, else Error
 */
int		add_instruction(data_t *data, instruction_list_t **head, char *content,
						int line_num)
{
	instruction_list_t	*new, *ptr;
	int					instr_id;
	char				*arg;

	if (!content || !strlen(content))
		return (0);
	instr_id = check_instruction(data, content);
	if (instr_id == -1)
	{
		return (dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_num,
		content));
	}
	new = (instruction_list_t *)calloc(1, sizeof(*new));
	if (!new)
		return (1);
	new->id = instr_id;
	new->next = NULL;
	arg = strtok(NULL, " ");
	new->argument = NULL;
	if (arg && strlen(arg) > 0)
	{
		new->argument = strdup(arg);
		if (!new->argument)
			return (1);
	}
	if (*head)
	{
		ptr = *head;
		while (ptr && ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*head = new;
	return (0);
}

/**
 * parse_file - Parses file
 * @data: Pointer to data structure
 * @filename: Path of file
 * Return: 0 if Success, else Error
 */
int		parse_file(data_t *data, char *filename)
{
	FILE				*stream;
	char				*line, *instruction;
	instruction_list_t	*list;
	size_t				len;
	int					ret, line_num = 0;

	stream = fopen(filename, "r");
	if (stream == NULL)
		return (dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
		filename));
	while ((ret = getline(&line, &len, stream)) > 0)
	{
		instruction = strtok(line, " ");
		if (!add_instruction(data, &list, instruction, line_num))
		{
			free_list(list);
			_memdel((void**)&line);
			return (0);
		}
		_memdel((void**)&line);
		line_num++;
	}
	_memdel((void**)&line);
	return (1);
}

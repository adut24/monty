#include "monty.h"

/**
 * check_instruction - Checks if the instruction exists
 * @content: Instruction
 * Return: Id to instruction function, -1 if error
 */
int		check_instruction(char *content)
{
	int	i;

	for (i = 0; i < NB_FUNCTIONS; i++)
	{
		if (!strcmp(data.functions[i].opcode, content))
			return (i);
	}
	return (-1);
}

/**
 * add_instruction - Adds new instructions to list
 * @head: Adress to head of list
 * @content: Instruction
 * @line_num: Line in file
 * Return: 0 if Success, else Error
 */
int		add_instruction(instruction_list_t **head, char *content,
						int line_num)
{
	instruction_list_t	*new, *ptr;
	int					instr_id;
	char				*arg;

	if (!content || !strlen(content) || *content == '#')
		return (0);
	arg = strtok(NULL, " ");
	content = strtok(content, "#");
	instr_id = check_instruction(content);
	if (instr_id == -1)
	{
		return (dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
		line_num, content));
	}
	new = (instruction_list_t *)malloc(sizeof(*new));
	if (!new)
		return (malloc_perror(1));
	bzero((void *)new, sizeof(*new));
	new->line = line_num;
	new->id = instr_id;
	new->next = NULL;
	new->argument = NULL;
	if (arg && strlen(arg) > 0)
	{
		new->argument = strdup(arg);
		if (!new->argument)
			free(new);
		if (!new->argument)
			return (malloc_perror(1));
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
 * @filename: Path of file
 * Return: 0 if Success, else Error
 */
int		parse_file(char *filename)
{
	FILE				*stream;
	char				*line = NULL, *instruction;
	size_t				len = 0;
	int					ret, line_num = 1;

	stream = fopen(filename, "r");
	if (stream == NULL)
		return (dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
		filename));
	while ((ret = getline(&line, &len, stream)) > 0)
	{
		line[ret] = '\0';
		instruction = strtok(line, " \n");
		if (add_instruction(&data.instructions, instruction, line_num))
		{
			fclose(stream);
			_memdel((void **)&line);
			return (1);
		}
		_memdel((void **)&line);
		line_num++;
	}
	fclose(stream);
	_memdel((void **)&line);
	return (0);
}

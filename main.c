#include "main.h"

data_t	data;
/**
 * main - Entry point
 * @ac: number of arguments passed to the program
 * @av: array of arguments
 * Return: 0 or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if(initialize_data() != 0)
		return (EXIT_FAILURE);
	if (parse_file(av[1]) != 0)
	{
		free_all();
		return(EXIT_FAILURE);
	}
	if (execute_instructions())
	{
		free_all();
		return(EXIT_FAILURE);
	}
	free_all();
	return (0);
}

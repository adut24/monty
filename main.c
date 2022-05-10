#include "main.h"

/**
 * main - Entry point
 * @ac: number of arguments passed to the program
 * @av: array of arguments
 * Return: 0 or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	data_t data;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if(initialize_data(&data) != 0)
		return (EXIT_FAILURE);
	if (parse_file(&data, av[1]) != 0)
	{
		free_all(&data);
		return(EXIT_FAILURE);
	}

	free_all(&data);
	return (0);
}

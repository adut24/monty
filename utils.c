#include "monty.h"

/**
 * _memdel - Frees pointer and sets its value to NULL
 * @ptr: Address of pointer to free
 */
void	_memdel(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * malloc_perror - Prints error when malloc fails
 * @ret: Value to return
 * Return: @ret
 */
int		malloc_perror(int ret)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (ret);
}

/**
 * is_number - Checks if string is a number
 * @s: String
 * Return: 1 if it's a number, 0 if not
 */
int		is_number(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

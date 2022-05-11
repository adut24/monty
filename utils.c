#include "main.h"

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
	dprintf(STDERR_FILENO, "Error: malloc failed\n");
	return (ret);
}

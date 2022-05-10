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

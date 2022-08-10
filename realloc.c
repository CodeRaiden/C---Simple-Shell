#include "main.h"

/**
 * _realloc - reallocates a memory block by using malloc and free
 * @ptr: input pointer
 * @old_size: the size of old ptr
 * @new_size: the size of new ptr
 * Return: the reallocated ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *res = NULL;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
	{
		free(ptr);
		res = malloc(new_size);
		if (!res)
		{
			perror("Malloc failed");
			exit(errno);
		}
		return (res);
	}
	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	res = malloc(new_size);
	if (!res)
	{
		perror("Malloc failed");
		exit(errno);
	}
	_memcpy(res, ptr, old_size);
	free(ptr);
	return (res);
}

/**
 * _memcpy - copies the memory area
 * @dest: the destination string
 * @src: the source string
 * @n: the number of bytes to be copied
 * Return: the pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ptr = dest;

	while (n--)
		*dest++ = *src++;
	return (ptr);
}



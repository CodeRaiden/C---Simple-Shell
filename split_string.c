#include "main.h"

/**
 * splitString - splits the string into an array of strings
 * separated by spaces
 * @build: the input build
 * Return: 1 if able to split, 0 if not
 */
int splitString(config *build)
{
	register unsigned int i = 0;
	char *tok, *cpy;

	if (countWords(build->buffer) == 0)
	{
		build->args = NULL;
		free(build->buffer);
		return (0);
	}
	build->args = malloc((countWords(build->buffer) + 1) * sizeof(char *));
	cpy = _strdup(build->buffer);
	tok = _strtok(cpy, " ");
	while (tok)
	{
		build->args[i] = _strdup(tok);
		tok = _strtok(NULL, " ");
		i++;
	}
	build->args[i] = NULL;
	free(cpy);
	return (1);
}

/**
 * countWords - count number of words in string
 * @str: the input string
 * Return: the number of words
 */
unsigned int countWords(char *str)
{
	register int words = 0;
	int wordOn = 0;

	while (*str)
	{
		if (isSpace(*str) && wordOn)
			wordOn = 0;
		else if (!isSpace(*str) && !wordOn)
		{
			wordOn = 1;
			words++;
		}
		str++;
	}
	return (words);
}

/**
 * isSpace - determines if char is a space
 * @c: input char
 * Return: 1 on success, 0 on failure.
 */
int isSpace(char c)
{
	return (c == ' ');
}



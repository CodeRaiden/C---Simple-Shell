#include "main.h"

/**
 * insertNullByte - inserts null byte at the given index
 * @str: input string
 * @index: the index to insert null the byte
 */
void insertNullByte(char *str, unsigned int index)
{
	str[index] = '\0';
}

/**
 * displayPrompt - displays shell prompt
 */
void displayPrompt(void)
{
	write(STDERR_FILENO, "$ ", 2);
}

/**
 * displayNewLine - displays new line
 */
void displayNewLine(void)
{
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * sigintHandler - catches SIGINT signal and reset signal
 * @sigint: the signal from stdint
 */
void sigintHandler(int sigint)
{
	(void)sigint;
	signal(SIGINT, sigintHandler);
	displayNewLine();
	displayPrompt();
	fflush(stdout);
}



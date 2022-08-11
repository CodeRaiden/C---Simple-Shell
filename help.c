#include "main.h"

/**
 * helpFunc - retrieves instruction on the use of builtin
 * @build: input build
 * Return: Always 1
 */
int helpFunc(config *build)
{
	type_b help_arr[] = {
		{"exit", helpExit},
		{"env", helpEnv},
		{"history", helpHistory},
		{"alias", helpAlias},
		{"cd", helpCd},
		{"setenv", helpSetenv},
		{"unsetenv", helpUnsetenv},
		{"help", helpHelp},
		{NULL, NULL}
	};
	register int i = 0, j = 1, argCount = countArgs(build->args);
	int foundCommand = 0;

	if (argCount == 1)
		return (displayHelpMenu());
	while (j < argCount)
	{
		i = 0;
		while (help_arr[i].command)
		{
			if (_strcmp(build->args[j], help_arr[i].command) == 0)
			{
				foundCommand = 1;
				help_arr[i].func(build);
				break;
			}
			i++;
		}
		j++;
	}
	if (foundCommand == 0)
	{
		errno = ENOBUILTIN;
		errorHandler(build);
	}
	return (1);
}

/**
 * displayHelpMenu - displays help options available
 * Return: Always 1
 */
int displayHelpMenu(void)
{
	char str[81] = "Type help [built-in]\n\nIncluded built-ins:";
	char *str2 = "\n\n\texit\n\tenv\n\tcd\n\tsetenv\n\tunsetenv\n\thelp\n";

	_strcat(str, str2);
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}


/**
 * helpExit - the instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpExit(config *build)
{
	char str[82] = "exit: exit [n]\n\tExit the shell.\n\n\t";
	char *str2 = "Exit with a status of n, or if n is omitted, 0.\n";

	(void)build;
	_strcat(str, str2);
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * helpEnv - the instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpEnv(config *build)
{
	char str[] = "env: env\n\tPrint the environment.\n";

	(void)build;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * helpHistory - the instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpHistory(config *build)
{
	char str[] = "history: history\n\tNot supported in this version.\n";

	(void)build;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

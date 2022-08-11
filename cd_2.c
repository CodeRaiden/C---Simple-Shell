#include "main.h"

/**
 * cdFunc - execute cd builtin
 * @build: inpuy build.
 * Return: 1 oon success, 0 on failure.
 */
int cdFunc(config *build)
{
	register uint count = 0;
	int ableToChange = 0;

	count = countArgs(build->args);
	if (count == 1)
		ableToChange = cdToHome(build);
	else if (count == 2 && _strcmp(build->args[1], "-") == 0)
		ableToChange = cdToPrevious(build);
	else
		ableToChange = cdToCustom(build);

	if (ableToChange)
		updateEnviron(build);
	return (1);
}

/**
 * cdToHome - move to home directory.
 * @build: input build.
 * Return: 1 on success, 0 on failure.
 */
int cdToHome(config *build)
{
	register int i;
	char *str, *ptr;

	i = searchNode(build->env, "HOME");
	if (i == -1)
		return (1);

	str = getNodeAtIndex(build->env, i);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	free(str);
	return (1);
}

/**
 * cdToPrevious - move to previous directory.
 * @build: input build.
 * Return: 1 on success, 0 on failure.
 */
int cdToPrevious(config *build)
{
	register int i;
	char *str, *ptr;
	char *current = NULL;

	current = getcwd(current, 0);
	i = searchNode(build->env, "OLDPWD");
	if (i == -1)
	{
		chdir(current);
		write(STDOUT_FILENO, current, _strlen(current));
		displayNewLine();
		return (1);
	}
	str = getNodeAtIndex(build->env, i);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	write(STDOUT_FILENO, ptr, _strlen(ptr));
	displayNewLine();
	free(str);
	return (1);
}

/**
 * cdToCustom - move to user input directory.
 * @build: input build.
 * Return: 1 on success, 0 on failure.
 */
int cdToCustom(config *build)
{
	register int changeStatus;

	changeStatus = chdir(build->args[1]);
	if (changeStatus == -1)
	{
		errno = EBADCD;
		errorHandler(build);
		return (0);
	}
	return (1);
}

/**
 * updateEnviron - updates enviromental variables.
 * @build: input build.
 * Return: 1 on success, 0 on failure.
 */
int updateEnviron(config *build)
{
	register int i;

	i = updateOld(build);
	updateCur(build, i);
	return (1);
}

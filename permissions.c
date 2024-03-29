#include "commands.h"
#include "general.h"

/**
 * is_executable :- A function that Check if a filename have
 *	a permissions for run or not.
 * @filename: A Filename to be checked.
 * Return: On success, PERMISSIONS;
 * On error, NON_PERMISSIONS
 ***/
int is_executable(char *filename)
{
	struct stat stats;

	if (stat(filename, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}

/**
 * is_file :- This functiont for Check if is a file or binary.
 * Description: Lool for excute permissions and if is a file.
 * @file: A File to check.
 * Return: If is a file with the correct permissions, PERMISSIONS
 * If is a file but not have permissions or doesn't exists, NON_PERMISSIONS
 * If is not a file, NON_FILE.
 ***/
int is_file(char *file)
{
	int i, size;

	size = _strlen(file);
	for (i = 0; i < size; i++)
		if (file[i] == '/')
			return (is_executable(file));

	return (NON_FILE);
}

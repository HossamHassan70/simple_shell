#include "commands.h"
#include "general.h"
#include "text.h"
#include <string.h>
#include <sys/cdefs.h>
#include <unistd.h>

/**
 * _getenv :- A function which is used to retrieve the value
 *	of an environment variable.
 * @name: An environment variable to get.
 * Return: On success value of @name.
 * On error, NULL
 ***/
char *_getenv(const char *name)
{
	char **env;
	char *aux, *token, *value;
	int size;

	size = _strlen((char *) name);

	for (env = environ; *env; ++env)
	{
		aux = _strdup(*env);

		token = strtok(aux, "=");
		if (token == NULL)
		{
			free(aux);
			return (NULL);
		}

		if (_strlen(token) != size)
		{
			free(aux);
			continue;
		}

		if (_strcmp((char *) name, aux) == 0)
		{
			token = strtok(NULL, "=");
			value = _strdup(token);

			free(aux);
			return (value);
		}

		free(aux);
	}

	return (NULL);
}

/**
 * which :-It used to search for the location of an executable
 *	file in the system's PATH environment variable.
 * @filename: The name of the file (Command received).
 * @info: It is a general info about the shell.
 * Return: A pointer string with found path or NULL in failure.
 ***/
char *which(char *filename, general_t *info)
{
	char *path, *tmp_path, *token;
	char *slash;
	int size;

	(void) info;
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	size = snprintf(NULL, 0, "/%s", filename) + 1;
	slash = malloc(size * sizeof(char));
	snprintf(slash, size, "/%s", filename);

	token = strtok(path, ":");
	while (token != NULL)
	{
		size = snprintf(NULL, 0, "%s/%s", token, filename) + 1;
		tmp_path = malloc(size * sizeof(char));
		snprintf(tmp_path, size, "%s/%s", token, filename);

		if (is_executable(tmp_path) == PERMISSIONS)
		{
			free(slash);
			free(path);

			return (tmp_path);
		}
		token = strtok(NULL, ":");
		free(tmp_path);
	}

	free(path);
	free(slash);

	return (NULL);
}

/**
 * is_current_path :- This function checks if a given path
 *	string represents the current directory.
 * @path: A PATH to check.
 * @info: General infor about the shell.
 * Return: Void.
 ***/
void is_current_path(char *path, general_t *info)
{
	info->is_current_path = _FALSE;

	if (path == NULL)
		return;

	if (path[0] == ':')
		info->is_current_path = _TRUE;
}

/**
 * get_full_env :- A function to get all the environment.
 * Return: Void.
 ***/
void get_full_env(void)
{
	char **tmp;
	int i;

	for (i = 0, tmp = environ; tmp[i] != NULL; i++)
	{
		print(tmp[i]);
		_putchar('\n');
	}
}
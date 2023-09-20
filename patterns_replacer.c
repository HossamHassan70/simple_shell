#include "general.h"
#include "text.h"
#include "commands.h"

/**
 * replacement :- A function that make replacement.
 * @info: A general info about shell.
 * @index: An input.
 * @string: An input string.
 * Return: The value of string (tmp).
***/

char *replacement(general_t *info, int *index, char *string)
{
	char *tmp;
	char symbol = *string;

	(void) index;

	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}

/**
 * replace_env - An Entry Point to replacement environment.
 * @info: A general info.
 * @environment: An input characters.
 * Return: A value of string or NULL if fail.
***/

char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}

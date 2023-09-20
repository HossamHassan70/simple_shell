#include "commands.h"
#include "general.h"
#include "memory.h"
#include "text.h"

/**
 * analyze_patterns :- An Entry Point to analyze pattern.
 * @info: An input.
 * @arguments: The input argument that pass to function.
 * Return: Void
***/

void analyze_patterns(general_t *info, char **arguments)
{
	int i;

	for (i = 0; arguments[i] != NULL; i++)
		arguments[i] = pattern_handler(info, arguments[i]);
}

/**
 * pattern_handler :- An Entry Point to handle pattern.
 * @info: An input.
 * @string: A string input.
 * Return: A string after handling.
***/

char *pattern_handler(general_t *info, char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '$' && string[i + 1] != '\0')
			string = replace_value(info, &i, string);
	}

	return (string);
}

/**
 * replace_value :- The function is responsible for replacing
 *	a specific value in a string with a new value.
 * @info: An input.
 * @index: A pointer to an integer.
 * @string: A pointer to a character.
 * Return: The modified (string).
***/
char *replace_value(general_t *info, int *index, char *string)
{
	int i, new_s, old_s;
	char *value;

	i = *index + 1;

	value = replacement(info, index, string + i);
	if (value == NULL)
	{
		string = _strcpy(string, "");

		return (string);
		;
	}

	old_s = _strlen(string);
	new_s = _strlen(value) + 1;

	string = _realloc(string, old_s, new_s);
	string = _strcpy(string, value);

	free_memory_p(value);
	*index = i;
	return (string);
}

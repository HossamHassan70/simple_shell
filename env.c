#include "builtins.h"

/**
 * bin_env :- An Implementation for the environment builtin.
 * @info: General information about the shell
 * @arguments: Command
 * Return: Void.
 ***/
void bin_env(general_t *info, char **arguments)
{
	(void) info;
	(void) arguments;

	get_full_env();
}

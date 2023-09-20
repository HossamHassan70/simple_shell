#include "builtins.h"
#include "general.h"

/**
 * bin_exit :- An Implementation of the exit builtin.
 * Description: Free all the memory used and exit with
 *	the last status_code.
 * @info: The information about the shell.
 * @arguments: Arguments received and pass to function.
 * Return: Void.
 ***/
void bin_exit(general_t *info, char **arguments)
{
	int status_code, status;

	status = _TRUE;
	if (arguments[1] != NULL)
		status = number_controller(info, arguments[1]);

	if (status == _FALSE)
		return;

	status_code = info->status_code;

	free_memory_pp((void **) arguments);
	free_memory_p((void *) info->buffer);
	free_memory_p((void *) info->environment);
	free_memory_p((void *) info);

	exit(status_code);
}

/**
 * number_controller - This function to make control the
 * argument of exit.
 * @info: An General information about the shell.
 * @number: The number of argument of the builtin.
 * Return: If the actual argument is valid, return (TRUE)
 * if not, return (FALSE).
 ***/
int number_controller(general_t *info, char *number)
{
	int _number;

	_number = _atoi(number);

	if (_number < 0 || contains_letter(number))
	{
		info->status_code = 2;
		info->error_code = _CODE_ILLEGAL_NUMBER;
		error_extra(info, number);
		return (_FALSE);
	}

	if (_number > 255)
		info->status_code = _number % 256;
	else
		info->status_code = _number;

	return (_TRUE);
}


#include "commands.h"
#include "builtins.h"
#include "general.h"
#include "memory.h"
#include "text.h"

/**
 * analyze - The function is responsible for analyzing and
 *	executing a command based on the given arguments.
 * @arguments: Commands and arguments to execute.
 * @info: An General information about the shell.
 * @buff: The line readed.
 * Return: Void.
 ***/
void analyze(char **arguments, general_t *info, char *buff)
{
	char *cmd = arguments[0];
	int status = is_file(cmd);
	char *value_path = which(cmd, info);

	if (arguments == NULL || *arguments == NULL)
		return;

	info->command = cmd;

	if (check_builtin(info, arguments) == _TRUE)
		return;

	if (status == NON_PERMISSIONS)
	{
		info->status_code = 126;
		info->error_code = _CODE_EACCES;
		error(info);
		return;
	}
	if (status == 1)
	{
		execute(cmd, arguments, info, buff);
		return;
	}
	if (current_directory(cmd, arguments, buff, info) == _TRUE)
		return;

	if (value_path != NULL)
	{
		execute(value_path, arguments, info, buff);
		free_memory_p((void *)value_path);
		return;
		}
/* Error handling for command not found */
	info->status_code = 127;
	info->error_code = _CODE_CMD_NOT_EXISTS;
	error(info);
}

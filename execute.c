#include "commands.h"
#include "general.h"
#include "memory.h"

/**
 * execute :- The function is responsible for executing a command
 *	with arguments using the execve system call.
 * @command: A Command to execute.
 * @arguments: The arguments of the (command).
 * @info: A General info about the shell.
 * @buff: A Line that readed.
 * Return: Void
 ***/
void execute(char *command, char **arguments, general_t *info, char *buff)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execvp(command, arguments);
		perror("./sh");

		free_memory_pp((void **)arguments);
		free(info->value_path);
		free(info);
		free(buff);

		exit(1);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
			info->status_code = WEXITSTATUS(status);
	}
}

/**
 * current_directory :- This function represent an execute the
 *	command if the order require.
 * @cmd: A Command to execute.
 * @arguments: Arguments of the (cmd).
 * @buff: A Line that readed.
 * @info: A General info about the shell.
 * Return: A Status of the operations.
 ***/
int current_directory(char *cmd, char **arguments, char *buff, general_t *info)
{
	if (info->is_current_path == _FALSE)
		return (_FALSE);

	if (is_executable(cmd) == PERMISSIONS)
	{
		execute(cmd, arguments, info, buff);
		return (_TRUE);
	}

	return (_FALSE);
}


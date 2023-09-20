#include "text.h"
#include "commands.h"
#include "general.h"
#include "memory.h"

/**
 * prompt :- A function to Print the prompt sign.
 * @info: A Struct of general information.
 * Return: Void.
 ***/
void prompt(general_t *info)
{
	if (info->mode == NON_INTERACTIVE)
		return;

	print("$ ");
}

/**
 * read_prompt :- This for Read lines in the prompt.
 *
 * Return: The Buffer That readed or NULL if EOF was found.
 ***/
char *read_prompt()
{
	char *buf;
	int res;
	size_t size;

	buf = NULL;

	res = getline(&buf, &size, stdin);

	if (res == EOF)
	{
		free_memory_p((void *) buf);
		return (NULL);
	}

	return (buf);
}

/**
 * start_prompt :- A function that runs a prompt loop
 *	to reading text.
 * @info: A Struct of general information.
 * Return: Buffer readed or NULL if EOF was found.
 ***/
void start_prompt(general_t *info)
{
	char *buff;
	char **arguments;
	char *path;

	signal(SIGINT, sigintHandler);
	do {
		prompt(info);

		path = _getenv("PATH");
		is_current_path(path, info);

		info->environment = path;
		buff = read_prompt();
		if (buff == NULL)
		{
			print(info->mode == INTERACTIVE ? "exit\n" : "");
			break;
		}

		info->n_commands++;
		if (buff[0] != '\n')
		{
			arguments = split_words(buff, " \t\n");

			info->arguments = arguments;
			info->buffer = buff;
			analyze_patterns(info, arguments);
			analyze(arguments, info, buff);

			free_memory_pp((void *)arguments);
		}

		free_memory_p((void *)buff);
		free_memory_p((void *)path);
	} while (1);
}

/**
 * sigintHandler - A function that Handle SIGINT.
 * @sig_num: Unused parameter
 * Return: Void.
 ***/
void sigintHandler(int sig_num)
{
	(void) sig_num;

	signal(SIGINT, sigintHandler);
	print("\n$ ");
	fflush(stdout);
}

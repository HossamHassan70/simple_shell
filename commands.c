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
    char *cmd;
    int status;

    if (*arguments == NULL || arguments == NULL)
        return;

    cmd = arguments[0];
    info->command = cmd;
    if (check_builtin(info, arguments) == _TRUE)
        return;

    status = is_file(cmd);
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

    info->value_path = which(cmd, info);
    if (info->value_path != NULL)
    {
        execute(info->value_path, arguments, info, buff);
        
        /* Free dynamically allocated memory before returning */
        free_memory_p((void *)info->value_path);
        info->value_path = NULL; /* Set to NULL to avoid double freeing */
    
        return;
    }

    info->status_code = 127;
    info->error_code = _CODE_CMD_NOT_EXISTS;
    error(info);

    /* Free dynamically allocated memory before returning */
    free_memory_p((void *)info->value_path);
}

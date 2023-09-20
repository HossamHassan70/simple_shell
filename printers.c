#include "general.h"
#include "text.h"
#include <unistd.h>

/**
 * _putchar_to_fd :- This function to Print a character to
 *	a specific file descriptor.
 * @c: A character to print.
 * @fd: The place to print the character.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 ***/
int _putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * print_to_fd :- This function to Print a string.
 * @msg: A Strin to print in the specified.
 * @fd: A File descriptor to print.
 * Return: On success numbers of bytes printed.
 * On error, -1 is returned, and errno is set appropriately.
 ***/
int print_to_fd(char *msg, int fd)
{
	int size = _strlen(msg);

	return (write(fd, msg, size));
}

#include "text.h"

/**
 * print_err :- Function for print a message to STDERR.
 * @msg: A message to print.
 * Return: Number of bytes printed.
 ***/
int print_err(char *msg)
{
	return (print_to_fd(msg, STDERR));
}

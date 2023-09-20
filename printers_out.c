#include "general.h"
#include "text.h"

/**
 * _putchar - A function to Print a character to STDOUT.
 * @c: A character to print.
 * Return: On success (1), On error (-1).
 ***/
int _putchar(char c)
{
	return (write(STDOUT, &c, 1));
}

/**
 * print - This function for Printing a message to STDOUT.
 * @msg: A message to print.
 * Return: On success number of bytes printed,
 * On errror (-1), and set the error.
 ***/
int print(char *msg)
{
	return (print_to_fd(msg, STDOUT));
}

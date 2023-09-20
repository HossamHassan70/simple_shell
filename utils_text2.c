#include "general.h"
#include "text.h"

/**
 * digits :- A function that Cout the number of digits of a number.
 * @n: The number be counted.
 * Return: The digits.
 ***/
int digits(int n)
{
	int i;

	for (i = 0; n != 0; i++, n /= 10)
		;

	return (i);
}

/**
 * to_string :- The function takes an integer number and converts
 *	it into a string.
 * @number: A number to convert.
 * Return: Value number as string.
 ***/
char *to_string(int number)
{
	int n_digits, i;
	char *_number;

	n_digits = digits(number);
	_number = malloc(n_digits * sizeof(char) + 2);
	if (number == 0)
	{
		_number[0] = '0';
		_number[1] = '\0';
		return (_number);
	}
	/* Check NULL */
	_number[n_digits] = '\0';
	for (i = n_digits - 1; number != 0; number /= 10, i--)
		_number[i] = (number % 10) + '0';

	return (_number);
}

/**
 * is_numerical :- A function that Check if is a digit.
 * @n: A Number.
 * Return: If is a number, return (1) else return (0).
 ***/
int is_numerical(unsigned int n)
{
	return (n >= '0' && n <= '9');
}

/**
 * _atoi :- A function that convert a string to a number.
 * @s: A string to convert.
 * Return: Return the number after check.
 ***/

int _atoi(char *s)
{
	int number = 0;
	bool is_negative = false;

/* Check if the string starts with a negative sign */
	if (*s == '-')
	{
		is_negative = true;
		s++;
	}
/* Iterate through each character of the string */
	while (*s != '\0')
	{
/* Check if the character is a digit */
		if (*s >= '0' && *s <= '9')
		{
			int digit = *s - '0';

			number = number * 10 + digit;
		}
		else
			break;
/* Stop iterating if a non-digit character is encountered */
	s++;	/* Move to the next character */
	}

/* Apply the sign to the number if it was negative */
	if (is_negative)
		number *= -1;

	return (number);
}

/**
 * contains_letter - A function that Search non-digits in a string.
 * @s: A String for search.
 * Return: If a non-digits was found, return _TRUE
 * if not, return _FALSE.
 ***/
int contains_letter(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}

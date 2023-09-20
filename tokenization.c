#include "text.h"

/**
 * split_words :- The function takes a string and a separator
 *	string, and splits the @line into individual words
 *	based on the separator.
 * @line: A Line to splits.
 * @sep: A Delimiters for split the words.
 * Return: An array of strings, set of words.
 ***/
char **split_words(char *line, const char *sep)
{
	char **words = NULL;
	char **tmp, *token;
	size_t new_size = 0;

	token = strtok(line, sep);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;

		tmp = realloc(words, (new_size + 2) * sizeof(char *));
		if (tmp == NULL)
			break;

		words = tmp;

		words[new_size] = malloc(strlen(token) + 1);
		if (words[new_size] == NULL)
		{
			free_memory_pp((void **)words);
			break;
		}

		strcpy(words[new_size], token);
		words[++new_size] = NULL;

		token = strtok(NULL, sep);
		}

	return (words);
}

/**
 * join_words - A function that make Join 3 words with a separator.
 * Description: Result -> w1.sep.w2.sep.nl
 * @word1: First Word to join.
 * @word2: Secound Word to join.
 * @word3: Third Word to join.
 * @sep: Separator between the words.
 * Return: The Line composed by 3 parts followed by a separator
 *	and end by a new line.
 ***/
char *join_words(char *word1, char *word2, char *word3, const char *sep)
{
	char *aux;
	int size_str1, size_str2, size_str3, size_sep;

	size_str1 = size_str2 = size_sep = 0;

	if (word1 != NULL)
		size_str1 = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		size_str2 = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		size_str3 = _strlen(word3);
	else
		word3 = "";

	if (sep != NULL)
		size_sep = _strlen((char *)sep);
	else
		sep = "";

	aux = malloc(size_str1 + size_str2 + size_sep + size_str3 + size_sep + 2);
	if (aux == NULL)
		return (NULL);

	aux = _strcpy(aux, word1);
	aux = _strcat(aux, (char *)sep);
	aux = _strcat(aux, word2);
	aux = _strcat(aux, (char *)sep);
	aux = _strcat(aux, word3);
	aux = _strcat(aux, "\n");

	return (aux);
}

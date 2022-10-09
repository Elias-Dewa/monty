#include "monty.h"

/**
 * isnum - whether a string is number or not
 * @str: input string
 *
 * REturn: 1 if str is number, otherwise 0
 */
int isnum(char *str)
{
	unsigned int i;

	if (!str)
		return (0);
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

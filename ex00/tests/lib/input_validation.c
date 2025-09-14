#include "lib_header.h"

int validate_input(char *str)
{
	int i;
	int count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] >= '1' && str[i] <= '4')
		{
			count++;
			i++;
			if (str[i] && str[i] != ' ')
				return (0);
		}
		else if (str[i])
			return (0);
	}
	return (count == 16);
}

int parse_constraints(char *str, int *constraints)
{
	int i;
	int j;

	if (!str || !constraints)
		return (0);
	i = 0;
	j = 0;
	while (str[i] && j < 16)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] >= '1' && str[i] <= '4')
		{
			constraints[j] = str[i] - '0';
			j++;
			i++;
		}
		else if (str[i])
			return (0);
	}
	return (j == 16);
}

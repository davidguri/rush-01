#include "main.h"

static void skip_spaces(char *str, int *i)
{
  while (str[*i] == ' ')
    (*i)++;
}

static int is_1_to_4(char c)
{
  return (c >= '1' && c <= '4');
}

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
    skip_spaces(str, &i);
    if (is_1_to_4(str[i]))
    {
      count++;
      i++;
      if (str[i] && str[i] != ' ')
        return (0);
    }
    else if (str[i])
    {
      return (0);
    }
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
    skip_spaces(str, &i);
    if (is_1_to_4(str[i]))
    {
      constraints[j] = str[i] - '0';
      j++;
      i++;
    }
    else if (str[i])
    {
      return (0);
    }
  }
  return (j == 16);
}

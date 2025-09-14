#include "main.h"

int count_visible_from_left(int *row)
{
  int count;
  int max_height;
  int i;

  count = 0;
  max_height = 0;
  i = 0;
  while (i < 4)
  {
    if (row[i] > max_height)
    {
      max_height = row[i];
      count++;
    }
    i++;
  }
  return (count);
}

int count_visible_from_right(int *row)
{
  int count;
  int max_height;
  int i;

  count = 0;
  max_height = 0;
  i = 3;
  while (i >= 0)
  {
    if (row[i] > max_height)
    {
      max_height = row[i];
      count++;
    }
    i--;
  }
  return (count);
}

int count_visible_from_top(int grid[4][4], int col)
{
  int count;
  int max_height;
  int i;

  count = 0;
  max_height = 0;
  i = 0;
  while (i < 4)
  {
    if (grid[i][col] > max_height)
    {
      max_height = grid[i][col];
      count++;
    }
    i++;
  }
  return (count);
}

int count_visible_from_bottom(int grid[4][4], int col)
{
  int count;
  int max_height;
  int i;

  count = 0;
  max_height = 0;
  i = 3;
  while (i >= 0)
  {
    if (grid[i][col] > max_height)
    {
      max_height = grid[i][col];
      count++;
    }
    i--;
  }
  return (count);
}

int check_visibility_constraints(int grid[4][4], int *constraints)
{
  int i;

  i = 0;
  while (i < 4)
  {
    if (count_visible_from_top(grid, i) != constraints[i])
      return (0);
    if (count_visible_from_bottom(grid, i) != constraints[i + 4])
      return (0);
    i++;
  }
  i = 0;
  while (i < 4)
  {
    if (count_visible_from_left(grid[i]) != constraints[i + 8])
      return (0);
    if (count_visible_from_right(grid[i]) != constraints[i + 12])
      return (0);
    i++;
  }
  return (1);
}

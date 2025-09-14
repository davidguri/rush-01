#include "main.h"

static int backtrack_solve(int grid[4][4], int *constraints, int pos);

int solve_puzzle(int *constraints, int grid[4][4])
{
  if (!constraints || !grid)
    return (0);
  return (backtrack_solve(grid, constraints, 0));
}

int is_valid_placement(int grid[4][4], int row, int col, int num)
{
  int i;

  i = 0;
  while (i < 4)
  {
    if (grid[row][i] == num)
      return (0);
    i++;
  }

  i = 0;
  while (i < 4)
  {
    if (grid[i][col] == num)
      return (0);
    i++;
  }
  return (1);
}

static int backtrack_solve(int grid[4][4], int *constraints, int pos)
{
  int row;
  int col;
  int num;

  if (pos == 16)
    return (check_visibility_constraints(grid, constraints));

  row = pos / 4;
  col = pos % 4;

  num = 1;
  while (num <= 4)
  {
    if (is_valid_placement(grid, row, col, num))
    {
      grid[row][col] = num;
      if (backtrack_solve(grid, constraints, pos + 1))
        return (1);
      grid[row][col] = 0;
    }
    num++;
  }
  return (0);
}

#include "main.h"

static void init_grid(int grid[4][4])
{
  int i;
  int j;

  i = 0;
  while (i < 4)
  {
    j = 0;
    while (j < 4)
    {
      grid[i][j] = 0;
      j++;
    }
    i++;
  }
}

int main(int argc, char **argv)
{
  int constraints[16];
  int grid[4][4];

  if (argc != 2)
  {
    print_error();
    return (1);
  }
  if (!validate_input(argv[1]) || !parse_constraints(argv[1], constraints))
  {
    print_error();
    return (1);
  }
  init_grid(grid);
  if (solve_puzzle(constraints, grid))
  {
    print_grid(grid);
    return (0);
  }
  print_error();
  return (1);
}

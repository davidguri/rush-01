#include <unistd.h>

// Function prototypes
int validate_input(char *str);
int parse_constraints(char *str, int *constraints);
int solve_puzzle(int *constraints, int grid[4][4]);
void print_grid(int grid[4][4]);
void print_error(void);
int is_valid_placement(int grid[4][4], int row, int col, int num);
int check_visibility_constraints(int grid[4][4], int *constraints);
int count_visible_from_left(int *row);
int count_visible_from_right(int *row);
int count_visible_from_top(int grid[4][4], int col);
int count_visible_from_bottom(int grid[4][4], int col);
int backtrack_solve(int grid[4][4], int *constraints, int pos);

int main(int argc, char **argv)
{
	int constraints[16];
	int grid[4][4];
	int i, j;

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

	if (solve_puzzle(constraints, grid))
	{
		print_grid(grid);
		return (0);
	}
	else
	{
		print_error();
		return (1);
	}
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
		// Skip spaces
		while (str[i] == ' ')
			i++;

		// Check if we have a valid digit
		if (str[i] >= '1' && str[i] <= '4')
		{
			count++;
			i++;
			// After a digit, we should have space or end of string
			if (str[i] && str[i] != ' ')
				return (0);
		}
		else if (str[i])
		{
			// Invalid character found
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
		// Skip spaces
		while (str[i] == ' ')
			i++;

		// Parse number
		if (str[i] >= '1' && str[i] <= '4')
		{
			constraints[j] = str[i] - '0';
			j++;
			i++;
		}
		else if (str[i])
		{
			// Invalid character
			return (0);
		}
	}

	return (j == 16);
}

int solve_puzzle(int *constraints, int grid[4][4])
{
	if (!constraints || !grid)
		return (0);

	return (backtrack_solve(grid, constraints, 0));
}

int backtrack_solve(int grid[4][4], int *constraints, int pos)
{
	int row, col, num;

	if (pos == 16)
	{
		return (check_visibility_constraints(grid, constraints));
	}

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

int check_visibility_constraints(int grid[4][4], int *constraints)
{
	int i;

	// Check column constraints (up and down)
	i = 0;
	while (i < 4)
	{
		if (count_visible_from_top(grid, i) != constraints[i])
			return (0);
		if (count_visible_from_bottom(grid, i) != constraints[i + 4])
			return (0);
		i++;
	}

	// Check row constraints (left and right)
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

void print_grid(int grid[4][4])
{
	int i, j;
	char c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void print_error(void)
{
	write(1, "Error\n", 6);
}

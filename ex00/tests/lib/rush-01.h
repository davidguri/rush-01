#ifndef RUSH_01_H
#define RUSH_01_H

#include <unistd.h>

// Structure to hold the puzzle state
typedef struct s_puzzle
{
	int constraints[16];
	int grid[4][4];
} t_puzzle;

// Input validation and parsing
int validate_input(char *str);
int parse_constraints(char *str, int *constraints);

// Puzzle solving
int solve_puzzle(int *constraints, int grid[4][4]);
int backtrack_solve(int grid[4][4], int *constraints, int pos);
int is_valid_placement(int grid[4][4], int row, int col, int num);

// Visibility checking
int check_visibility_constraints(int grid[4][4], int *constraints);
int count_visible_from_left(int *row);
int count_visible_from_right(int *row);
int count_visible_from_top(int grid[4][4], int col);
int count_visible_from_bottom(int grid[4][4], int col);

// Output functions
void print_grid(int grid[4][4]);
void print_error(void);

// Memory testing functions
void test_memory_leaks(void);
int run_test_case(char *input, char *expected_output);

#endif

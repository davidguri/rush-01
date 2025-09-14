#ifndef LIB_HEADER_H
#define LIB_HEADER_H

#include <unistd.h>

int validate_input(char *str);
int parse_constraints(char *str, int *constraints);
int solve_puzzle(int *constraints, int grid[4][4]);
int backtrack_solve(int grid[4][4], int *constraints, int pos);
int is_valid_placement(int grid[4][4], int row, int col, int num);
int check_visibility_constraints(int grid[4][4], int *constraints);
int count_visible_from_left(int *row);
int count_visible_from_right(int *row);
int count_visible_from_top(int grid[4][4], int col);
int count_visible_from_bottom(int grid[4][4], int col);
void print_grid(int grid[4][4]);
void print_error(void);

#endif

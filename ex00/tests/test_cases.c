#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Test cases for validation
void test_valid_cases(void)
{
  printf("Testing valid cases:\n");

  // Test case 1: Example from subject
  printf("Valid 1: ");
  system("./rush-01 \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"");
  printf("\n");

  // Test case 2: Solvable constraints for a different grid
  // Grid:
  // 2 1 4 3
  // 3 4 1 2
  // 4 3 2 1
  // 1 2 3 4
  printf("Valid 2: ");
  system("./rush-01 \"3 2 1 2 2 3 2 1 2 2 1 4 2 2 4 1\"");
  printf("\n");

  // Test case 3: Solvable constraints for another Latin square
  // Grid:
  // 1 3 4 2
  // 2 4 1 3
  // 3 1 2 4
  // 4 2 3 1
  printf("Valid 3: ");
  system("./rush-01 \"4 2 1 3 1 2 2 2 3 2 2 1 2 2 1 3\"");
  printf("\n");

  // Test case 4: Another solvable constraints set
  // Grid:
  // 4 1 2 3
  // 1 2 3 4
  // 2 3 4 1
  // 3 4 1 2
  // Constraints computed from the above grid
  printf("Valid 4: ");
  system("./rush-01 \"1 4 3 2 2 1 2 2 1 4 3 2 2 1 2 2\"");
  printf("\n");
}

void test_error_cases(void)
{
  printf("Testing error cases:\n");

  // Test invalid number of arguments
  printf("No arguments: ");
  system("./rush-01");

  printf("Too many arguments: ");
  system("./rush-01 \"1 2 3 4\" \"extra\"");

  // Test invalid characters
  printf("Invalid character: ");
  system("./rush-01 \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 a\"");

  // Test numbers out of range
  printf("Number out of range: ");
  system("./rush-01 \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 5\"");

  // Test too few numbers
  printf("Too few numbers: ");
  system("./rush-01 \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2\"");

  // Test too many numbers
  printf("Too many numbers: ");
  system("./rush-01 \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 1\"");

  // Test impossible constraints
  printf("Impossible constraints: ");
  system("./rush-01 \"4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4\"");

  // Additional: weird special characters sprinkled
  printf("Weird specials: ");
  system("./rush-01 \"4 3 2 1 1 2 2@2 4 3 2 1 1 2 2 2\"");

  // Additional: tabs between numbers (should be invalid if only spaces allowed)
  printf("Tabs between numbers: ");
  system("./rush-01 \"4\t3\t2\t1 1\t2\t2\t2 4\t3\t2\t1 1\t2\t2\t2\"");

  // Additional: newlines inside argument
  printf("Newlines inside argument: ");
  system("./rush-01 \"4 3 2 1\\n1 2 2 2 4 3 2 1 1 2 2 2\"");

  // Additional: multiple spaces (valid if parser skips spaces)
  printf("Multiple spaces between numbers: ");
  system("./rush-01 \"4   3  2    1   1    2  2  2  4   3 2   1  1  2  2  2\"");

  // Additional: leading/trailing spaces
  printf("Leading/trailing spaces: ");
  system("./rush-01 \"   4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2   \"");

  // Additional: INT_MAX-like tokens and large numbers
  printf("INT_MAX token: ");
  system("./rush-01 \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2147483647\"");

  printf("Negative number token: ");
  system("./rush-01 \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 -1\"");

  printf("Huge number token: ");
  system("./rush-01 \"9999999999 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"");
}

int main(void)
{
  printf("Compiling rush-01...\n");
  system("make -f Makefile.local");

  test_valid_cases();
  test_error_cases();

  printf("Cleaning up...\n");
  system("make -f Makefile.local clean");

  return (0);
}

# Matrix.h

Implementation of Matrixl.h library on C 

## Contents

0. [Information](#information)
1. [Matrix structure in C language](#matrix-structure)
2. [Matrix operations](#matrix-operations)

## Information   
Implement basic operations with matrices (partially described [below](#matrix-operations)): 
| Name | Description |
| ------ | ------ |
| `create_matrix` | creation|
| `remove_matrix` | cleaning and destruction|
| `eq_matrix` | comparison|
| `sum_matrix` | addition|
| `sub_matrix` | subtraction|
| `mult_matrix` | multiplication|
| `mult_number` | multiplication by number|
| `transpose` | transpose|
| `determinant` | calculation of determinant|
| `calc_complements` | calculation of matrix of algebraic complements|
| `inverse_matrix` | finding inverse of the matrix |

- The library was developed in C language of C11 standard using gcc compiler
- The library code was located in the src folder.   
- Outdated and legacy language constructions and library functions were not used.
- The programs were developed by POSIX.1-2017 standard.
- The program code written in Google style
- A static library (with the my_matrix.h header file)
- The library was developed according to the principles of structured programming;
- Use prefix my_ before each function
- Full coverage of library functions code with unit-tests using the Check library
- Unit tests cover at least 80% of each function (checked using gcov)  
- Makefile for building the library and tests (with targets all, clean, test, my_matrix.a, gcov_report)
- The gcov_report target generate a gcov report in the form of an html page. Unit tests was run with gcov flags to do this. 
- The matrix was implemented as the structure described [below](#matrix-structure)
- Verifiable accuracy of the fractional part is up to 6 decimal places


## Matrix structure

```c
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

## Matrix operations

All operations (except matrix comparison) should return the resulting code:
- 0 - OK
- 1 - Error, incorrect matrix
- 2 - Calculation error (mismatched matrix sizes; matrix for which calculations cannot be performed, etc.)

### Creating matrices (create_matrix)

```c
int my_create_matrix(int rows, int columns, matrix_t *result);
```

### Cleaning of matrices (remove_matrix)

```c
void my_remove_matrix(matrix_t *A);
```

### Matrix comparison (eq_matrix)

```c
#define SUCCESS 1
#define FAILURE 0

int my_eq_matrix(matrix_t *A, matrix_t *B);
```

The matrices A, B are equal |A = B| if they have the same dimensions and the corresponding elements are identical, thus for all i and j: A(i,j) = B(i,j)

The comparison was up to and including 7 decimal places.

### Adding (sum_matrix) and subtracting matrices (sub_matrix)

```c
int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int my_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

The sum of two matrices A = m × n and B = m × n of the same size is a matrix C = m × n = A + B of the same size whose elements are defined by the equations C(i,j) = A(i,j) + B(i,j).

The difference of two matrices A = m × n and B = m × n of the same size is a matrix C = m × n = A - B of the same size whose elements are defined by the equations C(i,j) = A(i,j) - B(i,j).


### Matrix multiplication by scalar (mult_number). Multiplication of two matrices (mult_matrix)

```c
int my_mult_number(matrix_t *A, double number, matrix_t *result);
int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

The product of the matrix A = m × n by the number λ is the matrix B = m × n = λ × A whose elements are defined by the equations B = λ × A(i,j).


### Matrix transpose (transpose)

```c
int my_transpose(matrix_t *A, matrix_t *result);
```

The transpose of matrix A is in switching its rows with its columns with their numbers retained


### Minor of matrix and matrix of algebraic complements (calc_complements)
```c
int my_calc_complements(matrix_t *A, matrix_t *result);
```

Minor M(i,j) is a (n-1)-order determinant obtained by deleting out the i-th row and the j-th column from the matrix A.


### Matrix determinant

```c
int my_determinant(matrix_t *A, double *result);
```

The determinant is a number that is associated to each square matrix and calculated from the elements using special formulas. \
The determinant can only be calculated for a square matrix. The determinant of a matrix equals the sum of the products of elements of the row (column) and the corresponding algebraic complements.


### Inverse of the matrix (inverse_matrix)

```c
int my_inverse_matrix(matrix_t *A, matrix_t *result);
```

A matrix A to the power of -1 is called the inverse of a square matrix A if the product of these matrices equals the identity matrix.


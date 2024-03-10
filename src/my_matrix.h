#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum {
  OK = 0,
  INCORRECT_MATRIX = 1,
  CALC_ERROR = 2,
  SUCCESS = 1,
  FAILURE = 0
} CONVERT_STATUS;

int my_create_matrix(int rows, int columns, matrix_t *result);
void my_remove_matrix(matrix_t *A);
int my_eq_matrix(matrix_t *A, matrix_t *B);
int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int my_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int my_mult_number(matrix_t *A, double number, matrix_t *result);
int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int my_transpose(matrix_t *A, matrix_t *result);
int my_determinant(matrix_t *A, double *result);
int my_calc_complements(matrix_t *A, matrix_t *result);
int my_inverse_matrix(matrix_t *A, matrix_t *result);

int my_matrix_correct(matrix_t *matrix);
int my_minor_mat(int row, int column, matrix_t *M, matrix_t *result);
double det(matrix_t *M);
int calc_helper(matrix_t *A, matrix_t *result);
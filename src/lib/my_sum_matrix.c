#include "../my_matrix.h"

int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;

  if (!my_matrix_correct(A) || !my_matrix_correct(B)) {
    res = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    res = CALC_ERROR;
  } else if (my_create_matrix(A->rows, A->columns, result) != OK) {
    res = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return res;
}
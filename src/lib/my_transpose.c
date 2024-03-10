#include "../my_matrix.h"

int my_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;

  if (!my_matrix_correct(A)) {
    res = INCORRECT_MATRIX;
  } else if (my_create_matrix(A->rows, A->columns, result) != OK) {
    res = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return res;
}

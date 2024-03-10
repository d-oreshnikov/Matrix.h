#include "../my_matrix.h"

int my_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = 1;

  if (A->rows != B->rows || A->columns != B->columns) res = 0;

  if (!my_matrix_correct(A) || !my_matrix_correct(B)) res = 0;

  if (res) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) res = 0;
      }
    }
  }

  return SUCCESS ? res : FAILURE;
}
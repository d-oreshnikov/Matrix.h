#include "../my_matrix.h"

int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = 1;
  if (my_matrix_correct(A) && my_matrix_correct(B)) {
    if (A->columns == B->rows) {
      err = my_create_matrix(A->rows, B->columns, result);
      if (err == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            for (int k = 0; k < B->rows; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      }
    } else {
      err = 2;
    }
  }
  return err;
}
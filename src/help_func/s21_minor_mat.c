#include "../my_matrix.h"

int my_minor_mat(int row, int column, matrix_t *A, matrix_t *result) {
  int err = SUCCESS;
  if (A->matrix != NULL) {
    err = my_create_matrix(A->rows - 1, A->columns - 1, result);
    if (err == FAILURE) {
      int m, n;
      for (int i = 0; i < A->rows; i++) {
        m = i;
        if (i > row - 1) {
          m--;
        }
        for (int j = 0; j < A->columns; j++) {
          n = j;
          if (j > column - 1) {
            n--;
          }
          if (i != row - 1 && j != column - 1) {
            result->matrix[m][n] = A->matrix[i][j];
          }
        }
      }
    }
  }
  return err;
}
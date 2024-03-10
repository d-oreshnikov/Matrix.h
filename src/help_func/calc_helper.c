#include "../my_matrix.h"

int calc_helper(matrix_t *A, matrix_t *result) {
  int err = OK;
  result->matrix[0][0] = 1;
  if (A->rows != 1) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double deted;
        matrix_t minored;
        err = my_minor_mat(i + 1, j + 1, A, &minored);
        if (err == OK) {
          err = my_determinant(&minored, &deted);
          if (err == OK) {
            result->matrix[i][j] = pow((-1), i + j) * deted;
          }
        }
        my_remove_matrix(&minored);
      }
    }
  }
  return err;
}

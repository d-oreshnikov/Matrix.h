#include "../my_matrix.h"

int my_determinant(matrix_t *A, double *result) {
  int err = 1;
  if (my_matrix_correct(A)) {
    err = 2;
    if (A->rows == A->columns) {
      err = 0;
      *result = A->matrix[0][0];
      if (A->rows != 1) {
        *result = det(A);
      }
    }
  }
  return err;
}
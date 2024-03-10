#include "../my_matrix.h"

int my_calc_complements(matrix_t *A, matrix_t *result) {
  int err = INCORRECT_MATRIX;
  if (my_matrix_correct(A)) {
    err = CALC_ERROR;
    if (A->rows == A->columns) {
      err = my_create_matrix(A->rows, A->columns, result);
      if (err == OK) {
        err = calc_helper(A, result);
      }
    }
  }
  return err;
}

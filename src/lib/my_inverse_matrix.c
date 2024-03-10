#include "../my_matrix.h"

int my_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = 1;
  if (my_matrix_correct(A)) {
    err = 2;
    double det;
    my_determinant(A, &det);
    if (fabs(det - 0) > 1e-6) {
      matrix_t tmp_calc;
      err = my_calc_complements(A, &tmp_calc);
      if (err == 0) {
        matrix_t tmp_trans;
        err = my_transpose(&tmp_calc, &tmp_trans);
        if (err == 0) {
          my_mult_number(&tmp_trans, 1 / det, result);
        }
        my_remove_matrix(&tmp_trans);
      }
      my_remove_matrix(&tmp_calc);
    }
  }
  return err;
}
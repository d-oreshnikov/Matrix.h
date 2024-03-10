#include "../my_matrix.h"

double det(matrix_t *A) {
  double result = OK;
  if (A->rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      matrix_t minor;
      my_minor_mat(1, i + 1, A, &minor);
      result += pow((-1), i) * A->matrix[0][i] * det(&minor);
      my_remove_matrix(&minor);
    }
  }
  return result;
}
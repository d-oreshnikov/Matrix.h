#include "../my_matrix.h"

int my_matrix_correct(matrix_t *matrix) {
  return matrix && (matrix->rows > 0) && (matrix->columns > 0) &&
         matrix->matrix;
  ;
}
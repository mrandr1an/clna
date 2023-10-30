
/* //Enable debug functions */
#define LNA_DEBUG
/* //Features */
#define LNA_FUNCTION_ERRORS

//Include library
#include "../../src/linear/algebra.h"

#define matrixAdditionTest_FAIL

int main() {
  #ifdef fillMatrixTest
  Matrix_ixj mat = initMatrix_ixj(2,4);

  fillMatrix_pos_ixj(0,0,&mat,1.0);
  fillMatrix_pos_ixj(0,1,&mat,2.0);
  fillMatrix_pos_ixj(0,2,&mat,3.0);
  fillMatrix_pos_ixj(0,3,&mat,4.0);

  fillMatrix_pos_ixj(1,0,&mat,1.0);
  fillMatrix_pos_ixj(1,1,&mat,2.0);
  fillMatrix_pos_ixj(1,2,&mat,3.0);
  fillMatrix_pos_ixj(1,3,&mat,4.0);

  printMatrix_ixj(mat);
  #endif // fillMatrixTest

  #ifdef matrixAdditionTest
  Matrix_ixj mat1 = initMatrix_ixj(3,2);
  Matrix_ixj mat2 = initMatrix_ixj(3,2);

  fillMatrix_pos_ixj(0,0,&mat1,1.0);
  fillMatrix_pos_ixj(0,1,&mat1,3.0);
  fillMatrix_pos_ixj(1,0,&mat1,1.0);
  fillMatrix_pos_ixj(1,1,&mat1,0.0);

  fillMatrix_pos_ixj(2,0,&mat1,1.0);
  fillMatrix_pos_ixj(2,1,&mat1,2.0);

  fillMatrix_pos_ixj(0,0,&mat2,0.0);
  fillMatrix_pos_ixj(0,1,&mat2,0.0);

  fillMatrix_pos_ixj(1,0,&mat2,7.0);
  fillMatrix_pos_ixj(1,1,&mat2,5.0);

  fillMatrix_pos_ixj(2,0,&mat2,2.0);
  fillMatrix_pos_ixj(2,1,&mat2,1.0);

  addMatrix_ixj_ixj(&mat1,mat2); 
  printMatrix_ixj(mat1);
  #endif //MatrixAdditiontest

  #ifdef matrixAdditionTest_FAIL
  Matrix_ixj mat1 = initMatrix_ixj(3,2);
  Matrix_ixj mat2 = initMatrix_ixj(2,2);

  fillMatrix_pos_ixj(0,0,&mat1,1.0);
  fillMatrix_pos_ixj(0,1,&mat1,3.0);

  fillMatrix_pos_ixj(1,0,&mat1,1.0);
  fillMatrix_pos_ixj(1,1,&mat1,0.0);

  fillMatrix_pos_ixj(2,0,&mat1,1.0);
  fillMatrix_pos_ixj(2,1,&mat1,2.0);

  fillMatrix_pos_ixj(0,0,&mat2,0.0);
  fillMatrix_pos_ixj(0,1,&mat2,0.0);

  fillMatrix_pos_ixj(1,0,&mat2,7.0);
  fillMatrix_pos_ixj(1,1,&mat2,5.0);

  addMatrix_ixj_ixj(&mat1,mat2); 
  printMatrix_ixj(mat1);
  #endif //matrixAdditionTest_Fail
  return 0;
}

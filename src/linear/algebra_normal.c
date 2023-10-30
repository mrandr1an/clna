#ifndef ALGEBRA_NORMAL
#define ALGEBRA_NORMAL
#include "algebra.h"


Matrix_ixj initMatrix_ixj(unsigned int rows,unsigned int collumns)
{
  Matrix_ixj mat;
  mat.rows = rows;
  mat.cols = collumns;
  mat.data = (float**) malloc(sizeof(float*) * (rows));
   for (int i = 0; i <= rows; i++) {
	 mat.data[i] = (float*)malloc(sizeof(float) * collumns);
    }

  return mat;
}

void fillMatrix_pos_ixj(unsigned int row, unsigned int col,Matrix_ixj* mat, float value) {
  mat->data[row][col] = value;
}

void printMatrix_ixj(Matrix_ixj mat) {
  //Print rows first
  for(int i = 0; i<mat.rows; i++)
	{
      //Print cols
	  for(int j = 0; j<mat.cols; j++)
		{
		  printf("%1.1f ",mat.data[i][j]);
		}
	  printf("\n");
	}
}

void fillMatrix_row_all_ixj(unsigned int row,float* arr,Matrix_ixj* mat)
{
}

void addMatrix_ixj_ixj(Matrix_ixj* mat1,Matrix_ixj mat2)
{
  if(mat1->rows != mat2.rows)
	{
	#ifdef LNA_FUNCTION_ERRORS
	  lna_perr( "Cannot add matrices with different number of rows\n"); 
	#endif
	}
  else
	{
	  for(int i=0;i<mat1->rows;i++)
		{
			//Print cols
		  for(int j = 0; j<mat1->cols; j++)
			{
			  if(mat2.data[i] != NULL)
				{
				  mat1->data[i][j] = mat1->data[i][j] + mat2.data[i][j];
				}
			}
		}
	}
}
#endif //ALGEBRA_NORMAL

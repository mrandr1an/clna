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
  #ifdef LNA_FUNCTION_ERRORS
  if(row >= mat->rows)
	{
	  lna_perr("Exceeding the limit of rows based on matrix definition | note: Remember to start from 0");
	}
  else if(col >= mat->cols)
	{
	  lna_perr("Exceeding the limit of columns based on matrix definition | note: Remember to start from 0");
	}
  #endif //LNA_FUNCTION_ERROR
  mat->data[row][col] = value;
}

#ifdef LNA_DEBUG
void printMatrix_ixj(Matrix_ixj mat) {
  //Print rows first
  for(int i = 0; i<mat.rows; i++)
	{
      //Print cols
	  for(int j = 0; j<mat.cols; j++)
		{
		  printf(LNA_CYAN "%1.1f ",mat.data[i][j]);
		}
	  printf("\n");
	}
}
#endif //LNA_DEBUG


#ifdef LNA_DEBUG
void printMatrix_bad_ixj(Matrix_ixj mat) {
  //Print rows first
  for(int i = 0; i<mat.rows; i++)
	{
      //Print cols
	  for(int j = 0; j<mat.cols; j++)
		{
		  printf(LNA_RED "%1.1f ",mat.data[i][j]);
		}
	  printf("\n");
	}
}
#endif //LNA_DEBUG

void fillMatrix_row_all_ixj(unsigned int row,float* arr,Matrix_ixj* mat)
{

}

void addMatrix_ixj_ixj(Matrix_ixj* mat1,Matrix_ixj mat2)
{
  if(mat1->rows != mat2.rows)
	{
	#ifdef LNA_FUNCTION_ERRORS 
	  lna_perr("Cannot add matrices with different number of rows matrix remains unchanged\n");
	#endif
	#ifdef LNA_FUNCTION_OPERATIONS
	  printMatrix_ixj(*mat1);
	  printf("+\n");
	  printMatrix_ixj(mat2);
	  printf("=\n");
	  printMatrix_bad_ixj(*mat1);
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

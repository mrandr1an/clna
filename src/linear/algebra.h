/*
   # lna - Linear Algebra

   # Matrices
		Matrix naming convention is Matrix_NUMBER_OF_ROWSxNUMNER_OF_COLLUMNS
		For special matrices its Matrix_NAME_OF_SPECIAL_MATRIX
		If not defined otherwise all the data-structures accept only float (Real) numbers
		on customized precision.

   # Imaginary Numbers


   # Vectors


   # Operations


   # Debug
*/
#ifndef ALGEBRA_H
#define ALGEBRA_H
#include <stdlib.h>
#include <stdio.h>

typedef struct Matrix_ixj
{
  size_t rows;
  size_t cols;
  float **data;
} Matrix_ixj;

//Creates an empty ixj matrix
Matrix_ixj initMatrix_ixj(unsigned int rows, unsigned int collumns);

/* ixj Matrix Operations */

//Sets position [i][j] equal to value
void fillMatrix_pos_ixj(unsigned int row, unsigned int col,Matrix_ixj* mat, float value);
// Takes a 2D array of rows[columns] that points to its columns and fills accordingly
void fillMatrix_all_ixj(float* arr,Matrix_ixj* mat);
//Adds two matrices of unknown size (ixj), modifies mat1
void addMatrix_ixj_ixj(Matrix_ixj* mat1, Matrix_ixj mat2);

/* SPECIAL MATRICES */
#define Matrix_Identity
#define Matrix_Zero

/* Misc functions */
#ifdef LNA_DEBUG
  #include "../style/debug.h"
  void printMatrix_ixj(Matrix_ixj mat);
  //print matrix with red color
  void printMatrix_bad_ixj(Matrix_ixj mat);
#endif //LNA_DEBUG

#endif //ALGEBRA_H

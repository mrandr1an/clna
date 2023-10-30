//Enable debug functions
#define LNA_DEBUG

//Include library
#include "../../src/linear/algebra.h"

static unsigned int test_counter = 0;
static unsigned int pass = 0;
static unsigned int fail = 0;

#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define BLUE "\x1B[33m"
#define OTHER "\x1B[34m"
#define RESET "\x1B[0m"


// Test functions if result is unexpected call failed otherwise call passed
// no reason to manually increase test_counter
void passed()
{
  pass++;
printf(GREEN "####PASSED TEST:%d####\n" RESET, ++test_counter);
}

void failed()
{
  fail++;
printf(RED "####FAILED TEST:%d####\n" RESET, ++test_counter);
}

void result() { 
  printf("####" GREEN "PASSED:" BLUE "%d" RESET "####\n" RESET
		 "####" RED "FAILED:%d" RESET
		 "####\n" RESET
		 "####" OTHER "TOTAL:" BLUE "%d" RESET"####\n",pass,fail, test_counter); 
}
//Define test name
#define matrixAdditionTest_FAIL
#define fillArrayTest
int main()
{
 #ifdef matrixAdditionTest_FAIL
  Matrix_ixj mat1 = initMatrix_ixj(3,2);
  Matrix_ixj mat_temp = mat1;
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
  if(mat1.data[4] == mat_temp.data[4])
	{
	  passed();
	}
  else
	{
	  failed();
	}
  #endif //matrixAdditionTest_Fail

  #ifdef fillArrayTest 
  Matrix_ixj mat_to_fill = initMatrix_ixj(3,2);

  float a[] = {1.0f, 3.0f,1.0f, 0.0f,1.0f,2.0f,32.0f,32};
 
  fillMatrix_all_ixj(a,&mat_to_fill);
  if(mat_to_fill.data[0][0] == mat1.data[0][0])
	{
	  passed();
	}
  else
	{
	  failed();
	}
  printMatrix_ixj(mat1);
  printMatrix_ixj(mat_to_fill);
  #endif //fillArraytest

  result();
  if(fail == 0)
  {
	return 0;
  }
  else
	{
	  return 1;
	}
}

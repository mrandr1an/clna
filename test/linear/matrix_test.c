//Enable debug functions
#define LNA_DEBUG

//Include library
#include "../../src/linear/algebra.h"

static unsigned int test_counter = 0;

#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define RESET "\x1B[0m"


// Test functions if result is unexpected call failed otherwise call passed
// no reason to manually increase test_counter
void passed()
{
printf(GREEN "####PASSED TEST:%d####\n" RESET, test_counter++);
}

void failed()
{
printf(RED "####FAILED TEST:%d####\n" RESET, test_counter++);
}

//Define test name

int main()
{

}

#ifndef LNA_STYLE
#define LNA_STYLE
#include <stdio.h>

#define LNA_RED  "\x1B[31m"
#define LNA_GREEN "\x1B[32m"
#define LNA_YELLOW  "\x1B[33m"
#define LNA_BLUE "\x1B[34m"
#define LNA_MAG  "\x1B[35m"
#define LNA_CYAN  "\x1B[36m"
#define LNA_RESET "\x1B[0m"

#define LNA_MESSAGE "LNA::"
#define LNA_ERROR "ERROR::"

/* prints error with defined color */
void lna_perr(char msg[52]);

#endif //LNA_STYLE

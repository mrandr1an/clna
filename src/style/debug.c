#include "debug.h"

void lna_perr(char msg[52]) {
  printf(LNA_MAG LNA_MESSAGE LNA_RESET LNA_RED LNA_ERROR LNA_RED "test %s%s",msg,LNA_RESET);
}


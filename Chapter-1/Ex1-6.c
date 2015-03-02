#include "apue.h"
#include <limits.h>

int main(void)
{
  int overflow = INT_MAX / (24 * 60 * 60 * 100);

  printf("\n Overflow happens after %d days!", overflow);

  exit(0);
}

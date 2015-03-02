#include "apue.h"
#include <time.h>

int main(void)
{

  time_t largest = 0x7FFFFFFF;
 
  printf("\n Sizeof(time_t): %lu", sizeof(time_t));
  printf("\n Overflow occurs at %s \n", asctime(gmtime(&largest)));

  exit(0);
}

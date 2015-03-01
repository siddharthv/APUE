#include "apue.h"

int main(void)
{
  int c;

  while((c=getc(stdin)) != EOF)
    if (putc(c, stdout) == EOF)
      err_sys("Output error");

  if (ferror(stdin))
    err_sys("Input error");

  exit(0);
}

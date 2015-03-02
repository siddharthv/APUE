#include "apue.h"
#include <sys/wait.h>

int main(void)
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("%%");
  while(fgets(buf, MAXLINE, stdin) != NULL)
    {
      if(buf[strlen(buf) - 1] == '\n')
      buf[strlen(buf) - 1] = 0;

      if ((pid = fork()) < 0)
	{
	  err_sys("Fork error");
	}
      else if (pid == 0)
	{
	  execlp(buf, buf, (char*) 0);
	  err_ret("Couldn't execute: %s", buf);
	  exit(127);
	}

      if ((pid = waitpid(pid, &status, 0)) < 0)
	err_sys("Waitpid error");

      printf("%%");
    }

  exit(0);
}

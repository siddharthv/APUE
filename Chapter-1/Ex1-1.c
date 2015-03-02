#include "apue.h"
#include <dirent.h>

int main(int argc, char **argv)
{
  DIR *dp;
  char filename [FILENAME_MAX];
  struct stat sb;
  unsigned long cwd, pwd;

  if ((dp=opendir(argv[1])) == NULL)
    err_sys("Can't open %s", argv[1]);

  snprintf(filename, FILENAME_MAX, "%s/.", argv[1]);
  
  if (stat(filename, &sb) != 0)
    err_sys("Unable to stat file: %s", filename);
  else
    {
      cwd = sb.st_ino;
      printf("\n Inode of %s : %llu \n", filename, sb.st_ino);
    }

  snprintf(filename, FILENAME_MAX, "%s/..", argv[1]);

  if (stat(filename, &sb) != 0)
    err_sys("Unable to stat file: %s", filename);
  else
    {
      pwd = sb.st_ino;
      printf("\n Inode of %s : %llu \n", filename, sb.st_ino);
    }

  if (cwd == pwd)
    printf("\n We are checking '/' \n");
  else
    printf("\n We are NOT checking '/' \n");

  exit(0);
}

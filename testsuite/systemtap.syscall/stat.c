/* COVERAGE: getcwd fstat stat lstat utime */
/* COVERAGE: fstat64 stat64 lstat64 */
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

int main()
{
  int fd;
  char cwd[128];
  struct stat sbuf;
  struct utimbuf ubuf;

  getcwd(cwd, 128);
  // getcwd (XXXX, 128) = NNNN

  fd = creat("foobar",S_IREAD|S_IWRITE);
  // open ("foobar", O_WRONLY|O_CREAT|O_TRUNC, 0600) = 4

  fstat(fd, &sbuf);
  // fstat (4, XXXX) = 0

  close(fd);

  stat("foobar",&sbuf);
  // stat ("foobar", XXXX) = 0

  lstat("foobar",&sbuf);
  // lstat ("foobar", XXXX) = 0

  ubuf.actime = 1;
  ubuf.modtime = 1135641600;
  utime("foobar", &ubuf);
  // utime ("foobar", \[1970/01/01-00:00:01, 2005/12/27-00:00:00\]) = 0

  ubuf.actime =  1135690000;
  ubuf.modtime = 1135700000;
  utime("foobar", &ubuf);
  // utime ("foobar", \[2005/12/27-13:26:40, 2005/12/27-16:13:20\]) = 0

  return 0;
}

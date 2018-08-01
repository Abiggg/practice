#include<stdio.h>
#include<stdlib.h>   // exit
#include<errno.h>
#include<fcntl.h>    // O_WRONLY
#include<sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int fd;
  int len;
  char buff[1024];
  time_t tp;

  if(mkfifo("fifo1", 0666) < 0 && errno != EEXIST)// create fifo pipe
  {
    printf("fifo1 opened failed\n");
    exit(1);
  }

  if(fd = open("fifo1", O_RDONLY) < 0)
  {
    printf("open fifo1 failed\n");
    exit(1);
  }

  while(len = read(fd, buff, 1024) > 0)
  {
    printf("Read messeage is :%s\n", buff);
  }
  close(fd); //close fifo1;
  return 0;
}

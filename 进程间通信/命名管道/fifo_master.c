#include<stdio.h>
#include<stdlib.h>   // exit
#include<fcntl.h>    // O_WRONLY
#include<sys/stat.h>
#include<time.h>     // time
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int fd;
  int n;
  int i;
  char buff[1024];
  time_t tp;

  printf("this is master process, process id is : %d\n", getpid());

  if(fd = open("fifo1", O_WRONLY) < 0) // Write only type to open a fifo ,nameed "fifo1"
  {
    printf("fifo1 opened failed\n");
    exit(1);
  }

  for(i=0;i<10;i++)
  {
    time(&tp);
    n = sprintf(buff, "process id is %d ,time is %s", getpid(), ctime(&tp));
    if(write(fd, buff, n+1) < 0) // write to fifo1
    {
      printf("write fifo1 failed\n");
      close(fd);
      exit(1);
    }
    sleep(1);
  }
  close(fd); //close fifo1;
  return 0;
}

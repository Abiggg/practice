#include <stdio.h>
#include <unistd.h>

int main()
{
  int fd[2];  //fd[0] is for read , fd[1] is for write

  pid_t pid;
  char buff[50];

  if(pipe(fd) < 0) //creat pipe
  {
    printf("creat pipe fail\n");
  }
  if((pid = fork()) < 0)
  {
    printf("fork error\n");
  }
  else if(pid == 0) //child process /
  {
    close(fd[1]);// close write ending
    read(fd[0], buff, 50);
    printf("%s\n", buff);
  }
  else  //parent process
  {
    close(fd[0]); //close read ending
    write(fd[1], "this is parent process send to child process", 50);
  }
}

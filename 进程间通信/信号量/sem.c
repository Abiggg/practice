#include<stdio.h>
#include<stdlib.h>
#include<sys/sem.h>
#include <sys/types.h>
#include <unistd.h>
//联合体，用于信号量初始化
union semun
{
  int val;
  struct semid_ds *buf;
  unsigned short *array;
};

//初始化信号量
int init_sem(int sem_id, int value)
{
  union semun tmp;
  tmp.val = value;
  if(semctl(sem_id, 0, SETVAL, tmp) == -1)
  {
    printf("Init sem failed\n");
    return -1;
  }
  return 0;
}

//p操作
//若信号量为0, 则等待进；
//若信号量为1,则获取资源，并将信号量值 -1 ;
int sem_p(int sem_id)
{
  struct sembuf sbuf;
  sbuf.sem_num = 0; //序号
  sbuf.sem_op = -1;//p操作
  sbuf.sem_flg = SEM_UNDO;

  if(semop(sem_id, &sbuf, 1) == -1)
  {
    printf("p operation failed\n");
    return -1;
  }
  return 0;
}

//v操作
// 释放资源并将信号量值+1
//如有进程挂起等待，唤醒它们；

int sem_v(int sem_id)
{
  struct sembuf sbuf;
  sbuf.sem_num = 0; //序号
  sbuf.sem_op = +1;//p操作
  sbuf.sem_flg = SEM_UNDO;

  if(semop(sem_id, &sbuf, 1) == -1)
  {
    printf("p operation failed\n");
    return -1;
  }
  return 0;
}

int del_sem(int sem_id)
{
  union semun tmp;
  if(semctl(sem_id, 0, IPC_RMID, tmp) == -1)
  {
    printf("Init sem failed\n");
    return -1;
  }
  return 0;
}

int main()
{
  int sem_id;
  key_t key;
  pid_t pid;

  if(key =ftok(".", 'z') < 0)
  {
    printf("ftok error\n");
  }
  //
  if(sem_id = semget(key, 1 , IPC_CREAT|0666) == -1)
  {
        printf("semget failed\n");
        exit(1);
  }

  //初始化信号量,初始化0资源被占用
  init_sem(sem_id, 0);

  if(pid = fork() == -1)
  {
    printf("fork failed\n");
  }
  else if(pid == 0) //子进程
  {
    sleep(2);
    printf("process child :pid = %d\n", getpid());
    sem_v(sem_id); //信号量+1
  }
  else
  {
    sem_p(sem_id); //等待信号量为1
    printf("process father:pid = %d\n", getpid());
    sem_v(sem_id);//信号量减1
    del_sem(sem_id);
  }
  return 0;
}

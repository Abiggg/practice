#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXSIZE 10
sem_t sem;
int stack[MAXSIZE];

void handler_data()
{
  int i;
  for(i=0;i<MAXSIZE;i++)
  {
    sem_wait(&sem);
    printf("%d\n", stack[i]);
  }
}


void provider_data()
{
    int i;
    for(i=0;i< MAXSIZE;i++)
    {
      stack[i] = i;
      usleep(10);
      sem_post(&sem);
    }
}

void main()
{
  pthread_t provider , handler;

  sem_init(&sem, 0, 0); /*信号量初始化*/
  pthread_create(&handler, NULL, (void*)handler_data, NULL);
  pthread_create(&provider, NULL, (void*)provider_data, NULL);

  pthread_join(provider, NULL);
  pthread_join(handler, NULL);
  //sem_destroy(&sem); //销毁信号量

  return;
}

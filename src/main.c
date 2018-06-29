#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <pthread_id.h>

pthread_t ntid;

int main()
{
    int err;

    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if(err!=0)
    {
        printf("can't create thread\n");
        exit(1);
    }
    printids("main thread:");
    sleep(2);
    return 1;
}

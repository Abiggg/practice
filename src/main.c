#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <pthread_id.h>
#include "sort.h"

pthread_t ntid;

typedef enum
{
    PTHREAD_TEST = 0,
    DATA_STRUCT_TEST,
    SORT_TEST,
}TEST_TYPE_E;

extern int test[];

int main()
{
    int err;
    int type = 2;
    int sort_type = QUICKSORT;
    switch(type)
    {
      case PTHREAD_TEST:
        err = pthread_create(&ntid, NULL, thr_fn, NULL);
        if(err!=0)
        {
            printf("can't create thread\n");
            exit(1);
        }
        printids("main thread:");
        sleep(2);
        break;
      case DATA_STRUCT_TEST:
        break;
      case SORT_TEST:
        {
            switch(sort_type)
            {
              case BUBBLESORT:
                  BubbleSort(test, 8);
              break;
              case CORTTAILSORT:
                  CockTailSort(test, 8);
              break;
              case SHELLSORT:

              break;
              case SELECTIONSORT:
                  SelectionSort(test, 8);
              break;
              case INSERTIONSROT:
                  InsertionSort(test, 8);
              break;
              case QUICKSORT:
                  QuickSort(test, 0, 7);
              break;
              default:
              break;
            }
        }
        break;
      default:
        break;

    }

    return 1;
}

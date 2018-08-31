#include <stdio.h>
#include <stdlib.h>

int (*fun)(int x, int y);

int max(int x, int y)
{
  return x > y ? x : y;
}

void main()
{
    fun = max;
    printf("the max value is :%d\n", fun(5, 6));
}

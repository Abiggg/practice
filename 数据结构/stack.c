#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct tagSTACK
{
  int *base;
  int *top;
  int stacksize;
}STACK_S,*pSTACK_S;

void init_stack(pSTACK_S s)
{
  s->base = (int *)malloc(MAX_STACK_SIZE * sizeof(int));
  if(!s->base) exit(1);
  s->top = s->base;
  s->stacksize = 100;
}

void push_stack(pSTACK_S s, int value)
{
  if((s->top - s->base) > s->stacksize)
  {
    s->base =  (int *)realloc(s->base, sizeof(int)*(1+ s->stacksize));
    if(!s->base) exit(1);
    s->top = s->base + s->stacksize + 1;
    *(s->top) = value;
  }
  if(!s->top) exit(1);
  *(s->top) = value;
  s->top += 1;
}

void delet_stack(pSTACK_S s)
{
  if(s->top == s->base)
  {
    free(s->base);
    s->base = NULL;
    s->top = NULL;
  }
  *(s->top) = 0;
  (s->top) -= 1;
}

void destory_stack(pSTACK_S s)
{
  s->top = s->base;
  free(s->base);
  s->base = NULL;
}

int main()
{
  int a[10] = {1,3,5,6,8,2,1,4,8,1};
  int i;
  STACK_S s;
  init_stack(&s);
  printf("push stack\n");
  for(i=0; i< sizeof(a)/sizeof(int);i++)
  {
    printf("num is :%d ,value is : %d\n", i, a[i]);
    push_stack(&s, a[i]);
  }
  for(i=0; i< (s.top - s.base);i++)
  {
    printf("num is :%d\n", i);
    printf("%d    ", *((s.base)+i));
  }
  printf("delete stack\n");
  delet_stack(&s);
  for(i=0; i< (s.top - s.base);i++)
  {
    printf("num is :%d\n", i);
    printf("%d    ", *((s.base)+i));
  }
  printf("destory stack\n");
  destory_stack(&s);
}

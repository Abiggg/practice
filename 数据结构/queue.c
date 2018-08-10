#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *pNext;
}Node_S, *pNode_S;

typedef struct QUEUE
{
  pNode_S rear;
  pNode_S front;
}QUEUE_S,*pQUEUE_S;

void init_Queue(pQUEUE_S q)
{
    q->rear = q->front = (pNode_S)malloc(sizeof(Node_S));
    if(!q->rear)
    {
      return ;
    }
    q->rear->pNext =  NULL;
}

void inset_Queue(pQUEUE_S q, int e)
{
   pNode_S p;
   p = (pNode_S)malloc(sizeof(Node_S));
   if(!p)
   {
     return ;
   }
   p->data = e;
   p->pNext = NULL;
   q->rear->pNext = p;
   q->rear = p;
}

void out_Queue(pQUEUE_S q, int* value)
{
  pNode_S p;
  if(q->rear == q->front)
  {
    return ;
  }

  p = q->front->pNext;
  *value = p->data;

  q->front->pNext = p->pNext;
  if(q->rear == p) q->rear = q->front;
  free(p);
}

void destroy_Queue(pQUEUE_S q)
{
  while(q->front)
  {
    q->rear = q->front->pNext;
    free(q->rear);
    q->front = q->rear;
  }
}

void main()
{
  int a[10] = {1,3,5,6,8,2,1,4,8,1};
  int i;
  QUEUE_S q;
  int value = 0;
  printf("init queue\n");
  init_Queue(&q);

  printf("insert queue\n");
  for(i=0;i < sizeof(a)/sizeof(int);i++)
  {
    inset_Queue(&q, a[i]);
  }

  while(q.front != q.rear)
  {
    out_Queue(&q, &value);
    printf("%d\n", value);
  }

  destroy_Queue(&q);
}

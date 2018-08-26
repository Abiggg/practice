#include <stdio.h>
#include <stdlib.h>

typedef struct ArcNode
{
  int adjvex;
  struct ArcNode *next;
}ArcNode_S;

typedef struct VNnode
{
  int data;
  ArcNode_S *firstArc;
}VNode_S;

void CreatGraph(int n, VNode_S G[])
{
  int i,e;
  ArcNode_S *p, *q;
  printf("intput the information of the vertex\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&(G[i].data));
  }
  for(i=0;i<n;i++)
  {
    printf("creat the edges for the %d th vertex\n",i);
    scanf("%d", &e);
    while(e!=-1)
    {
      p = (ArcNode_S *)malloc(sizeof(ArcNode_S));
      p->next = NULL;
      p->adjvex = e;
      if(G[i].firstArc == NULL)
      {
        G[i].firstArc = p;
      }
      else
      {
        q->next =p;
      }
      q = p;
      scanf("%d", &e);
    }
  }

}

int FirtstAdj(VNode_S G[] ,int v)
{
  if(G[v].firstArc != NULL)
  {
    return (G[v].firstArc)->adjvex;
  }
  else
  {
    return -1;
  }
}

int visited[5] = {0};

int NextAdj(VNode_S G[], int v)
{
  ArcNode_S *p;
  p = (G[v].firstArc);
  while(p!=NULL)
  {
    if(visited[p->adjvex])
    {
      p = p->next;
    }
    else
    {
      return p->adjvex;
    }
    return -1;
  }
}

void DFS(VNode_S G[] ,int v)
{
  int w;
  printf("%d\n", G[v].data);
  visited[v] = 1;
  w = FirtstAdj(G,v);
  while (w != -1)
  {
    if(visited[w] == 0)
    {
      DFS(G, w);
    }
    w = NextAdj(G, v);
  }
}

void main()
{
  VNode_S G[5];
  CreatGraph(5, G);
  DFS(G, 0);
}

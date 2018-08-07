#include <stdio.h>

int test[] = {6, 5, 3, 1 ,8, 7 ,2, 4};

void swap(int A[], int i, int j)
{
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

void printA(int A[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("%8d", A[i]);
  }
  printf("\n");
}

void BubbleSort(int A[],int n)
{
  int i;
  int j;
  int count = 0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(A[j] > A[j+1])
      {
        swap(A, j, j+1);
        count++ ;
      }
    }
  }
  printA(A, n);
  printf("the total count is :%d\n", count);
}

void CockTailSort(int A[], int n)
{
  int left = 0;
  int right = n -1;
  int count = 0;
  while(left < right)
  {
    for(int i=left;i<right;i++)
    {
      if(A[i] > A[i+1])
      {
        swap(A, i, i+1);
        count++ ;
      }
    }
    right --;
    for(int j = right;j>left;j--)
    {
      if(A[j] < A[j-1])
      {
        swap(A, j, j-1);
        count++ ;
      }
    }
    left ++;
  }
  printA(A, n);
  printf("the total count is :%d\n", count);
}

void SelectionSort(int A[], int n)
{
  int left = 0;
  for(int i = left;i<n;i++)
  {
      int min = left;
      for(int j = left+1;j<n;j++)
      {
        if(A[j] < A[min])
        {
          min = j;
        }
      }
      swap(A, left, min);
      left ++;
  }
  printA(A, n);
}

void InsertionSort(int A[], int n)
{
  for(int i = 1;i < n;i++)
  {
    int get = A[i];
    for(int j = 0;j<i;j++)
    {
      if(A[j]> A[i])
      {
        for(int k = i;k>j;k--)
        {
          A[k] = A[k-1];
        }
        A[j] = get;
      }
    }
  }
  printA(A, n);
}

int Partition(int A[], int left, int right)
{
  int pivot = A[right];
  int tail = left-1;
  for(int i = left;i<right;i++)
  {
    if(A[i] < pivot)
    {
      swap(A, ++tail, i);
    }
  }
  swap(A, tail+1, right);
  return tail+1;
}

void QuickSort(int A[], int left, int right)
{
  if(left >= right)
  {
    return;
  }
  int pivot_index = Partition(A, left, right);
  QuickSort(A, left, pivot_index-1);
  QuickSort(A, pivot_index + 1, right);
  printA(A, right+1);
}

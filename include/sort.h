#ifndef __SORT_H__
#define __SORT_H__

typedef enum
{
    BUBBLESORT = 0,
    CORTTAILSORT,
    SHELLSORT,
    SELECTIONSORT,
    INSERTIONSROT,
    QUICKSORT
}SORT_TYPE_E;

void BubbleSort(int A[], int n);

void CockTailSort(int A[], int n);

void SelectionSort(int A[], int n);

void InsertionSort(int A[], int n);

void QuickSort(int A[], int left, int right);

#endif

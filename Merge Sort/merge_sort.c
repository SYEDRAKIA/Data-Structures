#include <stdio.h>

void printArray(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid,int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++){
        A[i]=B[i];
    }
}

void mergeSort(int A[],int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,mid,low,high);
    }
}
int main()
{
    int A[] = {9, 14, 4, 8, 7, 5, 6};
    int size = 7;
    printArray(A, size);
    mergeSort(A, 0, 6);
    printArray(A, size);
    return 0;
}
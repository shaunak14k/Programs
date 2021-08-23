#include<stdio.h>
#include<conio.h>

void quick_sort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int*);

int main()
{
    int A[10],n,i=0;

    printf("\n Enter number of elements : ");
    scanf("%d",&n);

    printf("\n Enter the numbers : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }

    quick_sort(A,0,7);

    printf("\n\n Sorted elements : ");
    for(i=0; i<n; i++)
    {
        printf("%4d",A[i]);
    }

    printf("\n\n");
    getch();

    return 0;
}

void quick_sort(int *A, int start, int end)
{
    if(start < end)
    {
        int partitionIndex = partition(A, start, end);  // calling partition
        quick_sort(A, start, partitionIndex-1);
        quick_sort(A, partitionIndex+1, end);
    }
}

int partition(int *A, int start, int end)
{
    int pivot = A[end];
    int partitionIndex = start; // Set partition index as start initially
    int i;

    for(i=start; i<end; i++)
    {
        if(A[i] <= pivot)
        {
            swap(&A[i], &A[partitionIndex]);  // Swap if element is less than pivot
            partitionIndex++;
        }
    }       
    swap(&A[partitionIndex], &A[end]);    // Swap pivot with element at partition index

    return partitionIndex;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

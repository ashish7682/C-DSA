//.....................Quick Sort.................//

#include <stdio.h>

//................Function to swap elements.................//

void swap(int array[],int a, int b)
{

    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

//..............Function to find the parition postion............//
int partition(int array[], int low, int high)
{
    //........Select the right most element as pivot.............//
    int pivot = array[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (array[i] <= pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(array,i,j);
        }
        swap(array,j,low);
        return j;
    }
}

void Quicksort(int array[],int low,int high)
{
    if(low<high)
    {
        int pivot=partition(array,low,high);
        Quicksort(array,low,pivot-1);
        Quicksort(array,pivot+1,high);
    }
}

void printArray(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

int main()
{
    int data[]={8,7,2,1,0,9,6};
    int n=sizeof(data)/sizeof(data[0]);
    printf("Unsorted array: ");
    printArray(data,n);
    Quicksort(data,0,n-1);
    printf("Sorted array in Ascending order:");
    printArray(data,n);
}
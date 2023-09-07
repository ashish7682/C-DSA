//...................... Insertion sort in C.......................//

#include <stdio.h>

//.................. Function to print an array.....................//



void insertionSort(int array[], int size)
{
  for (int i = 1; i < size; i++)
  {
    int temp = array[i];
    int j = i - 1;

    // For descending order, change j<array[j] to j>array[j].
    while (array[j] > temp && j >= 0)
    {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = temp;
  }
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Driver code
int main()
{
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  printf("Sorted array in ascending order:\n");
  printArray(data, size);
}
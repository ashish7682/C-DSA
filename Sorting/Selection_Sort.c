//................. Selection sort in C..................//

#include <stdio.h>

// ......function to swap the the position of two elements.........

void swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min = step;
    for (int i = step + 1; i < size; i++) {

      // .......Select the minimum element in each loop...........

      if (array[i] < array[min])
           min= i;
    }

    //.......... put min at the correct position..........//

    swap(array[min], array[step]);

  }
}

// .........function to print an array..............//

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

//...........Main Method..................//

int main() {
  int data[] = {20, 12, 10, 15, 2};
  int size = sizeof(data) / sizeof(data[0]);
  selectionSort(data, size);
  printf("Sorted array in Acsending Order:\n");
  printArray(data, size);
}
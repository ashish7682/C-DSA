//..................Optimized Bubble sort in C....................//

#include<stdio.h>

//...........Perform the Bubble Sort................//
void bubblesort(int array[],int n)
{
    //---------Loop to access each array element--------//

    for(int i=0;i<n-1;i++)
    {

        //-----------Check if swapping occurs------------//
        int swapped=0;
        for(int j=0;j<n-i-1;j++)
        {
            //comapre two array element and and swaped to in descending order//
            if(array[j]>array[j+1])
            {
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;

                swapped=1;
            }
        }
    

    //-------------------No Swapping means the already sorted-----------------//
    if(swapped==0)
    {
        break;
    }

 }
}

//...............print Array....................//

void printArray(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

//.................Main method.....................//

int main()
{

    int data[]={-2,45,0,11,-9};
    int n=sizeof(data)/sizeof(data[0]);

    bubblesort(data,n);

    printf("Sorted Array in Ascending Order:\n");
    printArray(data,n);
}

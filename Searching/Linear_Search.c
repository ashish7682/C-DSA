#include<stdio.h>

int LinearSearch(int array[],int n,int element)
{
    for(int i=0;i<n;i++)
    {
        if(array[i]==element)
        {
            return i;
        }
    }   
            return -1;
        
    
}

int main()
{
    //..............Both Sorted and Unsorted array for LinearSearch...................//
    int n;
    printf("Enter numebr of element: ");
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++)
    {
         printf("Enter data:");
         scanf("%d",&array[i]);
    }
    printf("Enter number to be search:");
    int element;
    scanf("%d",&element);
    int SearchIndex=LinearSearch(array,n,element);
    printf("The elemnt %d was found at index %d\n",element,SearchIndex);
    return 0;
    
}


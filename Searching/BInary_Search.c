#include<stdio.h>
int BinarySearch(int arr[],int size ,int element)
{
    int low,mid,high;
    low=0;
    high=size-1;

    //...............Keeping Search until low<=high.................//

    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==element)
        {
            return mid;
        }
        if(arr[mid]<element)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}

int main()
{
    //..............Only sorted Array for BinarySearch..................//

    int arr[]={1,3,5,12,15,20,26,38,48,56,67,78,89};
    int size=sizeof(arr)/sizeof(int);
    int element=38;
    int SearchIndex=BinarySearch(arr,size,element);
    printf("The elemnt %d was found at index %d \n",element,SearchIndex); 
    return 0;

}
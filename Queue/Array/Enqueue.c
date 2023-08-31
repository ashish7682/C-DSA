#include<stdio.h>
#define N 5
int queue[N];

int rear= -1;
int front =0;

void enqueue(int data)
{
    if(rear==(N-1))
    {
     printf(" Queue Overflow\n");
    }
    else
    {
        queue[++rear]=data;
    }
}

void Display()
{
    if(rear== -1)
    {
        printf("Queue is empty.");
    }
    else
    {
        for(int i=front;i<5;i++)
        {
            printf("%d",queue[i]);
             printf("\t");
        }
       
    }
}

int main()
{
    int n;
    printf("number of element: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int d;
        printf("Enter data: ");
        scanf("%d",&d);
        enqueue(d);
    }
    Display();
}
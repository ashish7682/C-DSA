#include<stdio.h>
#define N 6
int queue[N];

int rear=-1;
int front=0;

void enqueue(int data)
{
    if(rear==(6-1))
    {
        printf("Queue is Overflow\n");
    }
    else
    {
        queue[++rear]=data;
    }
}

void peek()
{
    if(rear==-1)
    {
        printf("The queue is empty");
    }
    else
    {
        printf("peek element :%d",queue[front]);
    }
}

void Display()
{
    if(rear==-1)
    {
        printf("The queue is empty");
    }
    else
    {
        for(int i=front;i<6;i++)
        {
            printf("%d\t",queue[i]);
            
        }
        printf("\n");

    }
}


int main()
{
    int n;
    printf("Enter number of data: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        enqueue(data);
        
    }
    Display();
    peek();
    printf("\n");
    Display();
}

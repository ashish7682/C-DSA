#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];
int front=-1;
int rear=-1;
void enqeue(int x)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear + 1)% N==front)
    {
        printf("Queue is full");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is Empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%N;
    }
}
void display()
{
    if(rear==-1)
    {
        printf("Empty");
    }else
    {
        for(int i=front;i<5;i++)
        {
            printf("%d",queue[i]);
        }
    }

}
int main()
{
    int n;
    printf("Number of element: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int d;
        printf("Enter data:");
        scanf("%d",&d);
        enqeue(d);
    }
    display();
    return 0;
}

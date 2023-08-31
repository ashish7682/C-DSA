#include<stdio.h>
#define N 5

int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if(rear==N-1)
    {
        printf("Overflow Occurs");
    }
    else if(front == -1 && rear ==  -1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if(front == rear)
    {
     front = rear = -1;                                                                                                                                         
    }
    else
    {
      printf("%d",queue[rear]);
      front++;
    }
}

void Display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(int i=front;i<rear+1;i++)
        {
            printf("%d",queue[i]);
        }
    }

}

void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("%d",queue[front]);
    }
}

int main()
{
    int n;
    printf("Enter no. of data");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Enter data");
        scanf("%d", &x);
        enque(x);
    }
    Display();
    dequeue();
    Display();
}
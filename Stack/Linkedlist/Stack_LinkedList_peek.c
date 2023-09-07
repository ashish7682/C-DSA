#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Push(struct Node **head,int data)
{
    struct Node  *newNode=(struct Node *)malloc(sizeof(struct Node));

    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL)
    {
        *head=newNode;
        return;
    }
   else{
    struct Node *temp=*head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
     temp->next=newNode;
}
}

void peek(struct Node **head)
{
    struct Node *temp=*head;
    if (head == NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("peek element: %d\n", temp->data);
    }
}


void Display(struct Node *node)
{
    if(node==NULL)
    {
     printf("Stack is empty");
     return;
    }
    
    while(node!=NULL)
    {
      printf("%d",node->data);
      node=node->next;
      printf("\t");
    }

    
    
}

int main()
{
    int n;
    struct Node *head=NULL;
    printf("Enter number of data: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int d;
        printf("Enter data:");
        scanf("%d",&d);
        Push(&head,d);
    }
    peek(&head);
    Display(head);
    return 0;
}
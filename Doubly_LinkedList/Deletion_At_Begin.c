#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void InsertLast(struct Node **head,struct Node **prev,int data)
{
   struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
   newNode->data=data;
   newNode->next=NULL;
   newNode->prev=NULL;
   
    if(*head==NULL)
    {
        (*head)=newNode;
    }
    else{
       struct Node *temp=*head;
       while(temp->next!=NULL)
       {
        temp=temp->next;
       }
       temp->next=newNode;
       newNode->prev=temp;
       temp=newNode;
    }
     
}


void Delete(struct Node **head,struct Node **prev)
{
    if(*head==NULL)
    {
        printf("Linked List is empty");
    }
    else if((*head)->next==NULL)
    {
        *head=NULL;
    }
    else
    {
    struct Node *temp=*head;
    temp=temp->next;
    temp->prev=NULL;
    (*head)=temp;
    }
}

void Display(struct Node *node)
{
    while(node!=NULL)
    {
        printf("%d",node->data);
        node=node->next;
        printf("->");
    }
    printf("NULL");
}

int main()
{
    int n;
    struct Node *head=NULL;
    struct Node  *prev=NULL;
    printf("Enter Number of data: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int d;
        printf("Enter data:");
        scanf("%d",&d);
        InsertLast(&head,&prev,d);
    }
    Delete(&head,&prev);
    Display(head);
    return 0;
}
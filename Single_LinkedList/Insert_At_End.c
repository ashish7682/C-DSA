#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void InsertLast(struct Node **head,int data)
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
    printf("Enter Number of data: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int d;
        printf("Enter data: ");
        scanf("%d",&d);
        InsertLast(&head,d);
    }
    Display(head);
    return 0;
}
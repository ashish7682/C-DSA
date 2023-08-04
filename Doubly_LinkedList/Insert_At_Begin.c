#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void InsertFirst(struct Node **head,struct Node **prev,int data)
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
       (*head)->prev=newNode;
       newNode->next=*head;
       *head=newNode;
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
        InsertFirst(&head,&prev,d);
    }
    Display(head);
    return 0;
}
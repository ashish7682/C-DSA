#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void InsertFirst(struct Node **head, struct Node **tail, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        newNode->next = *head;
    }
    else
    {
      (*tail)->next=newNode;
      *tail=newNode;
      newNode->next=*head;
     
    }
}

void Delete(struct Node **head,struct Node **tail)
{
    struct Node *temp=*head;
    if(*head==NULL)
    {
        printf("Linked List is empty,nothing to be delete");
        return;
    }
    else if(*head==*tail)
    {
      *head =NULL;
      *tail=NULL;    
    }else
    {
        while(temp->next!=*tail)
        {
            temp=temp->next;
        }
        temp->next=*head;
        *tail=temp;
    }

}

void Display(struct Node *node)
{
    struct Node *temp = node;
    do
    {
        printf("%d", node->data);
        printf("->");
        node = node->next;
    } while (node != temp);
    printf("NULL");
}

int main()
{
    int n;
    struct Node *head = NULL;
    struct Node *tail = NULL;
    printf("Enter Number of data: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int d;
        printf("enter data: ");
        scanf("%d", &d);
        InsertFirst(&head, &tail, d);
    }
    Delete(&head,&tail);
    Display(head);
    return 0;
}
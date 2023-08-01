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
    struct Node *ptr=(temp)->next;
    if(*head==NULL)
    {
        printf("Linked List is empty,nothing to be delete");
        return;
    }
    else if((*head)->next==*head)
    {
        *head=NULL;
        *tail=NULL;
        printf("NULL");
    }
    else
    {
        int p;
        printf("Enter number of position: ");
        scanf("%d",&p);
        struct Node *temp=*head;
       // struct Node *ptr=temp->next;

        for(int i=1;i<p-1;i++)
        {
            temp=temp->next;
        }
         temp->next=(temp->next)->next;
        

        
        //........This is optonal..........(free(temp);).....................
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
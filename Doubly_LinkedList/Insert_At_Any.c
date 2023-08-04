#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void InsertLast(struct Node **head, struct Node **prev, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        (*head) = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
}
void Display(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
        printf("->");
    }
    printf("NULL");
}

void AtAny(struct Node **head, struct Node **prev)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    int p, d;
    printf("Enter position and data:");
    scanf("%d%d", &p, &d);

    newNode->data=d;
    newNode->prev=NULL;
    newNode->next=NULL;

    struct Node *temp = *head;

    if(p==1)
    {
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
    }
     else{
    for (int i = 1; i < p - 1; i++)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    newNode->next=temp->next;
    temp->next=newNode;
    (temp->next)->prev=newNode;
   }
}

int main()
{
    int n;
    struct Node *head = NULL;
    struct Node *prev = NULL;
    printf("Enter Number of data: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int d;
        printf("Enter data:");
        scanf("%d", &d);
        InsertLast(&head, &prev, d);
    }
    AtAny(&head,&prev);
    Display(head);
    return 0;
}
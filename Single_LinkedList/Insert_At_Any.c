#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void InsertLast(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void AtAny(struct Node **head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    int p, d;
    printf("enter position and data : ");
    scanf("%d%d", &p, &d);

    newNode->data = d;
    newNode->next = NULL;

    struct Node *temp = *head;
    if (p == 1 || head == NULL)
    {
        newNode->next = *head;
        *head=newNode;
        //return;
    }
    else if(p<0)
    {
        printf("Invalid input\n");
       // return;
    }
   else{
    for (int i = 1; i < p - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
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

int main()
{
    int n;
    struct Node *head = NULL;
    printf("Enter Number of data: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int d;
        printf("Enter data: ");
        scanf("%d", &d);
        InsertLast(&head, d);
    }
    AtAny(&head);
    Display(head);
    return 0;
}
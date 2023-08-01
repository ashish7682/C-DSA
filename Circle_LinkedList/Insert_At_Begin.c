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
    newNode->next=NULL;
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        newNode->next = *head;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
        (*tail)->next = *head;
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
    Display(head);
    return 0;
}
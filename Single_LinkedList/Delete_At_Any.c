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
void Delete(struct Node **head)
{
    struct Node *temp = *head;
    if (*head == NULL)
    {
        printf("Linked List is empty");
        return;
    }
    else
    {
        int p;
        printf("Enter position No.:");
        scanf("%d", &p);
        if (p < 0)
        {
            printf("Invalid Input");
        }
        else if(p==1)
        {
            *head=(*head)->next;
        }
        else
        {
            for (int i = 1; i < p - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = (temp->next)->next;
        }
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
    Delete(&head);
    Display(head);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void InsertLast(struct Node **head, struct Node **tail, int data)
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
        (*tail)->next = newNode;
        *tail = newNode;
        newNode->next = *head;
    }
}

/*void InsertLast(struct Node **head, int data)
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
}*/

void AtAny(struct Node **head, struct Node **tail)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    int p, d;
    printf("enter position and data : ");
    scanf("%d%d", &p, &d);

    newNode->data = d;
    newNode->next = NULL;

    struct Node *temp = *head;

    if (p == 1)
    {
        newNode->next = *head;
        *head = newNode;
        (*tail)->next = *head;
    }
    else
    {
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
        InsertLast(&head, &tail, d);
    }
    AtAny(&head, &tail);
    Display(head);

    return 0;
}
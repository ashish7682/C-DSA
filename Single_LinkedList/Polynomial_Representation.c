#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int coff;
    int pow;

    struct Node *next;
};

void createNode(int val, int power, struct Node **head)
{
    struct Node *temp = NULL;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coff = val;
    newNode->pow = power;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        temp = newNode;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        temp = newNode;
    }
}


void printPoly(struct Node *ptr)
{
    while (ptr != NULL)
    {
        if (ptr->coff > 0)
            printf("+%dx^%d ", ptr->coff, ptr->pow);
        else
            printf("%dx^%d ", ptr->coff);

        ptr = ptr->next;
    }
}


struct Node *addPolynomial(struct Node *poly1, struct Node *poly2)
{
    struct Node *head1 = poly1;
    struct Node *head2 = poly2;
    struct Node *res = NULL;
    struct Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (head1->pow == head2->pow)
        {
            newNode->coff = head1->coff + head2->coff;
            newNode->pow = head1->pow;
            newNode->next = NULL;

            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->pow > head2->pow)
        {
            newNode->coff = head1->coff;
            newNode->pow = head1->pow;
            newNode->next = NULL;

            head1 = head1->next;
        }
        else
        {
            newNode->coff = head2->coff;
            newNode->pow = head2->pow;
            newNode->next = NULL;
            head2 = head2->next;
        }

        if (res == NULL)
        {
            res = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (head1 != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coff = head1->coff;
        newNode->pow = head1->pow;
        newNode->next = NULL;
        if (res == NULL)
        {
            res = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coff = head2->coff;
        newNode->pow = head2->pow;
        newNode->next = NULL;
        if (res == NULL)
        {
            res = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        head2 = head2->next;
    }

    return res;
}


int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL;

    createNode(3, 4, &poly1);
    createNode(4, 1, &poly1);
    createNode(7, 0, &poly1);

    createNode(5, 2, &poly2);
    createNode(9, 1, &poly2);

    printf("\nPoly1:");
    printPoly(poly1);

    printf("\nPoly2:");
    printPoly(poly2);

    struct Node *res = addPolynomial(poly1, poly2);
    printf("\nAddition: ");
    printPoly(res);


    return 0;
}
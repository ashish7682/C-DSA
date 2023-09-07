#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial
{
    int coff;
    int pow;

    struct Polynomial *next;
} Poly;

void createNode(int val, int power, Poly **head)
{
    Poly *tail = NULL;

    Poly *newNode = (Poly *)malloc(sizeof(Poly));
    newNode->coff = val;
    newNode->pow = power;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        tail = newNode;
    }
    else
    {
        tail = *head;
        while (tail->next != NULL)
            tail = tail->next;

        tail->next = newNode;
        tail = newNode;
    }
}

void printPoly(Poly *temp)
{
    while (temp != NULL)
    {
        if (temp->coff > 0)
            printf("+%dx^%d ", temp->coff, temp->pow);
        else
            printf("%dx^%d ", temp->coff);

        temp = temp->next;
    }
}


int main()
{
    Poly *poly1 = NULL, *poly2 = NULL;

    createNode(3, 4, &poly1);
    createNode(4, 1, &poly1);
    createNode(7, 0, &poly1);

    createNode(5, 2, &poly2);
    createNode(9, 1, &poly2);

    printf("\nPoly1:");
    printPoly(poly1);

    printf("\nPoly2:");
    printPoly(poly2);

    return 0;
}
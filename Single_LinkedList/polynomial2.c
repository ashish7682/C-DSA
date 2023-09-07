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

Poly *addPolynomial(Poly *poly1, Poly *poly2)
{
    Poly *head1 = poly1;
    Poly *head2 = poly2;
    Poly *res = NULL;
    Poly *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        Poly *newNode = (Poly *)malloc(sizeof(Poly));
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
        Poly *newNode = (Poly *)malloc(sizeof(Poly));
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
        Poly *newNode = (Poly *)malloc(sizeof(Poly));
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
        head1 = head2->next;
    }

    return res;
}
Poly *subPolynomial(Poly *poly1, Poly *poly2)
{
    Poly *head1 = poly1;
    Poly *head2 = poly2;
    Poly *res = NULL;
    Poly *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        Poly *newNode = (Poly *)malloc(sizeof(Poly));
        if (head1->pow == head2->pow)
        {
            newNode->coff = head1->coff - head2->coff;
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
        Poly *newNode = (Poly *)malloc(sizeof(Poly));
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
        Poly *newNode = (Poly *)malloc(sizeof(Poly));
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
        head1 = head2->next;
    }

    return res;
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

    Poly *res = addPolynomial(poly1, poly2);
    printf("\nAddition: ");
    printPoly(res);

   res = subPolynomial(poly1, poly2);
    printf("\nSubtraction: ");
    printPoly(res);

    return 0;
}

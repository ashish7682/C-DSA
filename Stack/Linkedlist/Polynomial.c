#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function to create a new term with the given coefficient and exponent
Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a new term at the end of the linked list
void insertTerm(Term** poly, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to add two polynomials and store the result in a new linked list
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent == poly2->exponent) {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0) {
                insertTerm(&result, sumCoeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
    }

    // Copy any remaining terms from poly1 and poly2, if any
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }

    while (poly != NULL) {
        printf("%d", poly->coefficient);
        if (poly->exponent != 0) {
            printf("x^%d", poly->exponent);
        }
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
}

// Function to free the memory occupied by the linked list
void freeLinkedList(Term* poly) {
    Term* current = poly;
    while (current != NULL) {
        Term* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Creating polynomial 1: 3x^2 + 2x + 1
    Term* poly1 = NULL;
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 2, 1);
    insertTerm(&poly1, 1, 0);

    // Creating polynomial 2: 4x^3 + 2x^2 + 5
    Term* poly2 = NULL;
    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 5, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("\n");

    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    printf("\n");

    Term* result = addPolynomials(poly1, poly2);
    printf("Result: ");
    displayPolynomial(result);
    printf("\n");


    return 0;
}

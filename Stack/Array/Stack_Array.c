#include <stdio.h>
#include <stdlib.h>
#define N 5

void push();
void pop();
void peek();
void Display();

int top = -1, stack[N];

void push()
{

    int x;
    printf("Enter data : ");
    scanf("%d", &x);

    if (top == N - 1)
    {
        printf("Overflow Condition\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    int item;
    if (top == (-1))
    {
        printf("Underflow condition");
    }
    else
    {
        item = stack[top];
        top--;
        printf("%d", item);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d", stack[top]);
    }
}

void Display()
{
    printf("Display all element in the stack :");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
    
}

int main()
{
    int choice;
    do
    {
        printf("Enter your choice 1:push, 2:pop, 3:peek,4:Display: ");
//        printf("\n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            Display();
            break;

        default:
            printf("Invalid choice");
        }
    } while (choice != 0);

    return 0;
}
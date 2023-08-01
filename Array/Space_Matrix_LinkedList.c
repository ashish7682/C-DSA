#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int row;
    int col;
    int data;
    struct  Node *next;
};

struct Node *head=NULL,*temp;

void Add(int row,int col,int data)
{
  struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
  newNode->row=row;
  newNode->col=col;
  newNode->data=data;
  newNode->next=NULL;

   if(head==NULL)
   {
    head=newNode;
    temp=head;
   }
   else
   {
    temp->next=newNode;
    temp=newNode;
   }

}

void Display(struct Node *ptr)
{
    ptr=head;
    printf("Row: ");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->row);
        ptr=ptr->next;
    }
    printf("\n");

    ptr=head;
    printf("col: ");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->col);
        ptr=ptr->next;
    }
    printf("\n");

    ptr=head;
    printf("Data: ");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main()
{
    int Sparse[4][5]={{0,0,3,0,4},{0,0,5,7,0},{0,0,0,0,0},{0,2,6,0,0}};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(Sparse[i][j]!=0)
            {
                Add(i,j,Sparse[i][j]);
            }
        }
    }
  Display(head);

}
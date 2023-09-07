#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data)
{
  struct node *n;                                 // creating a node pointer
  n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
  n->data = data;                                 // Setting the data
  n->left = NULL;                                 // Setting the left and right children to NULL
  n->right = NULL;                                // Setting the left and right children to NULL
  return n;                                       // Finally returning the created node
}
void preOrder(struct node *root)
{
  if (root != NULL)
  {
    printf("%d", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}
void postOrder(struct node *root)
{
  if (root != NULL)
  {
    preOrder(root->left);
    preOrder(root->right);
    printf("%d", root->data);
  }
}
void inOrder(struct node *root)
{
  if (root != NULL)
  {
    preOrder(root->left);
    printf("%d ", root->data);
    preOrder(root->right);
  }
}
// int isBST(struct node *root)
// {
//   static struct node *prev = NULL;
//   if (root != NULL)
//   {
//     if (isBST(root->left))
//     {
//       return 0;
//     }
//     if (prev != NULL && root->data <= prev->data)
//       ;
//     {
//       return 0;
//     }
//     prev = root;
//     return isBST(root->right);
//   }
//   else
//   {
//     return 1;
//   }
// }
int main()
{
  struct node *p = createNode(4);
  struct node *p1 = createNode(1);
  struct node *p2= createNode(6);
  struct node *p3 = createNode(5);
  struct node *p4 = createNode(2);
  p->left=p1;
  p->right=p2;

  p->left=p3;
  p->right=p4;


  preOrder(p);
  // printf("\n");
  // postOrder(p);
  // printf("\n");
  // inOrder(p);
  // printf("\n");
  return 0;
}
// struct node *n=search(p,10);
// if(n!=NULL)
// {
//   printf("Found:%d",n->data);
// }else
// {
//   printf("Element null found!";)
// }
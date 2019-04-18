/* 

트리 순화 결과

preorder, inorder, postorder.

*/

#include <stdio.h>

#include <malloc.h>

 

struct Tree

{

  int data;

  

  Tree *L = NULL;

  Tree *R = NULL;

};

 

void preorder(Tree *node)

{

  if(node == NULL)  return;

  

  printf("%d ", node->data);

  

 

  preorder(node->L);

  preorder(node->R);

}

 

void inorder(Tree *node)

{

  if(node == NULL)  return;

 

  inorder(node->L);

  

  printf("%d ", node->data);

  

  inorder(node->R);

}

 

void postorder(Tree *node)

{

  if(node == NULL)  return;

  

  postorder(node->L);

  postorder(node->R);

  printf("%d ", node->data);

}

 

 

int main() {

 

  int n;

  int r,left,right;

  int arr[100];

  Tree node[100];

 

 

  scanf("%d", &n);

 

  for(int i=0;i<n;i++)

  {

    scanf("%d %d %d", &r, &left, &right);

    

    node[r].data = r;

  

    if(left == -1 && right == -1){}

    else if(right == -1)

    {

      node[r].L = &node[left];

      node[left].data = left;

    }

    else if(left == -1)

    {

      node[r].R = &node[right];

      node[right].data = right;

    }

    else

    {

      node[r].L = &node[left];

      node[left].data = left;

    

      node[r].R = &node[right];

      node[right].data = right;

    }

  }

  

  preorder(&node[0]);

  printf("\n");

  inorder(&node[0]);

  printf("\n");

  postorder(&node[0]);

  

  

  

  return 0;

}
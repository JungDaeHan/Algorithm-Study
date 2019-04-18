/*

Ʈ�������� �Ÿ�

Ʈ���� �־�����, �� ��� X, Y�� �־��� ��, �� �� ��� ������ �Ÿ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

Ʈ�������� �� ��带 �մ� ��ΰ� �����ϱ� ������, ������ �׻� �����ϴٴ� ���� �����Ѵ�. 

 
�Է�

ù ��° �ٿ� Ʈ���� ��� ���� n, �� ��� X, Y�� ��ȣ�� �־�����. 

( 0 �� X, Y �� n < 1000 ) �� ��° �ٺ��� Ʈ���� ���� ������ �־�����. 

�� ���� 2���� ���� a, b�� �̷������, �̴� ��� a�� ��� b�� �θ����� ���� �ǹ��Ѵ�. ��Ʈ�� ��� 0�̶�� �����Ѵ�.  


���

�� ��� X, Y ������ �Ÿ��� ����Ѵ�.


*/

#include <stdio.h>

struct Tree
{
  int data;
  
  Tree *parent = NULL;
};

/*
int findDistance(int edge[][1010], int X, int Y, int *distance,int h)
{
  *distance = h;
  
  if(edge[X][Y] == 1)
    return *distance;
  
  for(int i=0;i<1001;i++)
  {
    if(edge[X][i] == 1)
    {
      edge[X][i] = 0;
      edge[i][X] = 0;
      
      findDistance(edge,i,Y,distance,h+1); 
    }
    
  }
  
  //return *distance;
}*/

int main() {

  int n,X,Y;
  int node1, node2;
  int distance=0;
  int dis1[1001],dis2[1001];
  struct Tree tree[1010];
  struct Tree *tmp = NULL;
  int idx1=0,idx2=0;
  scanf("%d %d %d", &n, &X, &Y);
  
  tree[0].data = 0;
  
  for(int i=0;i<n-1;i++)
  {
    scanf("%d %d", &node1, &node2);
    
    tree[node2].data = node2;
    tree[node2].parent = &tree[node1];
  }
  
  tmp = tree[X].parent;
  
  while(tmp != NULL)
  {
    dis1[idx1++] = tmp->data;
    tmp = tmp->parent;
  }
  for(int i=0;i<idx1;i++)
    printf("%d ", dis1[i]);
  printf("\n");
  for(int i=0;i<idx1;i++)
  {
    if(dis1[i] == tree[Y].data)
    {
      printf("%d", i+1);
      return 0;
    }
  }
  
  tmp = tree[Y].parent;
  idx2=1;
  
  while(tmp != NULL)
  {
    if(tmp->data == tree[X].data)
    {
      printf("%d", idx2);
      return 0;
    }
    idx2++;
    tmp = tmp->parent;
  }
  
  tmp = tree[Y].parent;
  idx2=1;
  
  while(1)
  {
    for(int i=0;i<idx1;i++)
    {
      if(dis1[i] == tmp->data)
      {
        printf("%d", i+1 + idx2);
        return 0;
      }
    }
    idx2++;
    tmp = tmp->parent;
  }
  
  

  return 0;
}
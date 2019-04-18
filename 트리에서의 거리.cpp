/*

트리에서의 거리

트리가 주어지고, 두 노드 X, Y가 주어질 때, 이 두 노드 사이의 거리를 출력하는 프로그램을 작성하시오. 

트리에서는 두 노드를 잇는 경로가 유일하기 때문에, 정답은 항상 유일하다는 것을 참고한다. 

 
입력

첫 번째 줄에 트리의 노드 개수 n, 두 노드 X, Y의 번호가 주어진다. 

( 0 ≤ X, Y ≤ n < 1000 ) 두 번째 줄부터 트리의 간선 정보가 주어진다. 

각 줄은 2개의 숫자 a, b로 이루어지며, 이는 노드 a가 노드 b의 부모노드라는 것을 의미한다. 루트는 노드 0이라고 가정한다.  


출력

두 노드 X, Y 사이의 거리를 출력한다.


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
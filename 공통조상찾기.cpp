/*

공통조상찾기

트리의 노드 X에 대하여 “조상"을 정의할 수 있다. X의 “조상"이란, 루트까지 올라가는 중에 만나는 모든 노드를 말한다. 

예를 들어, 아래와 같이 트리가 주어질 경우, 노드 8의 “조상"은 노드 0, 노드 2, 노드 6이 된다.

트리가 주어지고, 두 노드 X, Y가 주어질 때, 가장 가까운 공통 조상을 찾는 프로그램을 작성하시오.

 
입력

첫 번째 줄에 트리의 노드 개수 n, 두 노드 X, Y의 번호가 주어진다. 

( 1 ≤ X, Y ≤ n ≤ 1000 ) 두 번째 줄부터 트리의 간선 정보가 주어진다. 

각 줄은 2개의 숫자 a, b로 이루어지며, 이는 노드 a가 노드 b의 부모노드라는 것을 의미한다. 루트는 노드 0이라고 가정한다.  


출력

두 노드 X, Y의 공통 조상을 출력한다.

*/

#include <stdio.h>

struct Tree
{
  int num;
  
  Tree * parent = NULL;
  
};



int main() {

  int n,X,Y;
  int node1, node2;
  int data1[1001],data2[1001];
  int i=0;
  int idx1,idx2;
  
  scanf("%d %d %d", &n, &X, &Y);
  
  struct Tree tree[1001];
  tree[0].num = 0;
  struct Tree *tmp = NULL;
  
  for(int i=0;i<n-1;i++)
  {
    scanf("%d %d", &node1, &node2);
    
    tree[node2].parent = &tree[node1];
    tree[node2].num = node2;
  
  }
  
  tmp = &tree[X];
  
  for(i=0; tmp->num != 0 ;i++)
  {
    tmp = tmp->parent;
    data1[i] = tmp->num;
    
  }
  idx1 = i;
  tmp = &tree[Y];
  
  for(i=0; tmp->num != 0 ; i++)
  {
    tmp = tmp->parent;
    data2[i] = tmp->num;
  }
  idx2 = i;
  
  for(i=0 ;i<idx1; i++)
  {
    for(int j=0; j<idx2; j++ )
    {
      if(data1[i] == data2[j])
      {
        printf("%d", data1[i]);
        return 0;
      }
    }
  }

  return 0;
}
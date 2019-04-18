/*

TREEHW

이진트리를 다음의 규칙에 따라 행과 열에 번호가 붙어있는 격자 모양의 틀 속에 그리려고 한다. 이때 다음의 규칙에 따라 그리려고 한다.

-------------------------------------------------------------------

이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다.

한 열에는 한 노드만 존재한다.

임의의 노드의 왼쪽 부트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에 위치하고, 오른쪽 부트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽의 열에 위치한다.

노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.

-------------------------------------------------------------------

이와 같은 규칙에 따라 이진트리를 그릴 때 각 레벨의 너비는 그 레벨에 할당된 노드 중 가장 오른쪽에 위치한 노드의 열 번호에서 가장 왼쪽에 위치한 노드의 열 번호를 뺀 값 더하기 1로 정의한다. 

트리의 레벨은 가장 위쪽에 있는 루트 노드가 1이고 아래로 1씩 증가한다.

우리는 주어진 이진트리를 위의 규칙에 따라 그릴 때에 너비가 가장 넓은 레벨과 그 레벨의 너비를 계산하려고 한다.

너비가 가장 넓은 레벨이 두 개 이상 있을 때는 번호가 작은 레벨을 답으로 한다.

임의의 이진트리가 입력으로 주어질 때 너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하시오
 

입력

첫째 줄에 노드의 개수를 나타내는 정수 N(1 ≤ N ≤ 1,000)이 주어진다. 

다음 N개의 줄에는 각 줄마다 노드 번호와 해당 노드의 왼쪽 자식 노드와 오른쪽 자식 노드의 번호가 순서대로 주어진다. 

노드들의 번호는 1부터 N까지이며, 자식이 없는 경우에는 자식 노드의 번호에 -1이 주어진다.


출력

첫째 줄에 너비가 가장 넓은 레벨과 그 레벨의 너비를 순서대로 출력한다. 너비가 가장 넓은 레벨이 두 개 이상 있을 때에는 번호가 작은 레벨을 출력한다.

*/

#include <cstdio>

using namespace std;

struct Tree
{
  int right;
  int left;
};

Tree tree[1010];
int mat[1010][1010];
int visited[1010];
int idx = 0;

void make2A(int node,int depth)
{
  if(tree[node].left != -1)
    make2A(tree[node].left,depth+1);
    
  mat[depth][idx] = node;
  idx++;    
    
  if(tree[node].right != -1)
    make2A(tree[node].right,depth+1);

}

int main() {

  int N;
  int n,l,r;
  int root;
  
  scanf("%d", &N);
  
  for(int i=0;i<N;i++)
  {
    scanf("%d %d %d", &n, &l, &r);
    if(i==0)
      root = n;
      
    tree[n].left = l;
    tree[n].right = r;
  
  }
  
  make2A(root,0);
  
  if(N==1)
  {
    printf("1 1");
    return 0;
  }
  
  int max = 0;
  int level = 0;
  int tmpa,tmpb;
  
  
  /*
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<N;j++)
      printf("%d ", mat[i][j]);
    printf("\n");
    
  }*/
  
  for(int k=1; k<1010;k++)
  {
    for(int i=0;i<N;i++)
    {
      if(mat[k][i] != 0)
      {
        tmpa = i;
        break;
      }
    }
    
    for(int j=N-1; j>=0 ;j--)
    {
      if(mat[k][j] != 0)
      {
        tmpb = j;
        break;
      }
    }
      
    if(max < tmpb - tmpa + 1)
    { 
      max = tmpb - tmpa +1;
      level = k;
      //printf("%d -- \n", k);
    }
    
  }
  
  printf("%d %d", level+1, max);
  
  
  return 0;
}
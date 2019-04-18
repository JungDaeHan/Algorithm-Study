/*

이분그래프 판별

이분 그래프란, 아래 그림과 같이 정점을 크게 두 집합으로 나눌 수 있는 그래프를 말한다. 

여기서 같은 집합에 속한 정점끼리는 간선이 존재해서는 안된다. 


입력

첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. 

( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다.

각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. (1 ≤ a, b ≤ N)


출력

주어진 그래프가 이분 그래프이면 Yes, 아니면 No를 출력한다.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[1010];
int color[1010]={0,}; 

int DFS(int x,int prior)
{
  int tmp;
  
  if(prior == -1)
    color[x] = 1;
  else if(color[prior] == 2)
    color[x] = 1;
  else if(color[prior] == 1)
    color[x] = 2;
    
  
  for(int i=0;i<Graph[x].size();i++)
  {
    tmp = Graph[x][i];
    
    if(color[tmp] == 0)
    {
      DFS(tmp,x);
    }
  }
  
  
  
}

int main() {

  int N,M;
  int v,e;
  int cnt=0;
  int check;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<M;i++)
  {
    scanf("%d %d", &v, &e);
    
    Graph[v].push_back(e);
    Graph[e].push_back(v);
  }
  
  DFS(v,-1);
    
  for(int i=1 ; i<= N; i++)
  {
    for(check=0; check<Graph[i].size() ; check++)
    {
      if(color[Graph[i][check]] == color[i])
        break;
    }
    
    if(check < Graph[i].size())
    {
      printf("No");
      return 0;
    }
    
  }

  
  printf("Yes");
  
  return 0;
}
/*

CONNECTEDCOMP

정점의 번호가 1부터 N까지 존재하는 그래프 G가 존재하고, 어떠한 정점 집합 S={i, j, k,..} 끼리는 서로 간선으로 연결되어있으며, 

그 이외의 정점 집합(S`)과는 연결되어있지 않을때, 집합 S로 그려지는 그래프를 그래프 G의 연결요소(Connected Component)라고 합니다. 

만약 정점 집합 S와 S`의 합집합이 G의 정점의 전체일 경우, 그래프 G의 연결요소의 개수는 2개입니다. 

방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.


입력
첫째 줄에 정점의 개수 V과 간선의 개수 E이 주어진다. (1 ≤ V ≤ 1,000, 0 ≤ E ≤ V×(N-1)/2) 

둘째 줄부터 E개의 줄에 간선의 양 끝점 v1와 v2가 주어진다. (1 ≤ v1, v2 ≤ N, v1 ≠ v2) 같은 간선은 한 번만 주어진다.


출력

첫째 줄에 연결 요소의 개수를 출력한다.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[1010];
int visited[1010] = {0,};

void DFS(int x)
{
  int tmp;
  
  visited[x] = 1;
  
  for(int i=0;i<Graph[x].size() ; i++)
  {
    tmp = Graph[x][i];
    
    if(visited[tmp] == 0)
      DFS(tmp);
  }
}

int main() {

  int V,E;
  int t,cnt=0;
  
  scanf("%d %d", &V, &E);
  
  for(int i=0;i<E;i++)
  {
    int v1,v2;
    
    scanf("%d %d", &v1, &v2);
    
    Graph[v1].push_back(v2);
    Graph[v2].push_back(v1);
  }
  
  while(1)
  {
    for(t=1;t<=V;t++)
    {
      if(visited[t] == 0)
        break;
    }
    
    if(t >= V+1 )
    {
      printf("%d", cnt);
      return 0;
    }
    
    DFS(t);
    cnt++;
  }
  
  return 0;
}
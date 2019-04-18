/*

이분그래프 판별(by BFS)

이분 그래프란, 아래 그림과 같이 정점을 크게 두 집합으로 나눌 수 있는 그래프를 말한다. 

여기서 같은 집합에 속한 정점끼리는 간선이 존재해서는 안된다. 

그래프가 입력으로 주어질 때, 이 그래프가 이분그래프인지를 판별하는 프로그램을 작성하시오.


입력

첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 

둘째 줄부터 간선의 정보가 주어진다. 

각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. (1 ≤ a, b ≤ N)


출력

주어진 그래프가 이분 그래프이면 Yes, 아니면 No를 출력한다.

*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> Graph[1010];
int color[1010];
queue<int> Queue;

void BFS(int x)
{
  int tmp;
  int next;
  
  color[x] = 1;
  Queue.push(x);
  
  while(1)
  {
    if(Queue.empty() == 1)
      break;
    
    tmp = Queue.front();
    Queue.pop();
    
    for(int i=0;i<Graph[tmp].size(); i++)
    {
      next= Graph[tmp][i];
      
      if(color[next] == 0 && color[tmp] ==1)
      {
        color[next] = 2;
        Queue.push(next);
      }
      else if(color[next] == 0 && color[tmp] == 2)
      {
        color[next] = 1;
        Queue.push(next);
      }
      
    }
  }
  
}

int main() {

  int N,M;
  int v,e;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<M;i++)
  {
    scanf("%d %d", &v, &e);
    
    Graph[v].push_back(e);
    Graph[e].push_back(v);
  }
  
  BFS(v);
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<Graph[i].size();j++)
    {
      if(color[i] == color[Graph[i][j]])
      {
        printf("No");
        return 0;
      }
    }
  }
  
  printf("Yes");

  return 0;
}
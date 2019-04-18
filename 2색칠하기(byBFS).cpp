/*

2색칠하기(by BFS)

2색 칠하기란, 다음 두 조건을 만족하면서 그래프의 정점을 모두 색칠할 수 있는지 묻는 문제이다. 

2개의 색이 존재한다. 인접한 두 정점은 색깔이 다르다. 

그래프가 주어질 때, 2색 칠하기가 가능한지 출력하는 프로그램을 작성하시오. 


입력

첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 10,000, 1 ≤ M ≤ 100,000 ) 

둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다.(0 ≤ a, b ≤ N-1)


출력

주어진 그래프에 대하여 2색 칠하기를 할 수 있으면 YES, 할 수 없으면 NO를 출력한다.

*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> Graph[10010];
int color[10010] = {0,};

void BFS(int x)
{ //1이 빨강, 2가 파랑, 인접한애 색칠같이되어있으면 안됨

  int tmp;
  int next;
  queue<int> Queue;
  
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
      next = Graph[tmp][i];
      
      if(color[tmp] == 1 && color[next] == 0)
      {
        color[next] = 2;
        Queue.push(next);
      }
      else if(color[tmp] == 2 && color[next] == 0)
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
        printf("NO");
        return 0;
      }
    }
  }
  
  printf("YES");
  
  return 0;
}
/*

웜바이러스(by BFS)

신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 

한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다. 

어느날 1번 컴퓨터가 웜 바이러스에 걸렸다. 

컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.


입력

첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번부터 차례대로 번호가 매겨진다. 

둘째 줄에는 네트워크상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 

이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.


출력

1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> Graph[101];
int visited[101];
queue<int> Queue;

void BFS(int x,int *cnt)
{
  int tmp;
  int next;

  visited[x] = 1;
  Queue.push(x);
  
  while(1)
  {
    if(Queue.empty() == 1)
      break;
   
    tmp = Queue.front();
    Queue.pop();
    *cnt = *cnt + 1;  
    for(int i=0;i<Graph[tmp].size();i++)
    {
      next = Graph[tmp][i];
      if(visited[next] == 0)
      {
        visited[next] = 1;
        Queue.push(next);
      }
    }
  }
}

int main() {

  int N,M;
  int v,e;
  int cnt=-1;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<M;i++)
  {
    scanf("%d %d", &v, &e);
    
    Graph[v].push_back(e);
    Graph[e].push_back(v);
  }
  
  BFS(1,&cnt);
  
  printf("%d", cnt);
  

  return 0;
}
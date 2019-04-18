/*

최단거리(by 다익스트라)

그래프와 출발점, 도착점이 주어질 때 출발점에서 도착점까지 이동하기 위한 최단거리를 출력하는 프로그램을 작성하시오. 


입력

첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 10,000, 1 ≤ M ≤ 1,000,000 ) 

둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. 

M+1 번째 줄에 대하여 출발점과 도착점의 정점 번호가 주어진다.

 
출력

출발점에서 도착점까지 이동하기 위한 최단거리를 출력한다.

*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> Graph[10010];
queue<int> Queue;
int Table[10010];
int visited[10010];

int main() {

  int N,M;
  int a,b;
  int start,end;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<M;i++)
  {
    scanf("%d %d", &a, &b);
    
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }
  
  scanf("%d %d", &start, &end);
  
  for(int i=0;i<N;i++)
  {
    Table[i] = 987987987;
  }
  
  Table[start]=0; // start부터의 거리를 집어넣어버리짓
  
  Queue.push(start); // 인덱스를 집어넣어버리짓
  
  while(1)
  {
    if(Queue.empty() == 1)
      break;
      
    int tmp = Queue.front();
    Queue.pop();
    
    for(int i=0;i<Graph[tmp].size();i++)
    {
      int next = Graph[tmp][i];
      
      if(visited[next] == 0 && Table[next] > Table[tmp] + 1)
      {  
        visited[next] = 1;
        Table[next] = Table[tmp] +1;
         Queue.push(next);
      }
        
    }
  }
  
  printf("%d", Table[end]); 
   
  return 0;
}
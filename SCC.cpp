/*

SCC

SCC (Strongly Connected Component)란, 방향성 그래프가 주어질 때 정점을 여러 집합으로 나누는 기법으로써, 같은 집합에 속해있는 정점끼리는 서로 왔다갔다 할 수 있어야 한다. 

그래프가 주어질 때, SCC를 구하였을 때 얻을 수 있는 정점의 집합의 개수를 구하는 프로그램을 작성하시오.


입력

첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 

각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a에서 정점 b로 향하는 간선이 존재한다는 의미이다.


출력

주어진 그래프에서 SCC를 구하였을 때, 얻을 수 있는 정점의 집합의 개수를 출력한다.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[1010];
vector<int> reverseGraph[1010];

int order[1010] = {0,}; //노드 빠져나온 순서 마지막이 제일 느림
int group[1010] = {0,};
int visited[1010] = {0,};
int visited2[1010] = {0,};
int order_len = 0, group_cnt=1;

void make_order(int node)
{
  visited[node] = 1;
  
  for(int i=0;i<Graph[node].size();i++)
  {
    int next = Graph[node][i];
    
    if(visited[next] == 0)
    {
      make_order(next);
    }
  }
  
  
  order[order_len++] = node;
}

void make_group(int node)
{
  visited2[node] = 1;
  group[node] = group_cnt;
  
  for(int i=0;i<reverseGraph[node].size();i++)
  {
    int next = reverseGraph[node][i];
    
    if(visited2[next] == 0)
    {
      make_group(next);
    }
  }
  
}

int main() {

  int N,M;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<M;i++)
  {
    int a,b;
    
    scanf("%d %d", &a, &b);
    
    Graph[a].push_back(b);
    reverseGraph[b].push_back(a);
  }
  
  for(int i=1;i<=N;i++)
  {
    if(!visited[i])
    {
      make_order(i);
    }
  }
  
  for(int i=order_len-1;i>=0;i--)
  {
    int tmp = order[i];
    
    if(!visited2[tmp])
    {
      make_group(tmp);
      group_cnt++;
    }
  }
  
  /*for(int i=1;i<=N;i++)
  {
    printf("%d : %d \n", order[i],group[order[i]]);
  }*/
  
  printf("%d", group_cnt-1);
  
  

  return 0;
}
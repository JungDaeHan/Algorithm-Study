/*

2��ĥ�ϱ�(by BFS)

2�� ĥ�ϱ��, ���� �� ������ �����ϸ鼭 �׷����� ������ ��� ��ĥ�� �� �ִ��� ���� �����̴�. 

2���� ���� �����Ѵ�. ������ �� ������ ������ �ٸ���. 

�׷����� �־��� ��, 2�� ĥ�ϱⰡ �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 


�Է�

ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. ( 1 �� N �� 10,000, 1 �� M �� 100,000 ) 

��° �ٺ��� ������ ������ �־�����. �� ���� �� ���� ���� a, b�� �̷���� ������, �̴� ���� a�� ���� b�� ����Ǿ� �ִٴ� �ǹ��̴�.(0 �� a, b �� N-1)


���

�־��� �׷����� ���Ͽ� 2�� ĥ�ϱ⸦ �� �� ������ YES, �� �� ������ NO�� ����Ѵ�.

*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> Graph[10010];
int color[10010] = {0,};

void BFS(int x)
{ //1�� ����, 2�� �Ķ�, �����Ѿ� ��ĥ���̵Ǿ������� �ȵ�

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
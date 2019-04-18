/*

�̺б׷��� �Ǻ�(by BFS)

�̺� �׷�����, �Ʒ� �׸��� ���� ������ ũ�� �� �������� ���� �� �ִ� �׷����� ���Ѵ�. 

���⼭ ���� ���տ� ���� ���������� ������ �����ؼ��� �ȵȴ�. 

�׷����� �Է����� �־��� ��, �� �׷����� �̺б׷��������� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. ( 1 �� N �� 1,000, 1 �� M �� 100,000 ) 

��° �ٺ��� ������ ������ �־�����. 

�� ���� �� ���� ���� a, b�� �̷���� ������, �̴� ���� a�� ���� b�� ����Ǿ� �ִٴ� �ǹ��̴�. (1 �� a, b �� N)


���

�־��� �׷����� �̺� �׷����̸� Yes, �ƴϸ� No�� ����Ѵ�.

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
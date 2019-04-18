/*

�����̷���(by BFS)

���� ���̷����� �� ���̷����� ��Ʈ��ũ�� ���� ���ĵȴ�. 

�� ��ǻ�Ͱ� �� ���̷����� �ɸ��� �� ��ǻ�Ϳ� ��Ʈ��ũ �󿡼� ����Ǿ� �ִ� ��� ��ǻ�ʹ� �� ���̷����� �ɸ��� �ȴ�. 

����� 1�� ��ǻ�Ͱ� �� ���̷����� �ɷȴ�. 

��ǻ���� ���� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ������ �־��� ��, 1�� ��ǻ�͸� ���� �� ���̷����� �ɸ��� �Ǵ� ��ǻ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ��� ��ǻ���� ���� �־�����. ��ǻ���� ���� 100 �����̰� �� ��ǻ�Ϳ��� 1������ ���ʴ�� ��ȣ�� �Ű�����. 

��° �ٿ��� ��Ʈ��ũ�󿡼� ���� ����Ǿ� �ִ� ��ǻ�� ���� ���� �־�����. 

�̾ �� ����ŭ �� �ٿ� �� �־� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ���� ��ȣ ���� �־�����.


���

1�� ��ǻ�Ͱ� �� ���̷����� �ɷ��� ��, 1�� ��ǻ�͸� ���� �� ���̷����� �ɸ��� �Ǵ� ��ǻ���� ���� ù° �ٿ� ����Ѵ�.

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
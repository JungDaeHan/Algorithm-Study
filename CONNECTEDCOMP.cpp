/*

CONNECTEDCOMP

������ ��ȣ�� 1���� N���� �����ϴ� �׷��� G�� �����ϰ�, ��� ���� ���� S={i, j, k,..} ������ ���� �������� ����Ǿ�������, 

�� �̿��� ���� ����(S`)���� ����Ǿ����� ������, ���� S�� �׷����� �׷����� �׷��� G�� ������(Connected Component)��� �մϴ�. 

���� ���� ���� S�� S`�� �������� G�� ������ ��ü�� ���, �׷��� G�� �������� ������ 2���Դϴ�. 

���� ���� �׷����� �־����� ��, ���� ��� (Connected Component)�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�
ù° �ٿ� ������ ���� V�� ������ ���� E�� �־�����. (1 �� V �� 1,000, 0 �� E �� V��(N-1)/2) 

��° �ٺ��� E���� �ٿ� ������ �� ���� v1�� v2�� �־�����. (1 �� v1, v2 �� N, v1 �� v2) ���� ������ �� ���� �־�����.


���

ù° �ٿ� ���� ����� ������ ����Ѵ�.

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
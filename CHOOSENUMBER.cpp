/*

CHOOSE NUMBER

���� �� ��, ���η� N���� ĭ���� �̷���� ǥ�� �ִ�. 

ù° ���� �� ĭ���� ���� 1, 2, ��, N�� ���ʴ�� ��� �ְ� ��° ���� �� ĭ���� 1�̻� N������ ������ ��� �ִ�. 

ù° �ٿ��� ���ڸ� ������ ������, �� ���� �������� �̷�� ���հ�, ���� �������� �ٷ� ���� ��° �ٿ� ����ִ� �������� �̷�� ������ ��ġ�Ѵ�. 

�̷��� ������ ������Ű���� �������� �̵�, �ִ�� ���� �̴� ����� ã�� ���α׷��� �ۼ��Ͻÿ�. 

���� ���, N=7�� ��� �Ʒ��� ���� ǥ�� �־����ٰ� ����.

1	2	3	4	5	6	7
3	1	1	5	5	4	6

�� ��쿡�� ù° �ٿ��� 1, 3, 5�� �̴� ���� ���̴�. ù° ���� 1, 3, 5�ؿ��� ���� 3, 1, 5�� ������ �� ������ ��ġ�Ѵ�. 

�̶� ������ ũ��� 3�̴�. ���� ù° �ٿ��� 1�� 3�� ������, �̵� �ٷ� �ؿ��� ���� 3�� 1�� �����Ƿ� �� ������ ��ġ�Ѵ�. 

�׷���, �� ��쿡 ���� ������ ������ �ִ밡 �ƴϹǷ� ���� �ɼ� ����.


�Է�

ù° �ٿ��� N(1��N��100)�� ��Ÿ���� ���� �ϳ��� �־�����. �� ���� �ٺ��ʹ� ǥ�� ��° �ٿ� ���� �������� ������� �� �ٿ� �ϳ��� �Էµȴ�.


���

ù° �ٿ� ���� �������� ������ ����ϰ�, ��° �ٿ� ���� �������� ���� ������ ū ���� ������ ������ ���� �����Ͽ� �ϳ��� ����Ѵ�.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[110];
//vector<int> reGraph[110];
int visited[110];
//int visited2[110];
int cycle[110];

int tmpCnt;

void DFS(int x,int fix)
{
  if(x == fix )
  {
    cycle[x] = 1;
  
    int tmp = Graph[x][0];
    
    while(visited[tmp] != 0)
    {
      visited[tmp] = 0;
      cycle[tmp] = 1;
      tmp = Graph[tmp][0];
    }
    return;
  }
  
  visited[x] = 1;
  
  int tmp = Graph[x][0];
  
  if(visited[tmp] == 0)
  {
    DFS(tmp,fix);
  }
  
  visited[tmp] = 0 ;
  
  return;
}

/*int rDFS(int x)
{
  if(visited2[x] == 1)
  {
    return tmpCnt;
  }
  
  visited2[x] = 1;
  
  if(reGraph[x].size() > 0)
    if(reGraph[x][0] == x)
    {
      return 1;
    }
  
  for(int i=0;i<reGraph[x].size();i++)
  {
    int next = reGraph[x][i];
    tmpCnt++;
    rDFS(next);
  }
  
}*/


int main() {

  int N;
  int num;
  int tmp[110];
  
  scanf("%d", &N);
  
  for(int i=1;i<=N;i++)
  {
    scanf("%d", &num);
    
    Graph[i].push_back(num);
    //reGraph[num].push_back(i);
  }
  
  int max = 0;
  
  
  for(int i=1;i<=N;i++)
  {
    DFS(Graph[i][0],i);
  }
    
  int sum=0;
  
  for(int i=1;i<=N;i++)
  {
    if(cycle[i] == 1)
      sum+=1;
  }
  
  printf("%d\n", sum);
  
  for(int i=1;i<=N;i++)
  {
    if(cycle[i] == 1)
      printf("%d ", i);
  }
  
  return 0;
}
/*

FINDBEAD

����� ������, ���԰� ��� �ٸ� N���� ������ �ִ�. N�� Ȧ���̸�, �������� ��ȣ�� 1,2,...,N���� �پ� �ִ�. 

�� ���� �߿��� ���԰� ��ü�� �߰��� (���� ������ (N+1)/2��°) ������ ã�� ���ؼ� �� ���� ���� ���� �Ϸ� �Ѵ�.

�츮���� �־��� ���� ���� �����̴�. 

�� ���� ������ ��� ���� ������ ���ʿ� �ϳ��� �÷� ���� ��� ���� ���ſ� ���� �� �� �ִ�. 

�̷��� M���� ���� ��� ���� ���� ���￡ �÷��� ��� ���� �� �ſ� ���� ��� �˾Ƴ´�. 

�� ����� �̿��Ͽ� ���԰� �߰��� �� ���ɼ��� ���� ���� �������� ���� �����Ѵ�.

���� ���, N=5�̰�, M=4 ���� ������ ���ؼ� ��� ���� ���ſ�� �˾Ƴ� ����� �Ʒ��� �ִ�.

���� 2���� ���� 1������ ���̴�.
���� 4���� ���� 3������ ���̴�.
���� 5���� ���� 1������ ���̴�.
���� 4���� ���� 2������ ���̴�.

���� ���� �� ���� ������� �˰� ������, ���԰� �߰��� ������ ��Ȯ�ϰ� ã�� ���� ������, 

1�� ������ 4�� ������ ���԰� �߰��� ������ ���� �� �� ���ٴ� ���� Ȯ���� �� �� �ִ�. 

1�� �������� ���ſ� ���� 2, 4, 5�� �����̰�, 4�� ���� ������ ���� 1, 2, 3���̴�. ���� ���� 2���̴�.

M ���� �ֿ� ���� ����� ���� ���԰� �߰��� ������ �� �� ���� ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

 
�Է�

ù ���� ������ ������ ��Ÿ���� ���� N(1 �� N �� 99)�� ���￡ �÷� �� ���� ���� M(0 �� N < N) �� �־�����. 

�� ���� M ���� ���� �� �ٸ��� �� ���� ���� ��ȣ�� �־����µ�, �� ��ȣ�� ������ �� ��ȣ�� �������� ���̴ٴ� ���� ���Ѵ�.


���

ù �ٿ� ���԰� �߰��� ����� �� �� ���� ������ ���� ��� �Ѵ�.

*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> Graph[100];
vector<int> reGraph[100];
queue<int> Queue;

int visited[100];
int edgeCnt;
int pick[100];

void BFS(int x, int avr,int cnt)
{
  visited[x] = 1;
  
  Queue.push(x);
 
  while(Queue.empty() != 1)
  {
    int tmp = Queue.front();
    Queue.pop();
  
    for(int i=0;i<Graph[tmp].size();i++)
    {
      int next = Graph[tmp][i];
      
      if(visited[next] == 0 )
      {
        visited[next] = 1;
        edgeCnt++;
        Queue.push(next);
      }
    }
  }
  
  
}

void rBFS(int x, int avr,int cnt)
{
  
  visited[x] = 1;
  
  Queue.push(x);
 
  while(Queue.empty() != 1)
  {
    int tmp = Queue.front();
    Queue.pop();
  
    for(int i=0;i<reGraph[tmp].size();i++)
    {
      int next = reGraph[tmp][i];
      
      if(visited[next] == 0 )
      {
        visited[next] = 1;
        edgeCnt++;
        Queue.push(next);
      }
    }
  }
  
}

int main() {

  int N,M;
  int x,y;
  int cnt=0;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<M;i++)
  {
    scanf("%d %d", &x,&y);
    
    Graph[x].push_back(y);
    reGraph[y].push_back(x);
  }
  
  int tmp;
  
  for(int i=1;i<=N;i++)
  {
    edgeCnt = 0;
    
    BFS(i,(N+2)/2,0);

    //printf("%d : %d \n", i , edgeCnt);
    
    if(edgeCnt >= (N+1)/2)
    {
      pick[i] = 1;
      cnt++;
    }
    
      
    for(int i=1;i<=N;i++)
      visited[i] = 0;
  }

  //printf("\n");
  
  for(int i=1;i<=N;i++)
  {
    edgeCnt = 0;
    
    rBFS(i,(N+2)/2,0);
    //printf("%d : %d -- \n", i,edgeCnt);
    
    if(edgeCnt >= (N+1)/2 && pick[i] == 0)
    {
      pick[i] = 1;
      cnt++;
    }
      
    for(int i=1;i<=N;i++)
      visited[i] = 0;
  }
  

  
  printf("%d", cnt);
  
  return 0;
}
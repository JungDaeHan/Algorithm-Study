/*

�ִܰŸ�(by ���ͽ�Ʈ��)

�׷����� �����, �������� �־��� �� ��������� ���������� �̵��ϱ� ���� �ִܰŸ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 


�Է�

ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. ( 1 �� N �� 10,000, 1 �� M �� 1,000,000 ) 

��° �ٺ��� ������ ������ �־�����. �� ���� �� ���� ���� a, b�� �̷���� ������, �̴� ���� a�� ���� b�� ����Ǿ� �ִٴ� �ǹ��̴�. 

M+1 ��° �ٿ� ���Ͽ� ������� �������� ���� ��ȣ�� �־�����.

 
���

��������� ���������� �̵��ϱ� ���� �ִܰŸ��� ����Ѵ�.

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
  
  Table[start]=0; // start������ �Ÿ��� ����־������
  
  Queue.push(start); // �ε����� ����־������
  
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
/*

�̺б׷��� �Ǻ�

�̺� �׷�����, �Ʒ� �׸��� ���� ������ ũ�� �� �������� ���� �� �ִ� �׷����� ���Ѵ�. 

���⼭ ���� ���տ� ���� ���������� ������ �����ؼ��� �ȵȴ�. 


�Է�

ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. 

( 1 �� N �� 1,000, 1 �� M �� 100,000 ) ��° �ٺ��� ������ ������ �־�����.

�� ���� �� ���� ���� a, b�� �̷���� ������, �̴� ���� a�� ���� b�� ����Ǿ� �ִٴ� �ǹ��̴�. (1 �� a, b �� N)


���

�־��� �׷����� �̺� �׷����̸� Yes, �ƴϸ� No�� ����Ѵ�.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[1010];
int color[1010]={0,}; 

int DFS(int x,int prior)
{
  int tmp;
  
  if(prior == -1)
    color[x] = 1;
  else if(color[prior] == 2)
    color[x] = 1;
  else if(color[prior] == 1)
    color[x] = 2;
    
  
  for(int i=0;i<Graph[x].size();i++)
  {
    tmp = Graph[x][i];
    
    if(color[tmp] == 0)
    {
      DFS(tmp,x);
    }
  }
  
  
  
}

int main() {

  int N,M;
  int v,e;
  int cnt=0;
  int check;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<M;i++)
  {
    scanf("%d %d", &v, &e);
    
    Graph[v].push_back(e);
    Graph[e].push_back(v);
  }
  
  DFS(v,-1);
    
  for(int i=1 ; i<= N; i++)
  {
    for(check=0; check<Graph[i].size() ; check++)
    {
      if(color[Graph[i][check]] == color[i])
        break;
    }
    
    if(check < Graph[i].size())
    {
      printf("No");
      return 0;
    }
    
  }

  
  printf("Yes");
  
  return 0;
}
/*

SCC

SCC (Strongly Connected Component)��, ���⼺ �׷����� �־��� �� ������ ���� �������� ������ ������ν�, ���� ���տ� �����ִ� ���������� ���� �Դٰ��� �� �� �־�� �Ѵ�. 

�׷����� �־��� ��, SCC�� ���Ͽ��� �� ���� �� �ִ� ������ ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. ( 1 �� N �� 1,000, 1 �� M �� 100,000 ) ��° �ٺ��� ������ ������ �־�����. 

�� ���� �� ���� ���� a, b�� �̷���� ������, �̴� ���� a���� ���� b�� ���ϴ� ������ �����Ѵٴ� �ǹ��̴�.


���

�־��� �׷������� SCC�� ���Ͽ��� ��, ���� �� �ִ� ������ ������ ������ ����Ѵ�.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[1010];
vector<int> reverseGraph[1010];

int order[1010] = {0,}; //��� �������� ���� �������� ���� ����
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
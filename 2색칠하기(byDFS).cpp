/*

2�� ĥ�ϱ��, ���� �� ������ �����ϸ鼭 �׷����� ������ ��� ��ĥ�� �� �ִ��� ���� �����̴�. 

2���� ���� �����Ѵ�. ������ �� ������ ������ �ٸ���. 

�׷����� �־��� ��, 2�� ĥ�ϱⰡ �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 


�Է�

ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. 

( 1 �� N �� 10,000, 1 �� M �� 100,000 ) ��° �ٺ��� ������ ������ �־�����. 

�� ���� �� ���� ���� a, b�� �̷���� ������, �̴� ���� a�� ���� b�� ����Ǿ� �ִٴ� �ǹ��̴�.(0 �� a, b �� N-1)


���

�־��� �׷����� ���Ͽ� 2�� ĥ�ϱ⸦ �� �� ������ YES, �� �� ������ NO�� ����Ѵ�.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[10010];
int color[10010]={0,}; // 1 -> ���, 2 -> �Ķ�

void DFS(int x,int prior)
{
  int tmp;
  
  if(prior == -1)
    color[x] = 1;
  else if(color[prior] == 1)
    color[x] = 2;
  else if(color[prior] == 2)
    color[x] = 1;

  for(int i=0;i<Graph[x].size(); i++)
  {
    tmp = Graph[x][i];
    
    if(color[tmp] == 0)
    {
      DFS(tmp,x);
    }
    
    //DFS(tmp,pick
  }
  
}

/*typedef struct
{
  int data[10010];
  int len=0;
  int capacity;
  int f,r;
  
  void Create(int x)
  {
    capacity = x;
    f = 0;
    r = 0;
  }
  
  void Push(int x)
  {
    data[r] = x;
    r = (r+1) % capacity;
    len++;
  }
  
  void Pop()
  {
    data[f] = 0;
    f = (f+1) % capacity;
    len--;
  }
  
  int Top()
  {
    if(len <= 0)
      return -1;
    
    return data[len-1];
  }
  
} Queue;*/

int main() {
  
  int N,M;
  int v,e,tmp;
  //Queue Q;
  
  scanf("%d %d", &N, &M);

  //Q.Create(N);
  
  for(int i=0;i<M;i++)
  {
    scanf("%d %d", &v, &e);
    
    Graph[v].push_back(e);
    Graph[e].push_back(v);
  } 
  
  DFS(0,-1);
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<Graph[i].size();j++)
    {
      tmp = Graph[i][j];
      if(color[i] == color[tmp])
      {
        printf("NO");
        return 0;
      }
    }
  }
  
  printf("YES");
  
  
  
  
  
  
  
  
  
  /*
  Q.Push(0);
  color[0] = 1;
  
  while(Q.Top() != -1)
  {
    tmp = Q.Top();
    Q.Pop();
    
    for(int i=0;i<Graph[tmp].size(); i++)
    {
      int tmp2 = Graph[tmp][i];
      
      if(color[tmp] == color[tmp2])
      {
        printf("NO");
        return 0;
      }
      
      if(color[tmp] == 1)
      {
        color[tmp2] = 2;
      }
      else if(color[tmp] == 2)
      {
        color[tmp2] = 1;
      }
      
      
    }
  }*/ // bfsbfs 
  


  

  return 0;
}
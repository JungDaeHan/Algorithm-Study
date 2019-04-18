/*

2색 칠하기란, 다음 두 조건을 만족하면서 그래프의 정점을 모두 색칠할 수 있는지 묻는 문제이다. 

2개의 색이 존재한다. 인접한 두 정점은 색깔이 다르다. 

그래프가 주어질 때, 2색 칠하기가 가능한지 출력하는 프로그램을 작성하시오. 


입력

첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. 

( 1 ≤ N ≤ 10,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 

각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다.(0 ≤ a, b ≤ N-1)


출력

주어진 그래프에 대하여 2색 칠하기를 할 수 있으면 YES, 할 수 없으면 NO를 출력한다.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[10010];
int color[10010]={0,}; // 1 -> 노랑, 2 -> 파랑

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
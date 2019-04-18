/*

특정 최단거리(by 다익스트라)

무방향 그래프가 주어질 때, 정점 1번에서 정점 N번으로 가는 최단거리를 구하려 하는데, 그 과정에서 두 개의 정점을 반드시 거쳐야 한다. 

한 번 방문했던 정점을 또 다시 방문하는 것도 허용하고, 간선도 마찬가지로 여러번 방문하는 것을 허용한다고 할 때, 

1번에서 N번으로 가는 “특정한" 최단거리를 출력하는 프로그램을 작성하시오.


입력

첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 

둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b, c로 이루어져 있으며, 이는 정점 a와 정점 b가 가중치 c인 간선으로 연결되어 있다는 의미이다. 

마지막 줄에는 반드시 거쳐야 하는 두 정점 A, B가 주어진다. ( 1 ≤ a, b, A, B ≤ 1,000, 1 ≤ c ≤ 50,000 )
 

출력

1번 정점에서 N번 정점으로 가는 “특정한" 최단거리를 출력한다. 

단, “특정한" 최단거리란, 주어진 정점 A와 B를 반드시 방문할 때의 최단거리를 의미한다.

*/

#include<cstdio>
#include<vector>

using namespace std;

vector<int> Graph[1010];
vector<int> Cost[1010];

int main() {

  int N,M;
  
  scanf("%d %d", &N,&M);
  
  for(int i=0; i<M; i++)
  {
    int a,b,c;
    
    scanf("%d %d %d", &a,&b,&c);
    
    Graph[a].push_back(b);
    Graph[b].push_back(a);
    
    Cost[a].push_back(c);
    Cost[b].push_back(c);
  }
  
  int A,B; // 이 두점을 반드시 지나면서 1~N의 최단거리
  
  scanf("%d %d", &A, &B);
  
  int Table[1010]; // 1에서 A로
  int Table2[1010]; // A에서 B로
  int Table3[1010]; // B에서 N으로
  
  int Check[1010] = {0,}; // 1이면 완전한 최단거리
  int Check2[1010] = {0,};
  int Check3[1010] = {0,};
  
  for(int i=0;i<=N;i++)
  {
    Table[i] = 987987987;
    Table2[i] = 987987987;
    Table3[i] = 987987987;
  }
    
  Table[1] = 0;
  Table2[A] = 0;
  Table3[B] = 0;
  
  for(int i=0;i<=N;i++)
  {
    int minValue= 987987987;
    int minIndex = -1;
    
    for(int i=0;i<=N;i++)
    {
      if(!Check[i] && minValue > Table[i])
      {
        minValue = Table[i];
        minIndex = i;
      }
    }
    
    Check[minIndex] = 1;
    
    for(int i=0;i<Graph[minIndex].size() ; i++)
    {
      int Node = Graph[minIndex][i];
      int cost = Cost[minIndex][i];
      
      if(Table[Node] > Table[minIndex] + cost)
        Table[Node] = Table[minIndex] + cost;
    }
  }
  
  for(int i=0;i<=N;i++)
  {
    int minValue= 987987987;
    int minIndex = -1;
    
    for(int i=0;i<=N;i++)
    {
      if(!Check2[i] && minValue > Table2[i])
      {
        minValue = Table2[i];
        minIndex = i;
      }
    }
    
    Check2[minIndex] = 1;
    
    for(int i=0;i<Graph[minIndex].size() ; i++)
    {
      int Node = Graph[minIndex][i];
      int cost = Cost[minIndex][i];
      
      if(Table2[Node] > Table2[minIndex] + cost)
        Table2[Node] = Table2[minIndex] + cost;
    }
  }
  
  for(int i=0;i<=N;i++)
  {
    int minValue= 987987987;
    int minIndex = -1;
    
    for(int i=0;i<=N;i++)
    {
      if(!Check3[i] && minValue > Table3[i])
      {
        minValue = Table3[i];
        minIndex = i;
      }
    }
    
    Check3[minIndex] = 1;
    
    for(int i=0;i<Graph[minIndex].size() ; i++)
    {
      int Node = Graph[minIndex][i];
      int cost = Cost[minIndex][i];
      
      if(Table3[Node] > Table3[minIndex] + cost)
        Table3[Node] = Table3[minIndex] + cost;
    }
  }
  
  /*for(int i=1;i<=N;i++)
    printf("%d ", Table[i]);
  printf("\n");
  for(int i=1;i<=N;i++)
    printf("%d ", Table2[i]);
  printf("\n");
  for(int i=1;i<=N;i++)
    printf("%d ", Table3[i]);*/
  
  //Table : 1 에서 모든 정점까지의 최단거리 
  //Table2 : A 에서 모든 정점까지의 최단거리 
  //Table3 : B 에서 모든 정점까지의 최단거리 
  
  //1에서 A , A 에서 B, B 에서 N 
  //1에서 B, B 에서 A, A 에서 N 
  
  int min = 987987987;
  
  if(min > Table[B] + Table3[A] + Table2[N])
    min = Table[B] + Table3[A] + Table2[N];
    
  if(min > Table[A] + Table2[B] + Table3[N])
    min = Table[A] + Table2[B] + Table3[N];
    
  printf("%d",min);
  
  return 0;
}
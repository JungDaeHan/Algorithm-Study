/*

파티

철수네 마을에는 N개의 집이 있으며, 각 집은 고유한 번호를 부여받는다. 

각 번호는 1보다 크거나 같고, N보다 작거나 같다. 철수는 마을 K에 살고 있다. 

집과 집 사이에는 단방향 도로가 존재하기 때문에, 이 도로를 통하여 서로 이동할 수 있다. 

즉, N개의 마을은 그래프 구조를 이룬다. 편의상 각 집에는 한 사람만이 살고 있다고 가정하자. 

크리스마스인 오늘, 철수는 본인의 집에서 파티를 열려고 한다. 

따라서 다른 모든 사람들이 철수의 집에 모여 파티를 즐기고, 파티가 끝난 후에는 다시 본인의 집으로 돌아가려 한다. 

사람들은 본인의 집에서 철수네 집까지 이동하기 위하여 항상 최단거리로 이동하기를 원하고, 

마찬가지로 철수네 집에서 본인의 집에 갈 때도 최단거리로 이동하기를 원한다. 

집의 개수와 두 집을 잇는 단방향 도로의 정보, 그리고 철수의 집 번호가 주어질 때, 

마을 사람들이 파티를 즐기기 위해서 이동해야 하는 총 거리의 합을 출력하는 프로그램을 작성하시오.


입력

첫째 줄에 정점의 개수 N과 간선의 개수 M, 그리고 철수의 집 번호 K가 주어진다. ( 1 ≤ N, K ≤ 1,000, 1 ≤ M ≤ 100,000 ) 

둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b, c로 이루어져 있으며, 이는 정점 a에서 정점 b로 이동하는 데 시간이 c만큼 걸린다는 의미이다. 

양방향 도로가 아님에 주의하자.


출력

마을 사람들이 파티를 즐기기 위해서 이동해야 하는 총 거리의 합을 출력한다.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[1010];
vector<int> Cost[1010];

int mat[1010][1010] =  {0,};

int main() {

  //1부터 N 까지 집 번호
  //철수는 K 집
  // 엣지는 단방향
  
  int N,M,K;
  
  scanf("%d %d %d", &N, &M, &K);
  
  for(int i=0;i<M;i++)
  {
    int a,b,c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    mat[a][b] = c;
    
    //Graph[a].push_back(b);
    
    //Cost[a].push_back(c);
  }
  
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
    {
      if(i==j)
        continue;
        
      if(mat[i][j] == 0)
        mat[i][j] = 987987987;
    }
  
  for(int m=1;m<=N;m++)
    for(int s=1;s<=N;s++)
      for(int e=1;e<=N;e++)
      {
        if(mat[s][e] > mat[s][m] + mat[m][e])
          mat[s][e] = mat[s][m] + mat[m][e];
      }
  
  
  
  
  /*int Table[1010][1010];
  int Check[1010][1010] = {0,};
  
  for(int i=0;i<=N;i++)
  {
    for(int j=0;j<=N;j++)
      Table[i][j] = 987987987;
  }
  
  for(int i=1;i<=N;i++)
    Table[i][i] = 0;
  
  //1부터 N 까지 집 번호
  //철수는 K 집
  // 엣지는 단방향
  // 모든 정점에서 모든 정점까지의 최단거리 -> 플로이드? 그러나 다익스트라로 해보자
  
  for(int i=1;i<=N;i++)
  { //i는 한 정점을 가리킬 것
    for(int j=1;j<=N;j++)
    {
      //j는 다른 정점들을 가리킬 것
      
      int minValue = 987987987;
      int minIndex = -1;
      
      for(int j=1;j<=N;j++)
      {
        if(!Check[i][j] && minValue > Table[i][j])
        {
          minValue = Table[i][j];
          minIndex = j;
        }
      }
      
      Check[i][minIndex] = 1;
      
      for(int j=0;j<=Graph[minIndex].size();j++)
      {
        int Node = Graph[minIndex][j];
        int cost = Cost[minIndex][j];
        
        if(Table[i][Node] > Table[i][minIndex] + cost)
          Table[i][Node] = Table[i][minIndex] + cost;
      }
    }
  }
  
  int sum = 0;
  
  for(int i=1;i<=N;i++)
    sum+= Table[K][i];
    
  for(int i=1;i<=N;i++)
  {
    sum+= Table[i][K];
  }*/
  
  int sum=0;
  
  for(int i=1;i<=N;i++)
  {
    sum+= mat[K][i];
    sum+= mat[i][K];
  }
  
  
  printf("%d", sum);
  
  return 0;
}
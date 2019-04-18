/*

목수의 미로탈출(by BFS)

이동할 수 있는 길, 그리고 이동할 수 없는 벽으로 이루어진 크기 N x M 의 지도가 주어진다. 

이 때, (N-1, 0) 에서 출발하여 (0, M-1) 까지 도착하는 최단거리를 찾으려 한다. 

그런데 목수는 도끼 하나를 갖고 있으며, 이 도끼를 이용하여 벽을 깨부술 수 있다. 

하지만 이 도끼는 내구성이 그렇게 좋지 않기 때문에, 벽을 최대 1개밖에 깰 수 없다. 

목수가 출발점에서 도착점까지 이동하기 위한 최단거리를 출력하는 프로그램을 작성하시오. 

물론, 벽은 최대 1개까지 깰 수 있다. 
 

입력

첫째 줄에 지도의 세로 길이 N과 지도의 가로 길이 M이 주어진다. ( 1 ≤ N, M ≤ 1,000 ) 둘째 줄부터 지도의 정보가 주어진다. 

0은 이동할 수 있는 부분, 1은 이동할 수 없는 부분을 나타낸다. 


출력

목수가 (N-1, 0) 에서 출발하여 (0, M-1) 까지 이동하는 데 필요한 최단거리를 출력한다. 목수는 미로를 항상 탈출할 수 있다고 가정한다.

*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
queue<int> Queue[2];

void BFS(int mat[][1010], int N,int M,int x,int y)
{
  //0,M-1 까지임
  int distance = 0;
  
  Queue[0].push(x);
  Queue[1].push(y);
  
  mat[x][y] = distance;
  
  while(1)
  {
    if(Queue[0].empty() == 1)
    {
      return;
    }
    
    x = Queue[0].front();
    y = Queue[1].front();
    
    distance = mat[x][y]+1;
    
    Queue[0].pop();
    Queue[1].pop();
    
    if(x+1 < N && mat[x+1][y] == 0)
    {
      mat[x+1][y] = distance;
      Queue[0].push(x+1);
      Queue[1].push(y);
    }
    if(x-1 >= 0 && mat[x-1][y] == 0)
    {
      mat[x-1][y] = distance;
      Queue[0].push(x-1);
      Queue[1].push(y);
    }
    if(y+1 < M && mat[x][y+1] == 0)
    {
      mat[x][y+1] = distance;
      Queue[0].push(x);
      Queue[1].push(y+1);
    }
    if(y-1 >= 0 && mat[x][y-1] == 0)
    {
      mat[x][y-1] = distance;
      Queue[0].push(x);
      Queue[1].push(y-1);
    }
  }
}

int getMin4(int a,int b,int c,int d)
{
  int min = 987987987;
  
  if(min > a && a!=0)
    min = a;
  if(min > b && b!=0)
    min = b;
  if(min > c && c!=0)
    min = c;
  if(min > d && d!=0)
    min = d;
    
  return min;
}

int getMin2(int a,int b)
{
  int min = 987987987;
  
  if(min > a)
    min = a;
  if(min > b)
    min = b;
    
  return min;
}

int main() {
  
  int N,M;
  int min;
  int tmp;
  int mat[1010][1010] = {0,};
  int semi[1010][1010] = {0,};

  scanf("%d %d", &N, &M);
  
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    {
      scanf("%d", &mat[i][j]);
      if(mat[i][j] == 1 ) 
        mat[i][j] = 987987987;
      semi[i][j] = mat[i][j];
    }
    
  BFS(mat,N,M,N-1,0);
  BFS(semi,N,M,0,M-1);
  
  mat[N-1][0] = 0;
  semi[0][M-1] = 0;
  
  for(int i=N-1;i>=0;i--)
  {
    for(int j=0;j<M;j++)
    {
      mat[i+1][j+1] = mat[i][j];
    }
  }
  
  for(int i=0 ; i<=N+1 ; i++)
  {
    mat[i][0] = 987987987;
    mat[i][M+1] = 987987987;
  }
  
  for(int i=0; i<=M+1; i++)
  {
    mat[0][i] = 987987987;
    mat[N+1][i] = 987987987;
  }
  
  for(int i=N-1;i>=0;i--)
  {
    for(int j=0;j<M;j++)
    {
      semi[i+1][j+1] = semi[i][j];
    }
  }
  
  for(int i=0 ; i<=N+1 ; i++)
  {
    semi[i][0] = 987987987;
    semi[i][M+1] = 987987987;
  }
  
  for(int i=0; i<=M+1; i++)
  {
    semi[0][i] = 987987987;
    semi[N+1][i] = 987987987;
  }
  
  min = 987987987;

  int t1;
  int t2;
  
  for(int i=1;i<=N ; i++)
  {
    for(int j=1;j<=M;j++)
    {
      if(mat[i][j] == 987987987)
      {
        t1 = getMin4(mat[i-1][j],mat[i][j-1],mat[i][j+1],mat[i+1][j]);
        t2 = getMin4(semi[i-1][j],semi[i][j-1],semi[i][j+1],semi[i+1][j]);
        //printf("%d %d --- \n", t1, t2);
        if(min > t1 + t2 + 2)
          min = t1 + t2 + 2;
      }
    }
  }
  
  
  /*for(int i=0;i<N+2;i++)
  {
    for(int j=0;j<M+2;j++)
    {
      if(mat[i][j] == 987987987)
        printf("■ ");
      else
        printf("%2d ", mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  for(int i=0;i<N+2;i++)
  {
    for(int j=0;j<M+2;j++)
    {
      if(semi[i][j] == 987987987)
        printf("■ ");
      else
        printf("%2d ", semi[i][j]);
    }
    printf("\n");
  }*/
  
  printf("%d", min);
  
  return 0;
}


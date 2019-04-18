/*

ICEBERG

지구 온난화로 인하여 북극의 빙산이 녹고 있다. 빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 

빙산 이외의 바다에 해당되는 칸에는 0이 저장된다. 

빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에, 

배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 

단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다. 

2차원 배열에서 동서남북 방향으로 붙어있는 칸들은 서로 연결되어 있다고 말한다. 

한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오. 

만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.


입력

첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다. 

N과 M은 3 이상 300 이하이다. 그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다. 

각 칸에 들어가는 값은 0 이상 10 이하이다. 

배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다. 

배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.
 

출력

첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.

*/

#include <cstdio>
#include <queue>

using namespace std;

int mat[310][310];
int visited[310][310];
int tmp[310][310];
queue<int> Queue[2];

void melt(int x,int y,int N,int M)
{
  int cnt=0;
  
  if(mat[x+1][y] == 0)
    cnt--;

  if(mat[x-1][y] == 0)
    cnt--;
    
  if(mat[x][y+1] == 0)
    cnt--;

  if(mat[x][y-1] == 0)
    cnt--;
    
  tmp[x][y] = cnt;  
  
  return;
}

void BFS(int x,int y,int N,int M)
{
  visited[x][y] = 1;
  
  Queue[0].push(x);
  Queue[1].push(y);
  
  int tx;
  int ty;
  
  while(Queue[0].empty() != 1)
  {
    tx = Queue[0].front();
    ty = Queue[1].front();
    
    Queue[0].pop();
    Queue[1].pop();
  
    if(visited[tx+1][ty] == 0 && mat[tx+1][ty] != 0)
    {
      visited[tx+1][ty] = 1;
      Queue[0].push(tx+1);
      Queue[1].push(ty);
    }
    
    if(visited[tx-1][ty] == 0 && mat[tx-1][ty] != 0)
    {
      visited[tx-1][ty] = 1;
      Queue[0].push(tx-1);
      Queue[1].push(ty);
    }
    
    if(visited[tx][ty+1] == 0 && mat[tx][ty+1] != 0)
    {
      visited[tx][ty+1] = 1;
      Queue[0].push(tx);
      Queue[1].push(ty+1);
    }
 
    if(visited[tx][ty-1] == 0 && mat[tx][ty-1] != 0)
    {
      visited[tx][ty-1] = 1;
      Queue[0].push(tx);
      Queue[1].push(ty-1);
    }
    
  }

  
}

int main() {

  int N,M;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
      scanf("%d", &mat[i][j]);
  }
 
  int cnt=1;
  int flag = 0;
  int tax=0,tay=0;
  
  while(1)
  {
    
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        if(mat[i][j] != 0)
        {
          //주변 바닷물 수만큼 줄여주는 함수
          melt(i,j,N,M);
        }
      }
    }
    
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        mat[i][j] += tmp[i][j];
        
        if(mat[i][j] < 0 )
          mat[i][j] = 0;
        else if(mat[i][j] > 0)
        {
          tax = i;
          tay = j;
        }
        
      }
    }
   
    if(mat[tax][tay] == 0)
    {
      printf("0");
      return 0;
    }
    
    BFS(tax,tay,N,M);
    
    /*for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        printf("%d ", visited[i][j]);
      printf("\n");
    }printf("\n");*/

    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        if(visited[i][j] == 0 && mat[i][j] != 0)
        {
          printf("%d", cnt);
          return 0;
        }
      }
    }
    
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        visited[i][j] = 0;
        tmp[i][j] = 0;
      }
    }
    
    
    cnt++;
  }
  
  
  
  
  return 0;
}
/*

COWART

소에 대해 잘 알려지지 않은 사실은 소들 눈에는 빨간색과 초록색이 같아보이는 적록색약이라는 것이다. 

이 사실은 인간뿐만아니라 소에게도 호소력있는 예술 작품을 만들기 어렵게한다.

크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 

그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 

또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

예를 들어, 그림이 아래와 같은 경우에

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 하지만, 소는 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)

그림이 입력으로 주어졌을 때, 소가 봤을 때와 적록색약이 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.


입력

첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100) 둘째 줄부터 N개 줄에 걸쳐 그림이 주어진다.


출력

적록색약이 아닌 사람이 봤을 때의 구역의 개수와 소가 봤을 때의 구역의 수를 공백으로 구분해 출력한다.

*/

#include <cstdio>
#include <queue>

using namespace std;

char mat[110][110];
int visited[110][110];
queue<int> Queue[2];

int human(int x,int y,int N,char col)
{
  visited[x][y] = 1;
  
  Queue[0].push(x);
  Queue[1].push(y);
  
  int tx;
  int ty;
  
  while(Queue[0].empty()!=1)
  {
    tx = Queue[0].front();
    ty = Queue[1].front();
    
    Queue[0].pop();
    Queue[1].pop();
    
    if(tx+1 < N)
    {
      if(mat[tx+1][ty] == col && visited[tx+1][ty] == 0)
      {
        visited[tx+1][ty] = 1;
        
        Queue[0].push(tx+1);
        Queue[1].push(ty);
      }
    }
    
    if(tx-1 >= 0)
    {
      if(mat[tx-1][ty] == col && visited[tx-1][ty] == 0)
      {
        visited[tx-1][ty] = 1;
        
        Queue[0].push(tx-1);
        Queue[1].push(ty);
      }
    }
    
    if(ty +1 < N)
    {
      if(mat[tx][ty+1] == col && visited[tx][ty+1] == 0)
      {
        visited[tx][ty+1] = 1;
        
        Queue[0].push(tx);
        Queue[1].push(ty+1);
      }
    }
    
    if(ty-1 >= 0)
    {
      if(mat[tx][ty-1] == col && visited[tx][ty-1] == 0)
      {
        visited[tx][ty-1] = 1;
        
        Queue[0].push(tx);
        Queue[1].push(ty-1);
      }
    }
  }
  
  return 1;
}

int cow(int x,int y,int N)
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
    
    if(tx+1 < N)
    {
      if( (mat[tx+1][ty] == 'R' || mat[tx+1][ty] == 'G') && visited[tx+1][ty] == 0 )
      {
        visited[tx+1][ty] = 1;
        
        Queue[0].push(tx+1);
        Queue[1].push(ty);
      }
    }
    
    if(tx-1 >= 0)
    {
      if( (mat[tx-1][ty] == 'R' || mat[tx-1][ty] == 'G') && visited[tx-1][ty] == 0)
      {
        visited[tx-1][ty] = 1;
        
        Queue[0].push(tx-1);
        Queue[1].push(ty);
      }
    }
    
    if(ty + 1 < N)
    {
      if( (mat[tx][ty+1] == 'R' || mat[tx][ty+1] == 'G') && visited[tx][ty+1] == 0)
      {
        visited[tx][ty+1] = 1;
        
        Queue[0].push(tx);
        Queue[1].push(ty+1);
      }
    }
    
    if(ty-1 >= 0)
    {
      if( (mat[tx][ty-1] == 'R' || mat[tx][ty-1] == 'G') && visited[tx][ty-1] == 0)
      {
        visited[tx][ty-1] = 1;
        
        Queue[0].push(tx);
        Queue[1].push(ty-1);
      }
    }
  }
  
  return 1;
}

int main() {

  int N;
  int pCnt=0;
  int cCnt=0;
  
  scanf("%d", &N);
  
  getchar();
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
      scanf(" %c", &mat[i][j]);
    getchar();
  }
  
  /*for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
      printf("%c ", mat[i][j]);
    printf("\n");
  }*/
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      if(visited[i][j] == 0)
        pCnt += human(i,j,N,mat[i][j]);
        
      /*for(int i=0;i<N;i++)
      {
        for(int j=0;j<N;j++)
          printf("%d ", visited[i][j]);
        printf("\n");
      }
      printf("\n");*/
    }
  }
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
      visited[i][j] = 0;
  }
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      if( (mat[i][j] == 'R' || mat[i][j] == 'G') && visited[i][j] == 0)
        cCnt += cow(i,j,N);
      else if( mat[i][j] == 'B' && visited[i][j] == 0)
        cCnt += human(i,j,N,mat[i][j]);
        
      /*for(int i=0;i<N;i++)
      {
        for(int j=0;j<N;j++)
          printf("%d ", visited[i][j]);
        printf("\n");
      }
      printf("\n");*/
        
    }
  }
  
  printf("%d %d", pCnt, cCnt);
  return 0;
}
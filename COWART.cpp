/*

COWART

�ҿ� ���� �� �˷����� ���� ����� �ҵ� ������ �������� �ʷϻ��� ���ƺ��̴� ���ϻ����̶�� ���̴�. 

�� ����� �ΰ��Ӹ��ƴ϶� �ҿ��Ե� ȣ�ҷ��ִ� ���� ��ǰ�� ����� ��ư��Ѵ�.

ũ�Ⱑ N��N�� �׸����� �� ĭ�� R(����), G(�ʷ�), B(�Ķ�) �� �ϳ��� ��ĥ�� �׸��� �ִ�. 

�׸��� �� ���� �������� �������� �ִµ�, ������ ���� ������ �̷���� �ִ�. 

��, ���� ������ �����¿�� ������ �ִ� ��쿡 �� ���ڴ� ���� ������ ���Ѵ�. (������ ���̸� ���� ������ ���ϴ� ��쵵 ���� �����̶� �Ѵ�)

���� ���, �׸��� �Ʒ��� ���� ��쿡

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

���ϻ����� �ƴ� ����� ���� �� ������ ���� �� 4���̴�. (���� 2, �Ķ� 1, �ʷ� 1) ������, �Ҵ� ������ 3�� �� �� �ִ�. (����-�ʷ� 2, �Ķ� 1)

�׸��� �Է����� �־����� ��, �Ұ� ���� ���� ���ϻ����� �ƴ� ����� ���� �� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ� N�� �־�����. (1 �� N �� 100) ��° �ٺ��� N�� �ٿ� ���� �׸��� �־�����.


���

���ϻ����� �ƴ� ����� ���� ���� ������ ������ �Ұ� ���� ���� ������ ���� �������� ������ ����Ѵ�.

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
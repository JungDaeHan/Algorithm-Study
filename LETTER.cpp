/*

LETTER

���� Rĭ, ���� Cĭ���� �������� ǥ ����� ���� �ִ�. ���� ������ ��� ĭ���� �빮�� ���ĺ��� �ϳ��� ���� �ִ�. ���� ��� ĭ (1�� 1��) ���� ���� ���� �ִ�.

���� ������ �� ĭ(�����¿�) ���� �� ĭ���� �̵��� �� �ִ�. �̶� �ż��� ���� ������ ĭ�� ���� ���ĺ��� �ٸ� ���ĺ� ĭ���θ� �̵��� �� �ִ�. ��, ���� ���ĺ��� ���� ĭ�� �� �� ���� �� ����.

���� ������ ���� ĭ�� �������� �� ��, �� ĭ�� �̵��� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ������ ĭ�� �ʱ⿡ ���� ��ġ�ߴ� ĭ�� ���Եȴ�.


�Է�

ù° �ٿ� R�� C�� ��ĭ�� ���̿� �ΰ� �־�����. (1 �� R, C �� 20) ��° �ٺ��� R���� �ٿ� ���ļ� C���� �빮�� ���ĺ����� �־�����.


���

ù° �ٿ� ���� �̵��� �� �ִ� ĭ�� �ִ밪�� ����Ѵ�.

*/

#include <cstdio>
#include <queue>

using namespace std;

int mat[25][25] = {0,};
int dist[25][25] = {0,};
int visited[25][25] = {0,};
char alpha[30];

int isTwice(char x,int idx)
{
  for(int i=0;i<idx;i++)
  {
    //printf("%c %c \n", x, alpha[i]);
    if(x == alpha[i])
      return 1;
  }
  //printf("\n\n");
  return 0;
}

//isTwice�� 0 �̸� �ߺ��� ���� ��

int DFS(int x,int y,int N,int M,int idx,int *cnt)
{
  visited[x][y] = 1;
  
  if(x+1 < N)
  {
    if(visited[x+1][y] == 0 && !isTwice(mat[x+1][y],idx) )
    {
      dist[x+1][y] = dist[x][y] + 1;
      alpha[idx] = mat[x+1][y];
      if(*cnt < dist[x+1][y])
        *cnt = dist[x+1][y];
        
      DFS(x+1,y,N,M,idx+1,cnt);
      visited[x+1][y] = 0;
    }
  }
  
  if(x-1 >= 0)
  {
    if(visited[x-1][y] == 0 && !isTwice(mat[x-1][y],idx))
    {
      dist[x-1][y] = dist[x][y] + 1;
      alpha[idx] = mat[x-1][y];
      if(*cnt < dist[x-1][y])
        *cnt = dist[x-1][y];
      DFS(x-1,y,N,M,idx+1,cnt);
      visited[x-1][y] = 0;
    }
  }
  
  
  if(y+1 < M)
  {
    if(visited[x][y+1] == 0 && !isTwice(mat[x][y+1],idx))
    {
      dist[x][y+1] = dist[x][y] + 1;
      alpha[idx] = mat[x][y+1];
      if(*cnt < dist[x][y+1])
        *cnt = dist[x][y+1];
      DFS(x,y+1,N,M,idx+1,cnt);
      visited[x][y+1] = 0;
    }
  }
  
  if(y-1 >= 0)
  {
    if(visited[x][y-1] == 0 && !isTwice(mat[x][y-1],idx))
    {
      dist[x][y-1] = dist[x][y] + 1;
      alpha[idx] = mat[x][y-1];
      if(*cnt < dist[x][y-1])
        *cnt = dist[x][y-1];
      DFS(x,y-1,N,M,idx+1,cnt);
      visited[x][y-1] = 0;
    }
  }
  return *cnt; 
}

int main() {

  int R,C;
  
  scanf("%d %d", &R, &C);
  
  getchar();
  
  for(int i=0;i<R;i++)
  {
    for(int j=0;j<C;j++)
      scanf("%c", &mat[i][j]);
    getchar();
  }
  
  int depth=1;
  
  dist[0][0] = 1;
  alpha[0] = mat[0][0];
  int max = DFS(0,0,R,C,1,&depth);
  
  printf("%d", max);
  
  
  return 0;
}
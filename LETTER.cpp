/*

LETTER

세로 R칸, 가로 C칸으로 나누어진 표 모양의 판이 있다. 판의 각각의 모든 칸에는 대문자 알파벳이 하나씩 적혀 있다. 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 인접한 네 칸(상하좌우) 중의 한 칸으로 이동할 수 있다. 이때 매순간 여태 지나온 칸에 적힌 알파벳과 다른 알파벳 칸으로만 이동할 수 있다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

말이 가능한 많은 칸을 지나도록 할 때, 몇 칸을 이동할 수 있는지 구하는 프로그램을 작성하시오. 말이 지나는 칸은 초기에 말이 위치했던 칸도 포함된다.


입력

첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R, C ≤ 20) 둘째 줄부터 R개의 줄에 걸쳐서 C개의 대문자 알파벳들이 주어진다.


출력

첫째 줄에 말이 이동할 수 있는 칸의 최대값을 출력한다.

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

//isTwice가 0 이면 중복이 없는 것

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
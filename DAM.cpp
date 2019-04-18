/*

DAM 

��� ���� �ȿ��� ū ȣ���� �ְ�, �װ��� ���� ���� �־���. 

�׷��� ����� �� ���� ���������� ȣ���� �ִ� ���� ������ ��� �ڵ������Ѵ�. 

ȣ���� �ִ� ���� ���� 1�ð��� �� ������ �̵��ϸ�, ���� ���� �����ϴ� ��������. 

���� �� �� �� ��� ���������� ������ �ڵ��´�.

����� ���� ���� ���� �� ������ ������ �޾Ҵ�. 

����� ������� �� ���� �ϰ��ð��� K�ð��� ����� �ִ��� ���� ��� ���� �� �̻� �������� ���ϵ��� �ϴ� ���̴�.


�Է�

ù �ٿ��� �迭�� ũ���� T(1 �� T ��100)�� �־����� ���� �ٺ��� �迭�� ���� �־�����. 

0�� �� �� ��, 1�� �ǹ��̴�. (���� �ǹ��� �ڵ��� ���Ѵٰ� �����Ѵ�.) 

�׸��� �� ���� �ٿ��� ȣ���� ��ǥ x, y(1 �� x, y �� T) �� �־�����, ���� �ٿ��� ���� �������� �ð��� K�� �־�����. 

���� ����� ��ǥ�� (1, 1)�̰�, ������ �ϴ��� ��ǥ�� (T, T)�̴�. ���� ȣ���� ��ǥ������ �ð��� 0�̴�.


���

����� �ϴ� ���� ���ڸ� ����Ѵ�. ����, ������ ���� ��� ������ ���� ���� �� ���ų� �ǹ��� �ѷ��׿� ���� ���̻� ������ ���� ��쿣 "-1"�� ����Ѵ�.

*/

#include <cstdio>
#include <queue>

using namespace std;

int mat[110][110];
int visited[110][110];
queue<int> Queue[2];
int dist[10010];

int BFS(int x,int y,int T,int k)
{
  visited[x][y] = 1;
  
  Queue[0].push(x);
  Queue[1].push(y);
  
  int tx;
  int ty;
  int cnt = 0 ;
  
  while(Queue[0].empty() != 1)
  {
    tx = Queue[0].front();
    ty = Queue[1].front();
    
    Queue[0].pop();
    Queue[1].pop();
    
    if(mat[tx][ty] == k)
      cnt++;
    
    if(tx+1 < T)
    {
      if(mat[tx+1][ty] == 0 && visited[tx+1][ty] == 0)
      {
        visited[tx+1][ty] = 1;
        mat[tx+1][ty] = mat[tx][ty] + 1;
        Queue[0].push(tx+1);
        Queue[1].push(ty);
      }
    }
    
    if(tx-1 >= 0)
    {
      if(mat[tx-1][ty] == 0 && visited[tx-1][ty] == 0)
      {
        visited[tx-1][ty] = 1;
        mat[tx-1][ty] = mat[tx][ty] + 1;
        Queue[0].push(tx-1);
        Queue[1].push(ty);
      }
    }
    
    if(ty+1 < T)
    {
      if(mat[tx][ty+1] == 0 && visited[tx][ty+1] == 0)
      {
        visited[tx][ty+1] = 1;
        mat[tx][ty+1] = mat[tx][ty] + 1;
        Queue[0].push(tx);
        Queue[1].push(ty+1);
      }
    }
    
    if(ty-1 >= 0)
    {
      if(mat[tx][ty-1] == 0 && visited[tx][ty-1] == 0)
      {
        visited[tx][ty-1] = 1;
        mat[tx][ty-1] = mat[tx][ty] + 1;
        Queue[0].push(tx);
        Queue[1].push(ty-1);
      }
    }
  }
  
  return cnt;
}

int main() {

  int T;
  int x,y;
  
  scanf("%d", &T);
  
  for(int i=0;i<T;i++)
    for(int j=0;j<T;j++)
    {
      scanf("%d", &mat[i][j]);
      if(mat[i][j] == 1)
        mat[i][j] = -1;
    }
    
  scanf("%d %d", &x,&y);
  
  x = x-1;
  y = y-1;
  
  int k;
  
  scanf("%d", &k);
  
  if(mat[y][x] == 1)
  {
    printf("-1");
    return 0;
  }
  
  int cnt = BFS(y,x,T,k);
  
  /*for(int i=0;i<T;i++)
  {
    for(int j=0;j<T;j++)
      printf("%2d ", mat[i][j]);
    printf("\n");
  }
  printf("\n");*/
  
  int max = 0;
  
  if(k==0)
  {
    printf("-1");
    return 0;
  }
  
  if(cnt == 0)
  {
    printf("-1");
    return 0;
  }
  
  printf("%d", cnt);
  
  /*for(int i=0;i<T;i++)
  {
    for(int j=0;j<T;j++)
    {
      
      if(max < mat[i][j])
        max = mat[i][j];
    }
  }
  
  if(max < k)
  {
    printf("-1"); 
    return 0;
  }*/
  
  /*
  for(int i=0;i<T;i++)
  {
    for(int j=0;j<T;j++)
      printf("%2d ", mat[i][j]);
    printf("\n");
  }
  printf("\n");*/
  
  /*for(int i=k; dist[i] != 0 ;i++)
  {
    if(min > dist[i])
      min = dist[i];
  }*/
  
  //printf("%d", cnt);
  
  return 0;
}
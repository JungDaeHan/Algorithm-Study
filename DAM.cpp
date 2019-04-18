/*

DAM 

어느 마을 안에는 큰 호수가 있고, 그것을 막는 댐이 있었다. 

그런데 어느날 그 댐이 무너져내려 호수에 있는 물이 마을을 모두 뒤덮으려한다. 

호수에 있는 물은 다음 1시간에 한 블럭으로 이동하며, 물의 양은 무한하다 가정하자. 

물은 상 하 좌 우로 퍼져나가며 마을을 뒤덮는다.

당신은 댐이 터진 순간 이 마을의 지도를 받았다. 

당신이 도와줘야 할 일은 완공시간이 K시간인 댐들을 최대한 빨리 지어서 물이 더 이상 진행하지 못하도록 하는 것이다.


입력

첫 줄에는 배열의 크기인 T(1 ≤ T ≤100)가 주어지고 다음 줄부터 배열의 값이 주어진다. 

0은 텅 빈 길, 1은 건물이다. (물은 건물을 뒤덮지 못한다고 가정한다.) 

그리고 그 다음 줄에는 호수의 좌표 x, y(1 ≤ x, y ≤ T) 가 주어지고, 다음 줄에는 댐이 지어지는 시간인 K가 주어진다. 

왼쪽 상단의 좌표는 (1, 1)이고, 오른쪽 하단의 좌표는 (T, T)이다. 또한 호수의 좌표에서의 시간은 0이다.


출력

지어야 하는 댐의 숫자를 출력한다. 만약, 마을이 전부 잠길 때까지 댐을 지을 수 없거나 건물에 둘러쌓여 물이 더이상 진행을 못할 경우엔 "-1"을 출력한다.

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
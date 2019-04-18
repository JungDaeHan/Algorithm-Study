/*

TREASURE

보물섬 지도를 발견한 후크 선장은 보물을 찾아나섰다. 

보물섬 지도는 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 각 칸은 육지(L)나 바다(W)로 표시되어 있다. 

이 지도에서 이동은 상하좌우로 이웃한 육지로만 가능하며, 한 칸 이동하는데 한 시간이 걸린다. 

보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다. 

육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 같은 곳을 두 번 이상 지나가거나, 멀리 돌아가서는 안된다.

보물 지도가 주어질 때, 보물이 묻혀 있는 두 곳 간의 최단 거리로 이동하는 시간을 구하는 프로그램을 작성하시오.


입력

첫째 줄에는 보물 지도의 세로의 크기와 가로의 크기가 빈칸을 사이에 두고 주어진다. 

이어 L과 W로 표시된 보물 지도가 아래의 예와 같이 주어지며, 각 문자 사이에는 빈 칸이 없다. 

보물 지도의 가로, 세로의 크기는 각각 3이상 50이하이다.


출력

첫째 줄에 보물이 묻혀 있는 두 곳 사이를 최단 거리로 이동하는 시간을 출력한다.

*/

#include <cstdio>
#include <queue>

using namespace std;

queue<int> Queue[2];
char map[51][51];
int tmp[51][51] = {0,};
int visited[51][51] = {0,};

int BFS(int N, int M)
{
  int x,y;
  int cnt = 0;
  
  while(Queue[0].empty() != 1)
  {
    x=Queue[0].front();
    y=Queue[1].front();
    
    Queue[0].pop();
    Queue[1].pop();
    
    if(x+1 < N)
    {
      if(tmp[x+1][y] == 0 && visited[x+1][y] ==0)
      {
        tmp[x+1][y] = tmp[x][y] + 1;
        visited[x+1][y] = 1;
        Queue[0].push(x+1);
        Queue[1].push(y);
        cnt = tmp[x+1][y];
      }
    }
    
    if(x-1 >=0)
    {
      if(tmp[x-1][y] == 0 && visited[x-1][y] == 0)
      {
        tmp[x-1][y] = tmp[x][y] + 1;
        visited[x-1][y] = 1;
        Queue[0].push(x-1);
        Queue[1].push(y);
        if(cnt < tmp[x-1][y])
          cnt = tmp[x-1][y];
      }
    }
    
    if(y+1 < M)
    {
      if(tmp[x][y+1] == 0 && visited[x][y+1] == 0)
      {
        tmp[x][y+1] = tmp[x][y] + 1;
        visited[x][y+1] = 1;
        Queue[0].push(x);
        Queue[1].push(y+1);
        
        if(cnt < tmp[x][y+1])
          cnt = tmp[x][y+1];
      }
    }
    
    if(y-1 >=0)
    {
      if(tmp[x][y-1] == 0 && visited[x][y-1] == 0)
      {
        tmp[x][y-1] = tmp[x][y] + 1;
        visited[x][y-1] = 1;
        Queue[0].push(x);
        Queue[1].push(y-1);
        if(cnt < tmp[x][y-1])
          cnt = tmp[x][y-1];
      }
    }
    
  }
  
  return cnt;
  
}

int main() {

  int N,M;
  
  scanf("%d %d", &N, &M);
  
  getchar();
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      scanf("%c", &map[i][j]);
      if(map[i][j] == 'W')
        tmp[i][j] = -1;
    }
    getchar();
  }
  
  int max = 0;
  int cnt;
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      if(tmp[i][j] == 0)
      {
        //printf("%d %d --- \n", i,j);
        Queue[0].push(i);
        Queue[1].push(j);
        visited[i][j] = 1;
        
        cnt = BFS(N,M);
        
       for(int q=0;q<N;q++)
          for(int p=0;p<M;p++)
            visited[q][p] = 0;
      }
      
      if(max < cnt)
        max = cnt;
        
      for(int a=0;a<N;a++)
      {
        for(int b=0;b<M;b++)
        {
          if(map[a][b] == 'W')
            tmp[a][b] = -1;
          if(map[a][b] == 'L')
            tmp[a][b] = 0;
        }
      }
      
      /*for(int q=0;q<N;q++)
        {
          for(int p=0;p<M;p++)
            printf("%d ", tmp[q][p]);
          printf("\n");
        }
        printf("\n");*/
      
    }
  }
  
  printf("%d", max);

  return 0;
}
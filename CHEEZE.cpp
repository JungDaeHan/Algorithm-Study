/*

CHEEZE

정사각형 칸들로 이루어진 사각형 모양의 판이 있고, 그 위에 얇은 치즈(회색 으로 표시된 부분)가 놓여 있다. 

판의 가장자리에는 치즈가 놓여 있지 않으며 치즈에는 하나 이상의 구멍이 있을 수 있다.

이 치즈를 공기 중에 놓으면 녹게 되는데 공기와 접촉된 칸은 한 시간이 지나면 녹아 없어진다. 

치즈의 구멍 속에는 공기가 없지만 구멍을 둘러싼 치즈가 녹아서 구멍이 열리면 구멍 속으로 공기가 들어 가게 된다.

치즈가 녹는 과정에서 여러 조각으로 나누어 질 수도 있다.

입력으로 사각형 모양의 판의 크기와 한 조각의 치즈가 판 위에 주어졌을 때, 

공기 중에서 치즈가 모두 녹아 없어지는 데 걸리는 시간과 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수 를 구하는 프로그램을 작성하시오.


입력

첫째 줄에는 사각형 모양 판의 세로와 가로의 길이가 양의 정수로 주어진다. 세로와 가로의 길이는 최대 100이다. 

판의 각 가로줄의 모양이 윗 줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 

치즈가 없는 칸은 0, 치즈가 있는 칸은 1로 주어 지며 각 숫자 사이에는 빈칸이 하나씩 있다.


출력

첫째 줄에는 치즈가 모두 녹아서 없어지는 데 걸리는 시간을 출 력하고, 

둘째 줄에는 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 출력한다.

*/

#include <stdio.h>
#include <queue>

using namespace std;

queue<int> Queue[2];
queue<int> cheese_info[2];

int mat[110][110];

void BFS(int x,int y,int N, int M)
{
  
  Queue[0].push(x);
  Queue[1].push(y);
  
  while(Queue[0].empty() != 1)
  {
    
    int tmpx = Queue[0].front();
    int tmpy = Queue[1].front();
    
    Queue[0].pop();
    Queue[1].pop();
    
    if(tmpx + 1 < N)
    {
      if(mat[tmpx+1][tmpy] == 1)
      {
        cheese_info[0].push(tmpx+1);
        cheese_info[1].push(tmpy);
        
      }
      else if(mat[tmpx+1][tmpy] == 0)
      {
        mat[tmpx+1][tmpy] = 2;
        
        Queue[0].push(tmpx+1);
        Queue[1].push(tmpy);
      }
    }
    
    if(tmpx -1 >= 0)
    {
      if(mat[tmpx-1][tmpy] == 1)
      {
        cheese_info[0].push(tmpx-1);
        cheese_info[1].push(tmpy);
        
      }
      else if(mat[tmpx-1][tmpy] == 0)
      {
        mat[tmpx-1][tmpy] = 2;
        
        Queue[0].push(tmpx-1);
        Queue[1].push(tmpy);
      }
    }
    
    if(tmpy + 1 < M)
    {
      if(mat[tmpx][tmpy+1] == 1)
      {
        cheese_info[0].push(tmpx);
        cheese_info[1].push(tmpy+1);
        
      }
      else if(mat[tmpx][tmpy+1] == 0)
      {
        mat[tmpx][tmpy+1] = 2;
        
        Queue[0].push(tmpx);
        Queue[1].push(tmpy+1);
      }
    }
    
    if(tmpy -1 >= 0)
    {
      if(mat[tmpx][tmpy-1] == 1)
      {
        cheese_info[0].push(tmpx);
        cheese_info[1].push(tmpy-1);
        
      }
      else if(mat[tmpx][tmpy-1] == 0)
      {
        mat[tmpx][tmpy-1] = 2;
        
        Queue[0].push(tmpx);
        Queue[1].push(tmpy-1);
      }
    }
    
  }
  
}

int main() {

  int N,M;
  int hour=0;
  int cnt=0;
  int i,j;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      scanf("%d", &mat[i][j]);

  while(1)
  {
    for(i=0;i<N;i++)
    {
      for(j=0;j<M;j++)
      {
        if(mat[i][j] == 1)
          break;
      }
      if(mat[i][j] == 1)
        break;
    }
    
    
    if(i==N && j==M)
    {
      printf("%d\n%d", hour, cnt);
      return 0;
    }
    
    BFS(0,0,N,M);
    cnt=0;
    while(cheese_info[0].empty() != 1)
    {
      if(mat[cheese_info[0].front()][cheese_info[1].front()] == 1)
      {
        mat[cheese_info[0].front()][cheese_info[1].front()] = 0;
        cnt++;
      }
      cheese_info[0].pop();
      cheese_info[1].pop();
       
    }
    
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        //printf("%d ", mat[i][j]);
        if(mat[i][j] == 2)
          mat[i][j] = 0;
      }
      //printf("\n");
    }
    
    //printf("\n\n\n");
    
    hour++;
  }
  
  
  return 0;
}
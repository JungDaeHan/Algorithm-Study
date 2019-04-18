/*

미로찾기(by BFS)

이동할 수 있는 길, 그리고 이동할 수 없는 벽으로 이루어진 크기 N x M 의 지도가 주어진다. 

이 때, (N-1, 0) 에서 출발하여 (0, M-1) 까지 도착하는 최단거리를 출력하는 프로그램을 작성하시오. 


입력

첫째 줄에 지도의 세로 길이 N과 지도의 가로 길이 M이 주어진다. ( 1 ≤ N, M ≤ 1,000 ) 

둘째 줄부터 지도의 정보가 주어진다. 0은 이동할 수 있는 부분, 1은 이동할 수 없는 부분을 나타낸다.


출력

(N-1, 0) 에서 출발하여 (0, M-1) 까지 이동하는 데 필요한 최단거리를 출력한다.

*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int mat[1010][1010];
queue<int> Queue[2];

void BFS(int x,int y,int M,int N)
{
  int tmpx,tmpy;
  int next;
  int distance = 0;
  
  mat[x][y] = 0;
  
  Queue[0].push(x);
  Queue[1].push(y);
  
  while(1)
  {
    //동서남북을 살피면서 0이면 지금까지온 이동거리+1를 넣자
    
    
    tmpx = Queue[0].front();
    tmpy = Queue[1].front();
    
   if(tmpx == 0 && tmpy == M-1)
    {
      int a = mat[tmpx][tmpy-1];
      int b = mat[tmpx+1][tmpy];
      
      printf("%d", mat[tmpx][tmpy]);
      break;
      
      /*if(a != 1 && a != 0 && b != 1 && b != 0)
      {
        if(a<b)
          printf("%d", a);
        else
          printf("%d", b);
      }
      else
      {
        if(a == 1 || a == 0)
          printf("%d", b);
        else if(b == 1 || b == 0)
          printf("%d", a);
      }
      break;*/
    }
    
    
    //printf("%d %d\n", tmpx, tmpy);
    
    Queue[0].pop();
    Queue[1].pop();
    
    if(tmpx >= N || tmpx < 0 || tmpy >= M || tmpy < 0)
      continue;
      
    distance = mat[tmpx][tmpy] + 1;
    
   // printf("%d aa \n", distance);
    //printf("%d %d bb \n", tmpx, tmpy);
    
    if(tmpx+1 < N)
      if(mat[tmpx+1][tmpy] == 0)
      {
        
        mat[tmpx+1][tmpy] = distance;
        Queue[0].push(tmpx+1);
        Queue[1].push(tmpy);
      }
    if(tmpx-1 >=0)
      if(mat[tmpx-1][tmpy] == 0)
      {
    
        mat[tmpx-1][tmpy] = distance;
          
        Queue[0].push(tmpx-1);
        Queue[1].push(tmpy);
      }
    if(tmpy+1 <M)
      if(mat[tmpx][tmpy+1] == 0)
      {
     
        mat[tmpx][tmpy+1] = distance;
          
        Queue[0].push(tmpx);
        Queue[1].push(tmpy+1);
      }
    if(tmpy-1 >= 0)
      if(mat[tmpx][tmpy-1] == 0)
      {
        mat[tmpx][tmpy-1] = distance;
        Queue[0].push(tmpx);
        Queue[1].push(tmpy-1);
      }
      
    
      
  }
  
}

int main() {

  int N,M;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      scanf("%d", &mat[i][j]);
      
  BFS(N-1,0,M,N);
  
  return 0;
}
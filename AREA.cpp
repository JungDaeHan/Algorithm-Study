/*

AREA

눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 

이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.

M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, 

K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지,

그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.


입력

첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. 

M, N, K는 모두 100 이하의 자연수이다. 

둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 

모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 

입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.


출력

첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 

둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.

*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int mat[110][110] = {0,};
int area[10010] = {0,};
int visited[110][110] = {0,};
queue<int> Queue[2];

int BFS(int N,int M)
{
  int area=1;
  int x,y;
  
  while(Queue[0].empty() != 1)
  {
    x = Queue[0].front();
    y = Queue[1].front();
    
    Queue[0].pop();
    Queue[1].pop();
    
    if(x-1 >= 0)
    {
      if(visited[x-1][y] == 0)
      {
        visited[x-1][y] = 1;
        Queue[0].push(x-1);
        Queue[1].push(y);
        area++;
      }
    }
    
    if(x+1 < N )
    {
      if(visited[x+1][y] == 0)
      {
        visited[x+1][y] = 1;
        Queue[0].push(x+1);
        Queue[1].push(y);
        area++;
      }
    }
    
    if(y-1 >= 0)
    {
      if(visited[x][y-1] == 0)
      {
        visited[x][y-1] = 1;
        Queue[0].push(x);
        Queue[1].push(y-1);
        area++;
      }
    }
    
    if(y+1 < M )
    {
      if(visited[x][y+1] == 0)
      {
        visited[x][y+1] = 1;
        Queue[0].push(x);
        Queue[1].push(y+1);
        area++;
      }
    }
  }
  
  return area;
  
}

int main() {

  int M,N,K;
  int x1,y1,x2,y2;
  int idx=0;
  
  scanf("%d %d %d", &M,&N,&K);
  //N이 세로, M 이 가로 . 
  
  for(int k=0;k<K;k++)
  {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    for(int i=x1; i<x2 ; i++ )
    {
      for(int j=y1; j<y2; j++)
      {
        mat[i][j] = 1;
        visited[i][j] = 1;
      }
    }
  }
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      if(visited[i][j] == 1)
        continue;
      
      visited[i][j] = 1;  
        
      Queue[0].push(i);
      Queue[1].push(j);
          
      int tmp = BFS(N,M);
        
      area[idx++] = tmp;
      
    }
  }
  
  sort(area,area+idx);
  
  printf("%d\n", idx);
  for(int i=0;i < idx; i++)
    printf("%d ", area[i]);
 /* printf("\n");
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
      printf("%d ", visited[i][j]);
    printf("\n");
  }*/
  
  
  return 0;
}
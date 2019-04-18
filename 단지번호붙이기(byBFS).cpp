/*

단지번호 붙이기(by BFS)

1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 

철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 

여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 

대각선상에 집이 있는 경우는 연결된 것이 아니다.  

지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.


입력

첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.


출력

첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int mat[30][30];
int danji[1000]; // 길이가 단지수, 
queue<int> Queue[2];

int BFS(int x,int y,int N)
{ //2 는 방문한 것 , 리턴값은 길이

  int tmp;
  int next;
  int cnt=0;
  int i,j;
  
    mat[x][y] = 4;
        
    Queue[0].push(x);
    Queue[1].push(y);
        
    while(1)
    {
      if(Queue[0].empty() == 1)
        break;
          
        i = Queue[0].front();
        j = Queue[1].front();
          
        Queue[0].pop();
        Queue[1].pop();
        
        cnt++;
          
        if(i+1 < N)
        {
          if(mat[i+1][j] == 3)
          {
            mat[i+1][j] = 4;
            Queue[0].push(i+1);
            Queue[1].push(j);
          }
        }
          
        if(i-1 >=0)
        {
          if(mat[i-1][j] == 3)
          {
            mat[i-1][j] = 4;
            Queue[0].push(i-1);
            Queue[1].push(j);
          }
        }
          
        if(j+1 < N)
        {
          if(mat[i][j+1] == 3)
          {
            mat[i][j+1] = 4;
            Queue[0].push(i);
            Queue[1].push(j+1);
          }
        }
          
        if(j-1 >=0)
        {
          if(mat[i][j-1] == 3)
          {
            mat[i][j-1] = 4;
            Queue[0].push(i);
            Queue[1].push(j-1);
          }
        }
          
      }
      
  return cnt;
}

int main() {

  int N;
  int cnt=0;
  int idx=0;
  
  scanf("%d", &N);

  getchar();
  for(int i=0;i<N;i++)
  {
    for(int j=0; j<N ; j++)
    {
      mat[i][j] = getchar();
      mat[i][j] = mat[i][j] - 46;  // 49는 왜 런타임에러?
    }
    getchar();
  }
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      if(mat[i][j] == 3)
      {
        cnt = BFS(i,j,N);
        //printf("%d aaa \n", cnt);
        danji[idx++] = cnt;
      }
    }
  }
  
  sort(danji,danji+idx);
  
  printf("%d\n", idx);
  
  for(int i=0;i<idx;i++)
    printf("%d\n", danji[i]);

  return 0;
}
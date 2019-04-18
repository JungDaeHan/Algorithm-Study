/*

단지번호 붙이기

<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 

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
#include <algorithm>

using namespace std;

int mat[30][30];

void DFS(int x,int y,int *cnt,int N)
{
  //오른쪽, 아래쪽, 위쪽, 왼쪽 순으로 DFS
  
 // if(x < 0 || x >= N || y < 0 || y >= N)
  //  return;
  
  mat[x][y] = 4;
  *cnt = *cnt +1;
  //printf("%d, %d, %d aa \n", *cnt,x,y);
  
  if(mat[x][y+1] == 3 && y+1 < N)
    DFS(x,y+1,cnt,N);
  if(mat[x+1][y] == 3 && x+1 < N)
    DFS(x+1,y,cnt,N);
  if(mat[x-1][y] == 3 && x-1 >= 0)
    DFS(x-1,y,cnt,N);
  if(mat[x][y-1] == 3 && y-1 >= 0)
    DFS(x,y-1,cnt,N);
  
}

//vector<int> Graph[1010];

int main() {

  int N;
  int idx=0;
  int cnt=0;
  char arr[30];
  int danji[1000] = {0,}; // 이 배열의 길이는 단지수
                        // 각 요소는 단지마다의 개수
                        // 정렬 해야함
  
  
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
  
  /*for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
      printf("%d", mat[i][j]);
    printf("\n");
  }*/
  
  for(int i=0;i<N;i++)
  {
   
    for(int j=0;j<N;j++)
    {
       cnt=0;
      if(mat[i][j] == 3)
      {
        DFS(i,j,&cnt,N);
        danji[idx++] = cnt;
      }
    }
  }
  
  printf("%d\n", idx);
  
  sort(danji,danji+idx);
  
  for(int i=0;i<idx;i++)
  {
    printf("%d\n", danji[i]);
  }
  
  return 0;
}
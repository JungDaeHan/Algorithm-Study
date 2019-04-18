/*

SAFETY ZONE

재난방재청에서는 많은 비가 내리는 장마철에 대비해서 다음과 같은 일을 계획하고 있다. 

먼저 어떤 지역의 높이 정보를 파악한다. 그 다음에 그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어 지는 지를 조사하려고 한다. 

이때, 문제를 간단하게 하기 위하여, 장마철에 내리는 비의 양에 따라 일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정한다.

어떤 지역의 높이 정보는 행과 열의 크기가 각각 N인 2차원 배열 형태로 주어지며 배열의 각 원소는 해당 지점의 높이를 표시하는 자연수이다. 

물에 잠기지 않는 안전한 영역이라 함은 물에 잠기지 않는 지점들이 위, 아래, 오른쪽 혹은 왼쪽으로 인접해 있으며 그 크기가 최대인 영역을 말한다. 

장마철에 내리는 비의 양에 따라서 물에 잠기지 않는 안전한 영역의 개수는 다르게 된다. 

어떤 지역의 높이 정보가 주어졌을 때, 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 계산하는 프로그램을 작성하시오.
#include <cstdio>
#include <queue>

using namespace std;

int mat[110][110];
int tmp[110][110];
int isDown[110][110];
queue<int> Queue[2];

void BFS(int N)
{
  int x,y;
  
  while(Queue[0].empty() != 1)
  {
      x = Queue[0].front();
      y = Queue[1].front();
      
      Queue[0].pop();
      Queue[1].pop();
      
      if(x+1 < N)
      {
        if(isDown[x+1][y] == 0)
        {
          isDown[x+1][y] =1;
          Queue[0].push(x+1);
          Queue[1].push(y);
        }
      }
      
      if(x-1 >= 0)
      {
        if(isDown[x-1][y] == 0)
        {
          isDown[x-1][y] = 1;
          Queue[0].push(x-1);
          Queue[1].push(y);
        }
      }
      
      if(y+1 < N)
      {
        if(isDown[x][y+1] == 0)
        {
          isDown[x][y+1] = 1;
          Queue[0].push(x);
          Queue[1].push(y+1);
        }
      }
      
      if(y-1 >= 0)
      {
        if(isDown[x][y-1] == 0)
        {
          isDown[x][y-1] = 1;
          Queue[0].push(x);
          Queue[1].push(y-1);
        }
      }
  }
}

int main() {

  int N;
  int hmax=0;
  
  scanf("%d", &N);
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    { 
      scanf("%d", &mat[i][j]);
      //tmp[i][j] = mat[i][j];
      if(hmax < mat[i][j])
        hmax = mat[i][j];
    }
  }
  
  int max = 1;
  int cnt;
  
  for(int k=1;k<hmax;k++)
  {
    //isDown 이 1 이면 물에 잠긴거임
    cnt = 0;
    
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        isDown[i][j] = 0;
    }
    
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
      {
        if(mat[i][j] <= k)
          isDown[i][j] = 1;
      }
    }
    
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
      {
        if(isDown[i][j] == 1)
          continue;
          
        isDown[i][j] = 1;
        
        Queue[0].push(i);
        Queue[1].push(j);
        
        BFS(N);
      
        cnt++;
        
      }
    }
    if(max < cnt)
      max = cnt;
  }
  
  printf("%d", max);
  
  
  return 0;
}

입력

첫째 줄에는 어떤 지역을 나타내는 2차원 배열의 행과 열의 개수를 나타내는 수 N이 입력된다. N은 2 이상 100 이하의 정수이다. 

둘째 줄부터 N개의 각 줄에는 2차원 배열의 첫 번째 행부터 N번째 행까지 순서대로 한 행씩 높이 정보가 입력된다. 

각 줄에는 각 행의 첫 번째 열부터 N번째 열까지 N개의 높이 정보를 나타내는 자연수가 빈 칸을 사이에 두고 입력된다. 

높이는 1이상 100 이하의 정수이다.


출력

첫째 줄에 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다.

*/


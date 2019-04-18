/*

SLIKAR

사악한 암흑의 군주 임정택은 드디어 원하던 마법 구슬을 손에 넣었고, 알랩숲에 홍수를 일으켰다! 

이 숲에 살고 있는 고슴도치는 지금 당장 비버의 굴로 가능한 빨리 돌아가 홍수를 피하려고 한다.

알랩숲의 지도는 R행 C열로 구성되어 있다. 비어있는 곳은 '.'로 나타나 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표현되어 있다. 

추가적으로, 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 표시되어 있다.

매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. (위, 아래, 오른쪽, 왼쪽) 

물은 매 분마다 물이 있는 칸과 적어도 한 변을 공유하는 비어있는 모든 칸에 물이 차게 된다. 

물과 고슴도치는 돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물은 비버의 소굴로 이동할 수 없다.

알랩숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 도달하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.

고슴도치는 물이 찰 예정인 칸으로 이동할 수 없음에 주의한다.


입력

첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.

다음 R개 줄에 걸쳐 C개의 문자가 주어진다.('.', '*', 'X', 'D' or 'S') 'D'와 'S'는 하나씩만 주어진다.


출력

첫째 줄에 고슴도치가 비버의 굴로 도달할 수 있는 가장 빠른 시간을 출력한다. 

만약, 안전하게 비버의 굴로 이동할 수 없을 경우, "KAKTUS"를 출력한다.

*/

#include<cstdio>
#include<queue>

using namespace std;

queue<int> Queue[2];

char mat[60][60];
char mat2[60][60];

queue<int> water[2];

void sBFS(int N,int M)
{
  while(1)
  {
    if(Queue[0].empty() == 1)
      return;
    
    int tmpx = Queue[0].front();
    int tmpy = Queue[1].front();
    
    Queue[0].pop();
    Queue[1].pop();
    
    if(mat[tmpx][tmpy] == 'D')
      continue;
    
    if(tmpx+1 < N)
    {
      if(mat[tmpx+1][tmpy] =='.')
      {
        mat[tmpx+1][tmpy] = mat[tmpx][tmpy] + 1;
        
        Queue[0].push(tmpx+1);
        Queue[1].push(tmpy);
      }
    }
    
    if(tmpx-1 >=0)
    {
      if(mat[tmpx-1][tmpy] == '.')
      {
        mat[tmpx-1][tmpy] = mat[tmpx][tmpy] +1;
        
        Queue[0].push(tmpx-1);
        Queue[1].push(tmpy);
      }
    }
    
    if(tmpy+1 < M)
    {
      if(mat[tmpx][tmpy+1] == '.')
      {
        mat[tmpx][tmpy+1] = mat[tmpx][tmpy] + 1;
        
        Queue[0].push(tmpx);
        Queue[1].push(tmpy+1);
      }
    }
    
    if(tmpy-1 >=0)
    {
      if(mat[tmpx][tmpy-1] == '.')
      {
        mat[tmpx][tmpy-1] = mat[tmpx][tmpy] +1;
        
        Queue[0].push(tmpx);
        Queue[1].push(tmpy-1);
      }
    }
  }
  
}

void wBFS(int N,int M)
{
  while(1)
  {
    if(water[0].empty() == 1)
      return;
    
    int tmpx = water[0].front();
    int tmpy = water[1].front();
    
    water[0].pop();
    water[1].pop();
    
    if(mat2[tmpx][tmpy] == 'D')
      continue;
    
    if(tmpx+1 < N)
    {
      if(mat2[tmpx+1][tmpy] =='.')
      {
        mat2[tmpx+1][tmpy] = mat2[tmpx][tmpy] + 1;
        
        water[0].push(tmpx+1);
        water[1].push(tmpy);
      }
    }
    
    if(tmpx-1 >=0)
    {
      if(mat2[tmpx-1][tmpy] == '.')
      {
        mat2[tmpx-1][tmpy] = mat2[tmpx][tmpy] +1;
        
        water[0].push(tmpx-1);
        water[1].push(tmpy);
      }
    }
    
    if(tmpy+1 < M)
    {
      if(mat2[tmpx][tmpy+1] == '.')
      {
        mat2[tmpx][tmpy+1] = mat2[tmpx][tmpy] + 1;
        
        water[0].push(tmpx);
        water[1].push(tmpy+1);
      }
    }
    
    if(tmpy-1 >=0)
    {
      if(mat2[tmpx][tmpy-1] == '.')
      {
        mat2[tmpx][tmpy-1] = mat2[tmpx][tmpy] +1;
        
        water[0].push(tmpx);
        water[1].push(tmpy-1);
      }
    }
  }
}

int main() {

  int R,C;
  int endx,endy;
  
  scanf("%d %d", &R, &C);
  
  getchar();
  
  for(int i=0;i<R;i++)
  {
    for(int j=0;j<C;j++)
    scanf(" %c", &mat[i][j]);
    
  }
  
  
  for(int i=0;i<R;i++)
  {
    for(int j=0;j<C;j++)
    {
      mat2[i][j] = mat[i][j];
      
      if(mat[i][j] == '*')
      {
        water[0].push(i);
        water[1].push(j);
        
        mat2[i][j] = 0;
      }
      if(mat[i][j] == 'S')
      {
        Queue[0].push(i);
        Queue[1].push(j);
        
        mat[i][j] = 0;
      }
      if(mat[i][j] == 'D')
      {
        endx= i;
        endy = j;
      }
    }
  }
    
  
    sBFS(R,C);
    wBFS(R,C);
  
   /* for(int i=0;i<R;i++)
    {
      for(int j=0;j<C;j++)
        printf("%d ", mat[i][j]);
      printf("\n");
    }
    
    printf("\n\n");
    
    for(int i=0;i<R;i++)
    {
      for(int j=0;j<C;j++)
        printf("%d ", mat2[i][j]);
      printf("\n");
    }*/
    //mat 이 고슴도치 거리, mat2 는 물 거리
    //즉 mat이 더 작으면 +1 해서 출력하고 return
    
    if(endx-1 >= 0)
    {
      if(mat[endx-1][endy] < mat2[endx-1][endy])
      {
        printf("%d", mat[endx-1][endy] + 1);
        return 0;
      }
    }
    
    if(endx+1 <R)
    {
      if(mat[endx+1][endy] < mat2[endx+1][endy])
      {
        printf("%d", mat[endx+1][endy]+1);
        return 0;
      }
    }
    
    if(endy-1 >= 0)
    {
      if(mat[endx][endy-1] < mat2[endx][endy-1])
      {
        printf("%d", mat[endx][endy-1]+1);
        return 0;
      }
    }
    
    if(endy+1 < C)
    {
      if(mat[endx][endy+1] < mat2[endx][endy+1])
      {
        printf("%d", mat[endx][endy+1]+1);
        return 0;
      }
    }
  
    printf("KAKTUS");
    
  return 0;
}
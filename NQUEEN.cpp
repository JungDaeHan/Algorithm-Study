/*

N-QUEEN

N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 체스판에 놓는 방법의 수를 구하는 프로그램을 작성하시오.

 
입력

첫째 줄에 체스판의 크기인 N이 주어진다. (1 ≤ N < 13)


출력

첫째 줄에 N x N인 체스판 위에 N개의 퀸을 놓을 수 있는 방법의 수를 출력한다.

*/

#include <cstdio>

using namespace std;

int mat[14][14];
int tmpsum=0;
int tmp[14][14]; // 1이면 둘 수 없음

void DFS(int x,int y,int N,int BFScnt)
{
  if(y+1 >= N)
  {
    tmpsum++;
    return;
  }
  
  int tx,ty;
  
  tx = x+1;
  ty = y+1;
  
  while(tx < N && ty < N)
  {
    if(tmp[tx][ty] == 0)
      tmp[tx][ty] = BFScnt;
    
    tx++;
    ty++;
  }
  
  tx = x;
  ty = y+1;
  
  while(ty < N)
  {
    if(tmp[tx][ty] == 0)
      tmp[tx][ty] = BFScnt;
    
    ty++;
  }
  
  tx = x-1;
  ty = y+1;
  
  while(tx >= 0 && ty < N)
  {
    if(tmp[tx][ty] == 0)
      tmp[tx][ty] = BFScnt;
    
    tx--;
    ty++;
  }
  
  /*for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
      printf("%d ", tmp[i][j]);
    printf("\n");
  }
  printf("\n");*/
  
  for(int i=0 ; i<N;i++)
  {
    if(tmp[i][y+1] == 0)
    {
      tmp[i][y+1] = 1;
      DFS(i,y+1,N,BFScnt+1);
      tmp[i][y+1] = 0;
      
      for(int i=0;i<N;i++)
      {
        for(int j=0;j<N;j++)
        {
          if(tmp[i][j] == BFScnt+1)
            tmp[i][j] = 0;
        }
      }
      
    }
  }
  
}

int main() {

  int N;
  int sum = 0;
  
  scanf("%d", &N);
  
  for(int i=0;i<N;i++)
  {
    tmpsum=0;
    DFS(i,0,N,2);
    sum += tmpsum;
    
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
      {
        tmp[i][j] = 0;
      }
  }

  printf("%d", sum);

  return 0;
}
/*

N-QUEEN

N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.

N�� �־����� ��, ���� ü���ǿ� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

 
�Է�

ù° �ٿ� ü������ ũ���� N�� �־�����. (1 �� N < 13)


���

ù° �ٿ� N x N�� ü���� ���� N���� ���� ���� �� �ִ� ����� ���� ����Ѵ�.

*/

#include <cstdio>

using namespace std;

int mat[14][14];
int tmpsum=0;
int tmp[14][14]; // 1�̸� �� �� ����

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
/*

SLIKAR

����� ������ ���� �������� ���� ���ϴ� ���� ������ �տ� �־���, �˷����� ȫ���� �����״�! 

�� ���� ��� �ִ� ����ġ�� ���� ���� ����� ���� ������ ���� ���ư� ȫ���� ���Ϸ��� �Ѵ�.

�˷����� ������ R�� C���� �����Ǿ� �ִ�. ����ִ� ���� '.'�� ��Ÿ�� �ְ�, ���� ���ִ� ������ '*', ���� 'X'�� ǥ���Ǿ� �ִ�. 

�߰�������, ����� ���� 'D'��, ����ġ�� ��ġ�� 'S'�� ǥ�õǾ� �ִ�.

�� �и��� ����ġ�� ���� �ִ� ĭ�� ������ �� ĭ �� �ϳ��� �̵��� �� �ִ�. (��, �Ʒ�, ������, ����) 

���� �� �и��� ���� �ִ� ĭ�� ��� �� ���� �����ϴ� ����ִ� ��� ĭ�� ���� ���� �ȴ�. 

���� ����ġ�� ���� ����� �� ����. ��, ����ġ�� ���� ���ִ� �������� �̵��� �� ����, ���� ����� �ұ��� �̵��� �� ����.

�˷����� ������ �־����� ��, ����ġ�� �����ϰ� ����� ���� �����ϱ� ���� �ʿ��� �ּ� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����ġ�� ���� �� ������ ĭ���� �̵��� �� ������ �����Ѵ�.


�Է�

ù° �ٿ� 50���� �۰ų� ���� �ڿ��� R�� C�� �־�����.

���� R�� �ٿ� ���� C���� ���ڰ� �־�����.('.', '*', 'X', 'D' or 'S') 'D'�� 'S'�� �ϳ����� �־�����.


���

ù° �ٿ� ����ġ�� ����� ���� ������ �� �ִ� ���� ���� �ð��� ����Ѵ�. 

����, �����ϰ� ����� ���� �̵��� �� ���� ���, "KAKTUS"�� ����Ѵ�.

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
    //mat �� ����ġ �Ÿ�, mat2 �� �� �Ÿ�
    //�� mat�� �� ������ +1 �ؼ� ����ϰ� return
    
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
/*

CHEEZE

���簢�� ĭ��� �̷���� �簢�� ����� ���� �ְ�, �� ���� ���� ġ��(ȸ�� ���� ǥ�õ� �κ�)�� ���� �ִ�. 

���� �����ڸ����� ġ� ���� ���� ������ ġ��� �ϳ� �̻��� ������ ���� �� �ִ�.

�� ġ� ���� �߿� ������ ��� �Ǵµ� ����� ���˵� ĭ�� �� �ð��� ������ ��� ��������. 

ġ���� ���� �ӿ��� ���Ⱑ ������ ������ �ѷ��� ġ� ��Ƽ� ������ ������ ���� ������ ���Ⱑ ��� ���� �ȴ�.

ġ� ��� �������� ���� �������� ������ �� ���� �ִ�.

�Է����� �簢�� ����� ���� ũ��� �� ������ ġ� �� ���� �־����� ��, 

���� �߿��� ġ� ��� ��� �������� �� �ɸ��� �ð��� ��� ��� �� �ð� ���� �����ִ� ġ�������� ���� �ִ� ĭ�� ���� �� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ��� �簢�� ��� ���� ���ο� ������ ���̰� ���� ������ �־�����. ���ο� ������ ���̴� �ִ� 100�̴�. 

���� �� �������� ����� �� �ٺ��� ���ʷ� ��° �ٺ��� ������ �ٱ��� �־�����. 

ġ� ���� ĭ�� 0, ġ� �ִ� ĭ�� 1�� �־� ���� �� ���� ���̿��� ��ĭ�� �ϳ��� �ִ�.


���

ù° �ٿ��� ġ� ��� ��Ƽ� �������� �� �ɸ��� �ð��� �� ���ϰ�, 

��° �ٿ��� ��� ��� �� �ð� ���� �����ִ� ġ�������� ���� �ִ� ĭ�� ������ ����Ѵ�.

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
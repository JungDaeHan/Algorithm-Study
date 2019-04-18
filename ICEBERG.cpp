/*

ICEBERG

���� �³�ȭ�� ���Ͽ� �ϱ��� ������ ��� �ִ�. ������ �� �κк� ���� ������ �迭�� �� ĭ�� ���� ������ ����ȴ�. 

���� �̿��� �ٴٿ� �ش�Ǵ� ĭ���� 0�� ����ȴ�. 

������ ���̴� �ٴ幰�� ���� �����ִ� �κп��� �� ���� �پ��� ������, 

�迭���� ������ �� �κп� �ش�Ǵ� ĭ�� �ִ� ���̴� �ϳ⸶�� �� ĭ�� �������� �� �������� �پ��ִ� 0�� ����� ĭ�� ������ŭ �پ���. 

��, �� ĭ�� ����� ���̴� 0���� �� �پ���� �ʴ´�. �ٴ幰�� ȣ��ó�� ���꿡 �ѷ��ο� ���� ���� �ִ�. 

2���� �迭���� �������� �������� �پ��ִ� ĭ���� ���� ����Ǿ� �ִٰ� ���Ѵ�. 

�� ����� ������ �־��� ��, �� ������ �� ��� �̻����� �и��Ǵ� ������ �ð�(��)�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 

���� ���� �� ���� ������ �� ��� �̻����� �и����� ������ ���α׷��� 0�� ����Ѵ�.


�Է�

ù �ٿ��� ������ �迭�� ���� ������ ���� ������ ��Ÿ���� �� ���� N�� M�� �� ���� ��ĭ�� ���̿� �ΰ� �־�����. 

N�� M�� 3 �̻� 300 �����̴�. �� ���� N���� �ٿ��� �� �ٸ��� �迭�� �� ���� ��Ÿ���� M���� ������ �� ���� �� ĭ�� ���̿� �ΰ� �־�����. 

�� ĭ�� ���� ���� 0 �̻� 10 �����̴�. 

�迭���� ������ �����ϴ� ĭ�� ����, ��, 1 �̻��� ������ ���� ĭ�� ������ 10,000 �� �����̴�. 

�迭�� ù ��° ��� ��, ������ ��� ������ �׻� 0���� ä������.
 

���

ù �ٿ� ������ �и��Ǵ� ������ �ð�(��)�� ����Ѵ�. ���� ������ �� ���� ������ �и����� ������ 0�� ����Ѵ�.

*/

#include <cstdio>
#include <queue>

using namespace std;

int mat[310][310];
int visited[310][310];
int tmp[310][310];
queue<int> Queue[2];

void melt(int x,int y,int N,int M)
{
  int cnt=0;
  
  if(mat[x+1][y] == 0)
    cnt--;

  if(mat[x-1][y] == 0)
    cnt--;
    
  if(mat[x][y+1] == 0)
    cnt--;

  if(mat[x][y-1] == 0)
    cnt--;
    
  tmp[x][y] = cnt;  
  
  return;
}

void BFS(int x,int y,int N,int M)
{
  visited[x][y] = 1;
  
  Queue[0].push(x);
  Queue[1].push(y);
  
  int tx;
  int ty;
  
  while(Queue[0].empty() != 1)
  {
    tx = Queue[0].front();
    ty = Queue[1].front();
    
    Queue[0].pop();
    Queue[1].pop();
  
    if(visited[tx+1][ty] == 0 && mat[tx+1][ty] != 0)
    {
      visited[tx+1][ty] = 1;
      Queue[0].push(tx+1);
      Queue[1].push(ty);
    }
    
    if(visited[tx-1][ty] == 0 && mat[tx-1][ty] != 0)
    {
      visited[tx-1][ty] = 1;
      Queue[0].push(tx-1);
      Queue[1].push(ty);
    }
    
    if(visited[tx][ty+1] == 0 && mat[tx][ty+1] != 0)
    {
      visited[tx][ty+1] = 1;
      Queue[0].push(tx);
      Queue[1].push(ty+1);
    }
 
    if(visited[tx][ty-1] == 0 && mat[tx][ty-1] != 0)
    {
      visited[tx][ty-1] = 1;
      Queue[0].push(tx);
      Queue[1].push(ty-1);
    }
    
  }

  
}

int main() {

  int N,M;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
      scanf("%d", &mat[i][j]);
  }
 
  int cnt=1;
  int flag = 0;
  int tax=0,tay=0;
  
  while(1)
  {
    
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        if(mat[i][j] != 0)
        {
          //�ֺ� �ٴ幰 ����ŭ �ٿ��ִ� �Լ�
          melt(i,j,N,M);
        }
      }
    }
    
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        mat[i][j] += tmp[i][j];
        
        if(mat[i][j] < 0 )
          mat[i][j] = 0;
        else if(mat[i][j] > 0)
        {
          tax = i;
          tay = j;
        }
        
      }
    }
   
    if(mat[tax][tay] == 0)
    {
      printf("0");
      return 0;
    }
    
    BFS(tax,tay,N,M);
    
    /*for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        printf("%d ", visited[i][j]);
      printf("\n");
    }printf("\n");*/

    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        if(visited[i][j] == 0 && mat[i][j] != 0)
        {
          printf("%d", cnt);
          return 0;
        }
      }
    }
    
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        visited[i][j] = 0;
        tmp[i][j] = 0;
      }
    }
    
    
    cnt++;
  }
  
  
  
  
  return 0;
}
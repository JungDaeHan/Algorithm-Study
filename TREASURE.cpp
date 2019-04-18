/*

TREASURE

������ ������ �߰��� ��ũ ������ ������ ã�Ƴ�����. 

������ ������ ���簢�� ����̸� ���� ĭ���� �������� �ִ�. �� ĭ�� ����(L)�� �ٴ�(W)�� ǥ�õǾ� �ִ�. 

�� �������� �̵��� �����¿�� �̿��� �����θ� �����ϸ�, �� ĭ �̵��ϴµ� �� �ð��� �ɸ���. 

������ ���� ���� �ִ� �Ÿ��� �̵��ϴµ� �־� ���� �� �ð��� �ɸ��� ���� �� ���� ������ �����ִ�. 

������ ��Ÿ���� �� �� ���̸� �ִ� �Ÿ��� �̵��Ϸ��� ���� ���� �� �� �̻� �������ų�, �ָ� ���ư����� �ȵȴ�.

���� ������ �־��� ��, ������ ���� �ִ� �� �� ���� �ִ� �Ÿ��� �̵��ϴ� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ��� ���� ������ ������ ũ��� ������ ũ�Ⱑ ��ĭ�� ���̿� �ΰ� �־�����. 

�̾� L�� W�� ǥ�õ� ���� ������ �Ʒ��� ���� ���� �־�����, �� ���� ���̿��� �� ĭ�� ����. 

���� ������ ����, ������ ũ��� ���� 3�̻� 50�����̴�.


���

ù° �ٿ� ������ ���� �ִ� �� �� ���̸� �ִ� �Ÿ��� �̵��ϴ� �ð��� ����Ѵ�.

*/

#include <cstdio>
#include <queue>

using namespace std;

queue<int> Queue[2];
char map[51][51];
int tmp[51][51] = {0,};
int visited[51][51] = {0,};

int BFS(int N, int M)
{
  int x,y;
  int cnt = 0;
  
  while(Queue[0].empty() != 1)
  {
    x=Queue[0].front();
    y=Queue[1].front();
    
    Queue[0].pop();
    Queue[1].pop();
    
    if(x+1 < N)
    {
      if(tmp[x+1][y] == 0 && visited[x+1][y] ==0)
      {
        tmp[x+1][y] = tmp[x][y] + 1;
        visited[x+1][y] = 1;
        Queue[0].push(x+1);
        Queue[1].push(y);
        cnt = tmp[x+1][y];
      }
    }
    
    if(x-1 >=0)
    {
      if(tmp[x-1][y] == 0 && visited[x-1][y] == 0)
      {
        tmp[x-1][y] = tmp[x][y] + 1;
        visited[x-1][y] = 1;
        Queue[0].push(x-1);
        Queue[1].push(y);
        if(cnt < tmp[x-1][y])
          cnt = tmp[x-1][y];
      }
    }
    
    if(y+1 < M)
    {
      if(tmp[x][y+1] == 0 && visited[x][y+1] == 0)
      {
        tmp[x][y+1] = tmp[x][y] + 1;
        visited[x][y+1] = 1;
        Queue[0].push(x);
        Queue[1].push(y+1);
        
        if(cnt < tmp[x][y+1])
          cnt = tmp[x][y+1];
      }
    }
    
    if(y-1 >=0)
    {
      if(tmp[x][y-1] == 0 && visited[x][y-1] == 0)
      {
        tmp[x][y-1] = tmp[x][y] + 1;
        visited[x][y-1] = 1;
        Queue[0].push(x);
        Queue[1].push(y-1);
        if(cnt < tmp[x][y-1])
          cnt = tmp[x][y-1];
      }
    }
    
  }
  
  return cnt;
  
}

int main() {

  int N,M;
  
  scanf("%d %d", &N, &M);
  
  getchar();
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      scanf("%c", &map[i][j]);
      if(map[i][j] == 'W')
        tmp[i][j] = -1;
    }
    getchar();
  }
  
  int max = 0;
  int cnt;
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      if(tmp[i][j] == 0)
      {
        //printf("%d %d --- \n", i,j);
        Queue[0].push(i);
        Queue[1].push(j);
        visited[i][j] = 1;
        
        cnt = BFS(N,M);
        
       for(int q=0;q<N;q++)
          for(int p=0;p<M;p++)
            visited[q][p] = 0;
      }
      
      if(max < cnt)
        max = cnt;
        
      for(int a=0;a<N;a++)
      {
        for(int b=0;b<M;b++)
        {
          if(map[a][b] == 'W')
            tmp[a][b] = -1;
          if(map[a][b] == 'L')
            tmp[a][b] = 0;
        }
      }
      
      /*for(int q=0;q<N;q++)
        {
          for(int p=0;p<M;p++)
            printf("%d ", tmp[q][p]);
          printf("\n");
        }
        printf("\n");*/
      
    }
  }
  
  printf("%d", max);

  return 0;
}
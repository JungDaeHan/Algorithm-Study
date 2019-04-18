/*

AREA

������ ������ 1�� M��N(M,N��100)ũ���� �����̰� �ִ�. �� ������ ���� ���ݿ� ���߾� K���� ���簢���� �׸� ��, 

�̵� K���� ���簢���� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ����������.

M, N�� K �׸��� K���� ���簢���� ��ǥ�� �־��� ��, 

K���� ���簢�� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ������������,

�׸��� �и��� �� ������ ���̰� �������� ���Ͽ� �̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ� M�� N, �׸��� K�� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����. 

M, N, K�� ��� 100 ������ �ڿ����̴�. 

��° �ٺ��� K���� �ٿ��� �� �ٿ� �ϳ��� ���簢���� ���� �Ʒ� �������� x, y��ǥ���� ������ �� �������� x, y��ǥ���� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����. 

�������� ���� �Ʒ� �������� ��ǥ�� (0,0)�̰�, ������ �� �������� ��ǥ��(N,M)�̴�. 

�ԷµǴ� K���� ���簢������ ������ ��ü�� ä��� ���� ����.


���

ù° �ٿ� �и��Ǿ� ���������� ������ ������ ����Ѵ�. 

��° �ٿ��� �� ������ ���̸� ������������ �����Ͽ� ��ĭ�� ���̿� �ΰ� ����Ѵ�.

*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int mat[110][110] = {0,};
int area[10010] = {0,};
int visited[110][110] = {0,};
queue<int> Queue[2];

int BFS(int N,int M)
{
  int area=1;
  int x,y;
  
  while(Queue[0].empty() != 1)
  {
    x = Queue[0].front();
    y = Queue[1].front();
    
    Queue[0].pop();
    Queue[1].pop();
    
    if(x-1 >= 0)
    {
      if(visited[x-1][y] == 0)
      {
        visited[x-1][y] = 1;
        Queue[0].push(x-1);
        Queue[1].push(y);
        area++;
      }
    }
    
    if(x+1 < N )
    {
      if(visited[x+1][y] == 0)
      {
        visited[x+1][y] = 1;
        Queue[0].push(x+1);
        Queue[1].push(y);
        area++;
      }
    }
    
    if(y-1 >= 0)
    {
      if(visited[x][y-1] == 0)
      {
        visited[x][y-1] = 1;
        Queue[0].push(x);
        Queue[1].push(y-1);
        area++;
      }
    }
    
    if(y+1 < M )
    {
      if(visited[x][y+1] == 0)
      {
        visited[x][y+1] = 1;
        Queue[0].push(x);
        Queue[1].push(y+1);
        area++;
      }
    }
  }
  
  return area;
  
}

int main() {

  int M,N,K;
  int x1,y1,x2,y2;
  int idx=0;
  
  scanf("%d %d %d", &M,&N,&K);
  //N�� ����, M �� ���� . 
  
  for(int k=0;k<K;k++)
  {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    for(int i=x1; i<x2 ; i++ )
    {
      for(int j=y1; j<y2; j++)
      {
        mat[i][j] = 1;
        visited[i][j] = 1;
      }
    }
  }
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      if(visited[i][j] == 1)
        continue;
      
      visited[i][j] = 1;  
        
      Queue[0].push(i);
      Queue[1].push(j);
          
      int tmp = BFS(N,M);
        
      area[idx++] = tmp;
      
    }
  }
  
  sort(area,area+idx);
  
  printf("%d\n", idx);
  for(int i=0;i < idx; i++)
    printf("%d ", area[i]);
 /* printf("\n");
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
      printf("%d ", visited[i][j]);
    printf("\n");
  }*/
  
  
  return 0;
}
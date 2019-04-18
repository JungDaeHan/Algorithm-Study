/*

������ȣ ���̱�(by BFS)

1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����. 

ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�. 

���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�. 

�밢���� ���� �ִ� ���� ����� ���� �ƴϴ�.  

������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, �� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.


���

ù ��° �ٿ��� �� �������� ����Ͻÿ�. �׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.

*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int mat[30][30];
int danji[1000]; // ���̰� ������, 
queue<int> Queue[2];

int BFS(int x,int y,int N)
{ //2 �� �湮�� �� , ���ϰ��� ����

  int tmp;
  int next;
  int cnt=0;
  int i,j;
  
    mat[x][y] = 4;
        
    Queue[0].push(x);
    Queue[1].push(y);
        
    while(1)
    {
      if(Queue[0].empty() == 1)
        break;
          
        i = Queue[0].front();
        j = Queue[1].front();
          
        Queue[0].pop();
        Queue[1].pop();
        
        cnt++;
          
        if(i+1 < N)
        {
          if(mat[i+1][j] == 3)
          {
            mat[i+1][j] = 4;
            Queue[0].push(i+1);
            Queue[1].push(j);
          }
        }
          
        if(i-1 >=0)
        {
          if(mat[i-1][j] == 3)
          {
            mat[i-1][j] = 4;
            Queue[0].push(i-1);
            Queue[1].push(j);
          }
        }
          
        if(j+1 < N)
        {
          if(mat[i][j+1] == 3)
          {
            mat[i][j+1] = 4;
            Queue[0].push(i);
            Queue[1].push(j+1);
          }
        }
          
        if(j-1 >=0)
        {
          if(mat[i][j-1] == 3)
          {
            mat[i][j-1] = 4;
            Queue[0].push(i);
            Queue[1].push(j-1);
          }
        }
          
      }
      
  return cnt;
}

int main() {

  int N;
  int cnt=0;
  int idx=0;
  
  scanf("%d", &N);

  getchar();
  for(int i=0;i<N;i++)
  {
    for(int j=0; j<N ; j++)
    {
      mat[i][j] = getchar();
      mat[i][j] = mat[i][j] - 46;  // 49�� �� ��Ÿ�ӿ���?
    }
    getchar();
  }
  
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      if(mat[i][j] == 3)
      {
        cnt = BFS(i,j,N);
        //printf("%d aaa \n", cnt);
        danji[idx++] = cnt;
      }
    }
  }
  
  sort(danji,danji+idx);
  
  printf("%d\n", idx);
  
  for(int i=0;i<idx;i++)
    printf("%d\n", danji[i]);

  return 0;
}
/*

������ȣ ���̱�

<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����. 

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
#include <algorithm>

using namespace std;

int mat[30][30];

void DFS(int x,int y,int *cnt,int N)
{
  //������, �Ʒ���, ����, ���� ������ DFS
  
 // if(x < 0 || x >= N || y < 0 || y >= N)
  //  return;
  
  mat[x][y] = 4;
  *cnt = *cnt +1;
  //printf("%d, %d, %d aa \n", *cnt,x,y);
  
  if(mat[x][y+1] == 3 && y+1 < N)
    DFS(x,y+1,cnt,N);
  if(mat[x+1][y] == 3 && x+1 < N)
    DFS(x+1,y,cnt,N);
  if(mat[x-1][y] == 3 && x-1 >= 0)
    DFS(x-1,y,cnt,N);
  if(mat[x][y-1] == 3 && y-1 >= 0)
    DFS(x,y-1,cnt,N);
  
}

//vector<int> Graph[1010];

int main() {

  int N;
  int idx=0;
  int cnt=0;
  char arr[30];
  int danji[1000] = {0,}; // �� �迭�� ���̴� ������
                        // �� ��Ҵ� ���������� ����
                        // ���� �ؾ���
  
  
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
  
  /*for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
      printf("%d", mat[i][j]);
    printf("\n");
  }*/
  
  for(int i=0;i<N;i++)
  {
   
    for(int j=0;j<N;j++)
    {
       cnt=0;
      if(mat[i][j] == 3)
      {
        DFS(i,j,&cnt,N);
        danji[idx++] = cnt;
      }
    }
  }
  
  printf("%d\n", idx);
  
  sort(danji,danji+idx);
  
  for(int i=0;i<idx;i++)
  {
    printf("%d\n", danji[i]);
  }
  
  return 0;
}
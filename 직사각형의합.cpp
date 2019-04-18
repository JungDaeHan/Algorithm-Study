/*

���簢���� ��

N x M �� ���簢���� �־�����, �� ĭ���� ������ ����ִ�. ���� Q���� ������ ���Ͽ� ���� �ؾ� �ϸ�, 

������ ������ (a, b)���� (c, d)������ ���簢���� ����ִ� ������ ���� ���´�. 


�Է�

ù ��° �ٿ� N, M, Q�� �־�����. ( 1 �� N, M �� 1,000, 1 �� Q �� 1,000,000 ) �� ��° �ٺ��� N x M ���簢���� �־�����. 

���簢�� ���� ���� S�� -100�̻� 100�����̴�. �� �� Q���� ������ �־�����. 

������ ������ ��a b c d�� �� �̷�� �� ������, �̴� (a, b) ���� (c, d) ������ ���簢���� ����ִ� ������ ���� ���´�. 

(0 �� a �� c < N, 0 �� b �� d < M)  


���

�� ������ ���� ���� ����Ѵ�.

*/

#include <stdio.h>

int main() {

  int N,M,Q;
  int arr[1000][1000];
  int i,j;
  int x1,y1,x2,y2;
  
  scanf("%d %d %d", &N, &M, &Q);

  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }
  
  for(i=0;i<N;i++)
  {
    for(j=0;j<M;j++)
    {
      if(i==0 && j==0)
        continue;
        
      if(i==0)
      {
        arr[i][j] = arr[i][j] + arr[i][j-1];
        continue;
      }
      if(j==0)
      {
        arr[i][j] = arr[i][j] + arr[i-1][j];
        continue;
      }
      
      arr[i][j] = arr[i][j] + arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
    }
  }
  
  /*for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }*/
  
  for(i=0;i<Q;i++)
  {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    if(x1 ==0 && y1 == 0)
    {
      printf("%d\n", arr[x2][y2]);
      continue;
    }
    
    if(x1 == 0)
    {
      printf("%d\n", arr[x2][y2] - arr[x2][y1-1]);
      continue;
    }
    
    if(y1 == 0)
    {
      printf("%d\n", arr[x2][y2] - arr[x1-1][y2]);
      continue;
    }
    /*
    if(x2 == 0)
    {
      printf("%d\n", arr[x2][y2] - arr[x1][y1-1]);
      continue;
    }
    
    if(y2 == 0)
    {
      printf("%d\n", arr[x2][y2] - arr[x1-1][y1]);
      continue;
    }
    */
    printf("%d\n", arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1]);
  }
  
  

  return 0;
}
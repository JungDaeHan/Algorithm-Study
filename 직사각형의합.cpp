/*

직사각형의 합

N x M 의 직사각형이 주어지며, 각 칸에는 정수가 들어있다. 이제 Q개의 질문에 대하여 답을 해야 하며, 

각각의 질문은 (a, b)부터 (c, d)까지의 직사각형에 들어있는 정수의 합을 묻는다. 


입력

첫 번째 줄에 N, M, Q가 주어진다. ( 1 ≤ N, M ≤ 1,000, 1 ≤ Q ≤ 1,000,000 ) 두 번째 줄부터 N x M 직사각형이 주어진다. 

직사각형 안의 숫자 S는 -100이상 100이하이다. 그 후 Q개의 질문이 주어진다. 

각각의 질문은 “a b c d” 로 이루어 져 있으며, 이는 (a, b) 부터 (c, d) 까지의 직사각형에 들어있는 정수의 합을 묻는다. 

(0 ≤ a ≤ c < N, 0 ≤ b ≤ d < M)  


출력

각 질문에 대한 답을 출력한다.

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
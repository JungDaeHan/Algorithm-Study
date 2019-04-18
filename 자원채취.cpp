/*

자원채취

N x M의 지도가 주어지며, 이 지도의 각 칸에는 자원이 존재한다. 자원의 양은 정수로 나타난다. 

철수는 자원을 채취하는 로봇을 갖고 있으며,

 이 로봇은 (0, 0) 에서 출발하여 (N-1, M-1) 에서 자원 채취를 마친다. 

로봇은 한가지 제약이 있는데, 오른쪽과 아랫쪽으로밖에 움직일 수 없다는 것이다. 

이 로봇을 이용하여 가장 많이 채취할 수 있는 자원의 양을 출력하는 프로그램을 작성하시오. 


입력

첫 번째 줄에 N, M이 주어진다. ( 1 ≤ N, M ≤ 1,000 ) 두 번째 줄부터 N x M 의 지도에 존재하는 자원의 양이 주어진다.


출력

로봇을 이용하여 채취할 수 있는 자원의 양의 최댓값을 출력한다.

*/

#include <stdio.h>

int main() {

  int mat[1000][1000];
  int N,M;
  
  scanf("%d %d", &N, &M);
  
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      scanf("%d", &mat[i][j]);

  for(int i=1;i<N;i++)
    mat[i][0] += mat[i-1][0];
  
  for(int i=1;i<M;i++)
    mat[0][i] += mat[0][i-1];
    
  for(int i=1;i<N;i++)
  {
    for(int j=1;j<M;j++)
    {
      if(mat[i-1][j] + mat[i][j] < mat[i][j-1] + mat[i][j])
        mat[i][j] += mat[i][j-1];
      else
        mat[i][j] += mat[i-1][j];
    }
  }
  
  /*for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }*/
  
  printf("%d", mat[N-1][M-1]);
    

  return 0;
}
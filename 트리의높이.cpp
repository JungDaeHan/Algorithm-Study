/*

트리의 높이

트리의 높이는 루트로부터 가장 멀리 떨어진 노드와의 거리로 정의된다. 

트리가 주어질 때, 그 트리의 높이를 출력하는 프로그램을 작성하시오.

 
입력

첫 번째 줄에 트리의 노드 개수 n, 그리고 루트노드의 번호 r이 주어진다. 

( 1 ≤ n ≤ 100, 0 ≤ r ≤ n - 1 ) 두 번째 줄부터 트리의 간선 정보가 주어진다. 

각 줄은 2개의 숫자 a, b로 이루어지며, 이는 a번 노드와 b번 노드가 연결되어 있다는 뜻이다. 

각 노드의 번호는 0 ~ n-1까지 존재한다. 또한, 연결이 되지않은 노드는 없다.  


출력

트리의 높이를 출력한다.

*/

#include <stdio.h>

int findMax(int edge[][101],int h,int r,int *max)
{
  //r 부터 봐주면서 하나 갈때마다 max 값을 
  // 갱신한 후에 가준다. 
  
  //int tmp;
  
  h++;
  
  for(int i=0;i<101;i++)
  {
    if(edge[r][i] == 1)
    {
      edge[r][i] = 0;
      edge[i][r] = 0;
      
      if(*max < h)
        *max = h;
        
      findMax(edge,h,i,max);
    }
  }
  
  return *max;
}

int main() {

  int n,r;
  int i;
  int edge[101][101] = {0,};
  int x,y;
  int h=0;
  int max=0;
  
  scanf("%d %d", &n, &r);
  
  for(i=0;i<n-1;i++)
  {
    scanf("%d %d", &x, &y);
    
    edge[x][y] = 1;
    edge[y][x] = 1;
    
  }
  
  printf("%d", findMax(edge,0,r,&max));
  
  
  
  
  
  
  return 0;
}
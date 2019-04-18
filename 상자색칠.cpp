
/* 

상자 색칠 문제

면이 6개인 상자가 있다. 이를 여러 가지 색으로 칠하려 하는데, 단 조건이 있다. 
인접한 면에 같은 색깔을 칠하면 안 된다는 것이다. 
여러 가지 색깔이 주어졌을 때, 그 색깔들로 조건을 만족하여 상자의 모든 면을 칠할 수 있는지 판별하는 프로그램을 작성하시오.

 
입력

첫째 줄에 색깔의 개수 N ( 1 <= N <= 1,000 ) 이 주어진다. 
둘째 줄에 색깔을 나타내는 N개의 숫자가 주어진다. 색깔은 양의 정수로 이루어져 있고, 
1부터 N까지의 범위의 수이다.

 
출력

조건을 만족하면서 상자를 칠할 수 있으면 “YES”, 아니면 “NO”를 출력한다.

*/



#include <stdio.h>
#include <malloc.h>

int arrChange(int arr[], int j,int N) // j번째의 값을 없애고, 뒤의 값들을 땡겨줌
{
  for(int i=j;i<N-1;i++)
    arr[i] = arr[i+1];
    
  return N-1;
}

int main() {

  int N;
  int *cor;
  int *tmp; // tmp 값에 
  int len;
  int i,j,a;
  int flag =1;
  
  scanf("%d", &N);

  len = N;
  cor = (int*)malloc(sizeof(int)*N);
  tmp = (int*)malloc(sizeof(int)*6);
  
  for(i=0;i<N;i++)
    scanf("%d", &cor[i]);

  tmp[0] = cor[0];
  len = arrChange(cor,0,N);

  a=len;
  for(j=0;j<len;j++)
  {
    if(tmp[0] != cor[j])
    {
      tmp[1] = cor[j];
      len = arrChange(cor,j,len);
      break;
    }
  }
  if(j==a)
    flag = 0;
  a=len;
  for(j=0;j<len;j++)
  {
   if(tmp[0] != cor[j])
    if(tmp[1] != cor[j])
    {
      tmp[2] = cor[j];
      len = arrChange(cor,j,len);
      break;
    }
  }
  if(j==a)
    flag = 0;
  a=len;
  for(j=0;j<len;j++)
  {
    if(tmp[0] != cor[j])
      if(tmp[2] != cor[j])
      {
        tmp[3] = cor[j];
        len = arrChange(cor,j,len);
        break;
      }
  }
  if(j==a)
    flag= 0;
  a=len;
  for(j=0;j<len;j++)
  {
    if(tmp[0] != cor[j])
      if(tmp[1] != cor[j])
        if(tmp[3] != cor[j])
        {
          tmp[4] = cor[j];
          len = arrChange(cor,j,len);
          break;
        }
  }
  if(j==a)
    flag = 0;
  a=len;
  for(j=0;j<len;j++)
  {
    if(tmp[1] != cor[j] && tmp[2] != cor[j] && tmp[3] != cor[j] && tmp[4] != cor[j])
          {
            tmp[5] = cor[j];
            break;
          }
  }
  if(j==a)
    flag = 0;
    
  if(flag)
    printf("YES");
  else
    printf("NO");
    
  
 return 0;
}
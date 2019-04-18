/*

카드놀이

N개의 카드가 주어지고, 각각은 자연수의 점수를 가진다. 

철수는 이제 이 카드를 가져감으로써 카드에 적혀있는 수 만큼의 점수를 얻는다. 

단, 카드를 가져갈 때 한가지 규칙이 있는데, 이는 연속하여 3개의 카드는 가져갈 수 없다는 것이다. 

예를 들어, 6개의 카드 “1 3 5 2 7 3”가 주어질 경우, 3+5+7+3 = 18 만큼의 점수를 얻는 것이 최대이다. 

N개의 카드가 주어질 때, 얻을 수 있는 점수의 최댓값을 출력하는 프로그램을 작성하시오.


입력

첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 ) 두 번째 줄에 N개의 숫자가 주어지며, 이는 각 카드의 점수를 나타낸다.  


출력

얻을 수 있는 점수의 최댓값을 출력한다.

*/

#include <stdio.h>

int main() {

  int N,i,j;
  int arr[100010];
  int max=0;
  int sum[100010]={0,};
  
  scanf("%d", &N);
  
  for(int i=0;i<N;i++)
    scanf("%d", &arr[i]);
  
  //3을 먹거나, 못먹거나 둘 중 하나.
  // -> 경우의수 : i-1 번째까지의 max 더하기 i 번째.
  //      i-2번쨰 max 더하기 i 번째
  //      i-3번째 max 더하기 i-1,i 
  
  if(N==1)
  {
    printf("%d", arr[0]);
    return 0;
  }
  else if(N==2)
  {
    printf("%d", arr[0]+ arr[1]);
    return 0;
  }
  
  sum[0] = arr[0];
  sum[1] = arr[0] + arr[1];

  if(sum[1] < arr[0] + arr[2])
    sum[2] = arr[0] + arr[2];
  else
    sum[2] = sum[1];
    
  if(sum[2] < arr[1] + arr[2]);
    sum[2] = arr[1] + arr[2];
  
  for(i=3;i<N;i++)
  {
    max  = sum[i-1];
    
    if(max <  sum[i-2] + arr[i])
      max = sum[i-2] + arr[i];
    
    if(max < sum[i-3] + arr[i-1] + arr[i])
      max = sum[i-3] + arr[i-1] + arr[i];
      
    sum[i] = max;
  }
  
  printf("%d", sum[N-1]);
  
  return 0;
}
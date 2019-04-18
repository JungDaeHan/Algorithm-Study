/*

숫자만들기

숫자 1, 2, 3을 이용하여 숫자 N을 만드는 경우의 수를 출력하는 프로그램을 작성하시오. 

예를 들어, N이 4일 경우에는 다음의 7가지 경우가 존재한다. 단, 경우의 수가 매우 많을 수 있으므로, 경우의 수를 1,000,007 로 나눈 나머지를 출력한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
 

입력

첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 )  


출력

1, 2, 3을 이용하여 N을 만들 수 있는 경우의 수를 1,000,007 로 나눈 나머지를 출력한다.  

*/

#include <stdio.h>

int main() {

  int N;
  long long int table[100010]={0,};
  int i,j;
  long long int sum=0;
  long long int cnt=0;
  
  scanf("%d", &N);
  
  table[1] = 1;
  for(i=2;i<=3;i++)
  {
    sum += table[i-1];
    table[i] = sum+1;
  }
  //printf("%d %d %d \n", table[1], table[2], table[3]);
  
  for(i=4;i<=N;i++)
  {
    for(j=i-3 ; j<i ; j++)
    {
      table[i] += table[j];
    }
    if(table[i] >= 1000007)
      table[i] = table[i] % 1000007;
  }
  printf("%d", table[N]);
  
  return 0;
}
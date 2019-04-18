/*

제곱수의합

숫자 N을 제곱수의 합으로 표현하고자 할 때, 사용해야 하는 제곱 수의 최소 개수를 출력하는 프로그램을 작성하시오. 

예를 들어, 숫자 45를 제곱수의 합으로 표현하고자 할 때 필요한 제곱 수의 최소 개수는 2개이며, 이는 다음과 같다.

45 = 3^2 + 6^2
 

입력

첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 )  


출력

필요한 제곱 수의 최소 개수를 출력한다.

*/

#include <stdio.h>
#include <math.h>

int main() {

  int N;
  int tmp;
  int cnt =0;
  int arr[100010];
  int min = 987987987;

  
  scanf("%d", &N);
  
  arr[1] = 1;
  arr[2] = 2;
  
  for(int i=3;i<=N;i++)
  {
    tmp = sqrt(i);
    min = 987987987;

    for(int j=tmp;j>=1;j--)
    {
      if(min > 1 + arr[i-j*j])
        min =  1 + arr[i-j*j];
    }
    arr[i] = min;
  }
  
  printf("%d", arr[N]);
  
  return 0;
}
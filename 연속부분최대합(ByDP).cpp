/*

연속부분최대합(by DP)

N개의 정수가 주어질 때, 연속된 부분을 선택하여 합을 최대화 하는 프로그램을 작성하시오. 

예를 들어, (2,3,-5,8,-3,4,2,-9) 가 있을 때, 최대 값은 ( 8,-3,4,2) 를 골랐을 때이다.
 

입력

첫 번째 줄에 n이 주어진다. ( 1 ≤ n ≤ 1,000,000 ) 두 번째 줄에 n개의 정수가 주어진다.  


출력

연속된 부분을 선택하였을 때의 최댓값을 출력한다.

*/

#include <stdio.h>

int main() {

  int arr[1000010];
  int n;
  int max;
  
  scanf("%d", &n);
  
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);
    
  for(int i=1;i<n;i++)
  {
    if(arr[i] < arr[i] + arr[i-1])
      arr[i] = arr[i] + arr[i-1];
  }
  
  max = arr[0];
  
  for(int i=1;i<n;i++)
  {
    if(max < arr[i])
      max = arr[i];
  }
  
  printf("%d", max);
  
  return 0;
}
/*

거듭제곱구하기L

n과 m이 주어질 때, n의 m승을 구하는 프로그램을 작성하시오. 단, n의 m승의 값이 커질 수 있기 때문에, 정답을 10,007 으로 나눈 나머지를 출력한다.


입력

첫 번째 줄에 숫자 n과 m이 주어진다. ( 1 ≤ n ≤ 100, 1 ≤ m ≤ 1,000,000,000,000,000,000 )  


출력

첫째 줄에 n의 m승을 10,007 으로 나눈 나머지를 출력한다.

*/

#include <stdio.h>
// 이걸 재귀로 ??
int main() {

  long long int n;
  long long int m;
  long long int arr[100000];
  long long int idx=1;
  long long int i;
  long long int tmp;
  
  scanf("%lld %lld", &n, &m);
  
  // n을 한번 곱할때마다 10007 로 나눈 나머지를 배열에 저장
  // 배열의 첫번째와 같은 값이 나온다면 break 한 다나온다면
  // m을 idx 로 나눠서 어떤 나머지가 마지막에 반복되는지를 확인한다.
  
  arr[0] = n%10007;
  tmp = n;
  for(int i=1;i<m;i++)
  {
    tmp = tmp*n;  
    //printf("%lld\n", tmp);
    if(tmp > 10007)
      tmp %= 10007;
    if(tmp%10007 == arr[0])
      break;
    arr[idx++] = tmp%10007;
  }
  // 여기서 idx 는 arr의 길이로 나옴
  
  //for(int i=0;i<idx;i++)
  //  printf("%lld ",arr[i]);
  if(m%idx == 0)
    printf("%lld", arr[idx-1]);
  else
    printf("%lld", arr[m%idx-1]);
  

  return 0;
}
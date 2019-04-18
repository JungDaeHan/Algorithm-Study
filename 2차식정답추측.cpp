/*

2차식 정답 추측

2차식 f(x) = x*x+ x 가 있고, 숫자 a가 주어진다. 우리는 f(x) = a 를 만족하는 x의 값을 찾고 싶지만, 보통 이 값은 정수로 떨어지지 않는 경우가 많다. 

예를 들어, f(x) = 20 을 풀고자 한다면, x = 4이기 때문에 이는 정수이지만, f(x) = 103 을 풀고자 한다면 이는 x = 9.6612... 로써 정수가 아니다.

이 문제에서는 x의 정수부분이 얼마인지를 구하는 프로그램을 작성하시오. 예를 들어, f(x) = 103 을 풀고자 한다면, x = 9.6612... 이기 때문에 정수부분은 9가 된다.


입력

첫 번째 줄에 숫자 a가 주어진다. ( 1 ≤ a ≤ 1,000,000,000,000,000,000 )  


출력

f(x) = a 를 만족하는 x의 정수부분을 출력한다.  

*/

#include <stdio.h>

long long int BinarySearch(long long int start,long long int end,long long int value)
{
  long long int mid=(start+end)/2;
  
  if(start>end)
    return -1;
  if(start==end)
  {
    if(start*start + start <= value && (start+1)*(start+1) + start+1 > value)
      return start;
    else return -1;
  }
  
  if(mid*mid + mid <= value && (mid+1)*(mid+1) + mid+1 > value)
    return mid;
  else if(mid*mid + mid > value)
    return BinarySearch(start,mid-1,value);
  else if((mid+1)*(mid+1) + mid <= value)
    return BinarySearch(mid+1,end,value);

}

int main() {

  long long int a;
  long long int b;
  
  scanf("%lld", &a);

  b = BinarySearch(0,1000000000,a);
  
  printf("%lld", b);

  return 0;
}
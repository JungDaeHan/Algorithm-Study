/*

tobin

두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램을 작성하세요.

 
입력

두 정수 n, k가 입력으로 주어진다. ( 0 < n <= 30, 0 <= k < 8 , n >= k )
 

출력

결과를 내림차순으로 출력한다.

*/


#include <stdio.h>

void tobin(int total,int n,int one,int arr[])
{
  
  if(one == 0)
  {
    for(int i=total-1;i>=0;i--)
      printf("%d", arr[i]);
    printf("\n");
    return;
  }
  
  if(n-1<0)
    return;
    
  arr[n-1] = 1;
  tobin(total,n-1,one-1,arr);
  
  //if(one !=0)
 // {
  arr[n-1] = 0;
  tobin(total,n-1,one,arr);
  //}
  
}
  
  
  /*  
  if(one>0)
  {
    printf("1");
    tobin(n,one-1,zero);
  }
  else
  {
    printf("0");
    tobin(n,one,zero-1);
  }
  */

int main() {

  int n,k;
  int arr[30] = {0,};
  
  scanf("%d %d", &n, &k);//1을 k개 가진 n자리 이진수
  
  tobin(n,n,k,arr);
  
  
  
  return 0;
}
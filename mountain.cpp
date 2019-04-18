/*

mountain

봉우리가 여러개인 산 모양을 출력한다. 산 모양은 그림과 같고 좌우 대칭이다.


입력

첫 번째 줄에 숫자를 입력 받는다. 숫자의 크기는 20보다 작은 자연수이다.


출력

출력 예의 형식으로 출력한다.

*/


#include <stdio.h>

void mountain(int a)
{
  if(a==1)
  {
    printf("1");
    return;
  }
  
    mountain(a-1);
  
  printf("%d", a);
      
    mountain(a-1);  
}

int main() {

  int N;
  int cnt=1;
  int tmp=1;
  
  scanf("%d", &N);
  
  for(int i=2;tmp<N;i*=2)
  {
    cnt += i;
    tmp++;
  }
  
  //printf("%d", cnt);  
  
  mountain(N);
  
  return 0;
}
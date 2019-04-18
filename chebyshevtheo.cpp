/*

chebyshevtheo 

베르트랑-체비쇼프 정리는 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.

이 명제는 조제프 베르트랑(Joseph Louis Francois Bertrand, 1822-1900)이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.

예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다. (11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17, 19, 23)

n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.
  

입력

입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 케이스는 n을 포함하며, 한 줄로 이루어져 있다. (n ≤ 123,456)

입력의 마지막에는 0이 주어진다.

 

출력

각 테스트 케이스에 대해서, n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력한다.

*/



#include <stdio.h>

int main() {

  int n;
  int i,j;
  int cnt=0,tmp_cnt;
  int arr[300000]={0,};
  //0이면 소수
  
  arr[0]=1;
  arr[1]=1;
  arr[2]=0;
  
  
  for(i=2;i<300000;i++)
  {
    if(arr[i] == 1)
      continue;
    
    for(j=2;i*j<300000;j++)
    {
      arr[i*j] = 1;
    }
  }
    
  while(1)
  {
    scanf("%d", &n);
    
    if(n==0)
      return 0;
    
    cnt=0;
    
    for(i=n;i<=2*n;i++)
    {
      if(arr[i] == 0)
        cnt++;

      if(i==n)
        tmp_cnt = cnt;
    }
    
    printf("%d", cnt-tmp_cnt);
    
    if(n>0)
      printf("\n");
    
  }
  
  return 0;
}
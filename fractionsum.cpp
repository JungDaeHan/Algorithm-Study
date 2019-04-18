/*

fractionsum

분자 분모가 모두 자연수인 두 분수의 합 또한 분자 분모가 자연수인 분수로 표현할 수 있다.

두 분수가 주어졌을 때, 그 합을 기약분수의 형태로 구하는 프로그램을 작성하시오.

기약분수란 더 이상 약분되지 않는 분수를 의미한다.  


입력

첫째 줄과 둘째 줄에, 각 분수의 분자와 분모를 뜻하는 두 개의 자연수가 순서대로 주어진다. 

입력되는 네 자연수는 모두 30,000 이하이다.

 

출력

첫째 줄에 구하고자 하는 기약분수의 분자와 분모를 뜻하는 두 개의 자연수를 공백으로 구분하여 순서대로 출력한다.

*/


#include <stdio.h>

int main() {

  int u1,d1;
  int u2,d2;
  int i,j;
  int tmp1,tmp2,upsum;
  int gcd;
  
  scanf("%d %d %d %d", &u1, &d1, &u2, &d2);
  
  tmp1=d1;
  tmp2=d2;
  
  while(1)
  {
    if(tmp1 == 0 )
      break;
     
    if(tmp1 > tmp2)
    {
      i= tmp1;
      tmp1 = tmp2;
      tmp2 = i;
    }
    
    if(tmp2 - tmp1 > tmp1)
      tmp2 = tmp2 - tmp1;
    else
    {
      i=tmp1;
      tmp1 = tmp2 - tmp1;
      tmp2 =    i;
    }
    //printf("%d %d gfdg ", tmp1, tmp2);
  }
  u1 = u1*(d2/tmp2);
  u2 = u2*(d1/tmp2);
  i=d1;
  d1 = d1 * (d2/tmp2);
  d2 = d2 * (i/tmp2);
  
 // printf("%d %d %d %d %d ---",tmp2,u1, d1, u2, d2);
  
  upsum = u1+u2;
  
  tmp1 = upsum;
  //printf("%d %d", upsum, d2);
  
  while(1)
  {
    if(tmp1 == 0 )
      break;
    
    if(tmp1 > d2)
    {
      i = tmp1;
      tmp1 = d2;
      d2 = i;
    }
     
    if(d2 - tmp1 > tmp1)
      d2 = d2 - tmp1;
    else
    {
      i=tmp1;
      tmp1 = d2 - tmp1;
      d2 =    i;
    }
  //  printf("%d %d ", tmp1, d2);
  }
  
  printf("%d %d", upsum/d2 , d1/d2);

  return 0;
}
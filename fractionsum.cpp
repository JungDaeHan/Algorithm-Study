/*

fractionsum

���� �и� ��� �ڿ����� �� �м��� �� ���� ���� �и� �ڿ����� �м��� ǥ���� �� �ִ�.

�� �м��� �־����� ��, �� ���� ���м��� ���·� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���м��� �� �̻� ��е��� �ʴ� �м��� �ǹ��Ѵ�.  


�Է�

ù° �ٰ� ��° �ٿ�, �� �м��� ���ڿ� �и� ���ϴ� �� ���� �ڿ����� ������� �־�����. 

�ԷµǴ� �� �ڿ����� ��� 30,000 �����̴�.

 

���

ù° �ٿ� ���ϰ��� �ϴ� ���м��� ���ڿ� �и� ���ϴ� �� ���� �ڿ����� �������� �����Ͽ� ������� ����Ѵ�.

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
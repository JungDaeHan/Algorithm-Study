/*

mountain

���츮�� �������� �� ����� ����Ѵ�. �� ����� �׸��� ���� �¿� ��Ī�̴�.


�Է�

ù ��° �ٿ� ���ڸ� �Է� �޴´�. ������ ũ��� 20���� ���� �ڿ����̴�.


���

��� ���� �������� ����Ѵ�.

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
/*

���ڸ����

���� 1, 2, 3�� �̿��Ͽ� ���� N�� ����� ����� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

���� ���, N�� 4�� ��쿡�� ������ 7���� ��찡 �����Ѵ�. ��, ����� ���� �ſ� ���� �� �����Ƿ�, ����� ���� 1,000,007 �� ���� �������� ����Ѵ�.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
 

�Է�

ù ��° �ٿ� N�� �־�����. ( 1 �� N �� 100,000 )  


���

1, 2, 3�� �̿��Ͽ� N�� ���� �� �ִ� ����� ���� 1,000,007 �� ���� �������� ����Ѵ�.  

*/

#include <stdio.h>

int main() {

  int N;
  long long int table[100010]={0,};
  int i,j;
  long long int sum=0;
  long long int cnt=0;
  
  scanf("%d", &N);
  
  table[1] = 1;
  for(i=2;i<=3;i++)
  {
    sum += table[i-1];
    table[i] = sum+1;
  }
  //printf("%d %d %d \n", table[1], table[2], table[3]);
  
  for(i=4;i<=N;i++)
  {
    for(j=i-3 ; j<i ; j++)
    {
      table[i] += table[j];
    }
    if(table[i] >= 1000007)
      table[i] = table[i] % 1000007;
  }
  printf("%d", table[N]);
  
  return 0;
}
/*

goodseq

���� 1, 2, 3���θ� �̷������ ������ �ִ�. ������ ������ ������ �� ���� �κ� ������ ������ �� �� ������, �� ������ ���� �����̶�� �θ���. �׷��� ���� ������ ���� �����̴�.

������ ���� ������ ���̴�.

33

32121323

123123213

������ ���� ������ ���̴�.

2

32

32123

1232123

���̰� N�� ���� �������� N�ڸ��� ������ ���� ���� ���� ���� ���� ��Ÿ���� ������ ���ϴ� ���α׷� �� �ۼ��϶�. 

���� ���, 1213121�� 2123212�� ��� ���� ���������� �� �߿��� ���� ���� ��Ÿ���� �� �� 1213121�̴�.


�Է�

�Է��� ���� N�ϳ��� �̷������. N�� 1 �̻� 80 �����̴�.


���

ù ��° �ٿ� 1, 2, 3���θ� �̷���� �ִ� ���̰� N�� ���� ������ �߿��� ���� ���� ���� ��Ÿ�� �� ������ ����Ѵ�. 

������ �̷�� 1, 2, 3�� ���̿��� ��ĭ�� ���� �ʴ´�.

*/

#include <stdio.h>

int isReat(int *arr, int len)
{
  int i,j;
  
  if(len == 2 || len == 3)
    return 0;
    
  for(i=2;i<=len/2 ; i++)
  {
    for(j=1;j<=i;j++)
    {
      if(arr[len-j] != arr[len-i-j])
        break;
    }
    if(j==i+1)
      return 1;
  }
  return 0;
  
}

void makeSeq(int *arr,int N,int idx,int *flag)
{
  int i;
  
  if(*flag == 1)
    return;
    
  if(isReat(arr,idx) == 1)
    return;
  
  if(idx == N)
  {
    for(int i=0;i<N;i++)
      printf("%d", arr[i]);
    *flag = 1;
    return;
  }
  
  if(arr[idx-1] == 1)
  {
    arr[idx] = 2;
    makeSeq(arr,N,idx+1,flag);
    arr[idx] = 3;
    makeSeq(arr,N,idx+1,flag);
  }
  else if(arr[idx-1] == 2)
  {
    arr[idx] = 1;
    makeSeq(arr,N,idx+1,flag);
    arr[idx] = 3;
    makeSeq(arr,N,idx+1,flag);
  }
  else if(arr[idx-1] == 3)
  {
    arr[idx] = 1;
    makeSeq(arr,N,idx+1,flag);
    arr[idx] = 2;
    makeSeq(arr,N,idx+1,flag);
  }
  
  
}

int main() {

  int N;
  int arr[100];
  int flag=0;
  
  scanf("%d", &N);
  
  arr[0] = 1;
  
  makeSeq(arr,N,1,&flag);
  
  //for(int i=0;i<N;i++)
  //  printf("%d", arr[i]);
  
  
  return 0;
}
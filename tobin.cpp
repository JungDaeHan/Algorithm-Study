/*

tobin

�� ���� n, k�� �Է¹޾� k���� 1�� ���� n�ڸ� ���� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.

 
�Է�

�� ���� n, k�� �Է����� �־�����. ( 0 < n <= 30, 0 <= k < 8 , n >= k )
 

���

����� ������������ ����Ѵ�.

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
  
  scanf("%d %d", &n, &k);//1�� k�� ���� n�ڸ� ������
  
  tobin(n,n,k,arr);
  
  
  
  return 0;
}
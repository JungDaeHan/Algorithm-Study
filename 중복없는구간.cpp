/*

�ߺ����±���

n���� ���ڰ� �־�����, �� �߿��� r���� ���ӵ� ���ڸ� �������� ��, �� ���� �κ� ������ ���ڰ� �ߺ����� �ʱ⸦ ���Ѵ�. 

r�� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���, (4, 2, 1, 3)�� �����ϸ� �ǹǷ� r�� �ִ��� 4�̴�. 

r�� 5 �̻��� �� ���, �ߺ� ���� ���� �κ��� �����ϴ� ���� �Ұ����ϴ�.
 

�Է�

ù° �ٿ��� ������ ���� n�� �־�����. ( 1 �� n �� 100,000 ) ��° �ٿ� n���� ���ڰ� �־�����. �� ���ڴ� �׻� 1���� ũ�ų� ����, n���� �۰ų� ����.  

���

r�� �ִ��� ����Ѵ�.

*/

#include <stdio.h>

int check(int arr[], int interval,int len)
{
  int tmp[200000] = {0,};
  int cnt=0,j;
  
  for(int i=0;i<interval;i++)
  {
    tmp[arr[i]]++;
    
    if(tmp[arr[i]] < 2 )
      cnt++;
  }
  if(cnt==interval)
    return 1;
  
  for(int i=0;i<len-interval;i++)
  {
    tmp[arr[i]]--;
    //cnt --;
    tmp[arr[i+interval]]++;
    
    for(j=i+1 ; j<i+interval+1 ; j++)
    {
      if(tmp[arr[j]] >1)
       break;
    }
    
    if(j==i+interval+1)
      return 1;
  }
  
  return 0;
  
}

int main() {

  int n;
  int arr[200000];
  int start,end,mid;
  
  scanf("%d", &n);
  
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);
    
  if(check(arr,1,n) == 0)
  {
    printf("0");
    return 0;
  }
  
  if(check(arr,n,n) == 1)
  {
    printf("%d", n);
    return 0;
  }
  
  start = n; // s�� �׻� �Ұ���
  end = 0; // e�� �׻� ����
  
  while(start - 1 >end)
  {
    mid = (start+end)/2;
    
    if(check(arr,mid,n) == 1) // mid �� �ȴٴ� ���� �ִ밡 �� ���� Ȯ�����ִ�
      end = mid;
    else if(check(arr,mid,n) == 0)
      start = mid;
  }
    
  printf("%d", end) ; 
  return 0;
}
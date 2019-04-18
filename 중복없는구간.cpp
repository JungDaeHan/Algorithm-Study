/*

중복없는구간

n개의 숫자가 주어지고, 이 중에서 r개의 연속된 숫자를 선택했을 때, 이 연속 부분 내에는 숫자가 중복되지 않기를 원한다. 

r의 최댓값을 구하는 프로그램을 작성하시오. 위의 경우, (4, 2, 1, 3)을 선택하면 되므로 r의 최댓값은 4이다. 

r이 5 이상이 될 경우, 중복 없이 연속 부분을 선택하는 것이 불가능하다.
 

입력

첫째 줄에는 숫자의 개수 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 둘째 줄에 n개의 숫자가 주어진다. 각 숫자는 항상 1보다 크거나 같고, n보다 작거나 같다.  

출력

r의 최댓값을 출력한다.

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
  
  start = n; // s는 항상 불가능
  end = 0; // e는 항상 가능
  
  while(start - 1 >end)
  {
    mid = (start+end)/2;
    
    if(check(arr,mid,n) == 1) // mid 가 된다는 것은 최대가 더 있을 확률이있다
      end = mid;
    else if(check(arr,mid,n) == 0)
      start = mid;
  }
    
  printf("%d", end) ; 
  return 0;
}
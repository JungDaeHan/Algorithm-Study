/*

연속부분최대합(divide and conquer)

N개의 정수가 주어질 때, 연속된 부분을 선택하여 합을 최대화 하는 프로그램을 작성하시오. 

예를 들어, (2,3,-5,8,-3,4,2,-9) 가 있다고 하면, (8,-3,4,2) 를 선택했을 때가 최대가 된다.


입력

첫 번째 줄에 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 두 번째 줄에 n개의 정수가 주어진다.
 

출력

연속된 부분을 선택하였을 때의 최댓값을 출력한다.

*/

#include <stdio.h>

int SubMax(int arr[], int start, int end)
{
  // 경계 무시하고 왼쪽, 오른쪽의 부분 최대합만 구함
  int mid;
  int leftsum=0;
  int rightsum=0;
  int leftMax=-987987987;
  int rightMax=-987987987;
  int finalMax=-987987987;
  
  if(start >= end) return arr[start];
  
  mid = (start+end)/2;
  
  int left = SubMax(arr,start,mid);
  int right = SubMax(arr,mid+1,end);
  
  //이제 경계를 포함하는 수들의 최대합을 구함
  
  for(int i=mid;i>=start;i--)
  {
    leftsum += arr[i];
    
    if(leftMax < leftsum )
      leftMax = leftsum;
  }
  
  for(int i=mid+1; i<=end ; i++)
  {
    rightsum += arr[i];
    
    if(rightMax < rightsum)
      rightMax = rightsum;
  }
  finalMax = rightMax + leftMax;
  
  if(finalMax >= left && finalMax >= right) return finalMax;
  else if(right >= finalMax && right >= left) return right;
  else if(left >= finalMax && left >= right) return left;
}

int main() {

  int n;
  int max;
  int arr[100010];
  
  scanf("%d", &n);
  
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);
  
  max = SubMax(arr,0,n-1);
  
  printf("%d", max);

  return 0;
}
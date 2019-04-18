/*

���Ӻκ��ִ���(divide and conquer)

N���� ������ �־��� ��, ���ӵ� �κ��� �����Ͽ� ���� �ִ�ȭ �ϴ� ���α׷��� �ۼ��Ͻÿ�. 

���� ���, (2,3,-5,8,-3,4,2,-9) �� �ִٰ� �ϸ�, (8,-3,4,2) �� �������� ���� �ִ밡 �ȴ�.


�Է�

ù ��° �ٿ� n�� �־�����. ( 1 �� n �� 100,000 ) �� ��° �ٿ� n���� ������ �־�����.
 

���

���ӵ� �κ��� �����Ͽ��� ���� �ִ��� ����Ѵ�.

*/

#include <stdio.h>

int SubMax(int arr[], int start, int end)
{
  // ��� �����ϰ� ����, �������� �κ� �ִ��ո� ����
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
  
  //���� ��踦 �����ϴ� ������ �ִ����� ����
  
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
/*


퀵정렬 


*/


#include <stdio.h>

int getLeft(int arr[],int start,int end,int pivot,int result[])
{ //start부터 end 까지에서 pivot 보다 작거나 같은 값을
// result 에 저장하고 그 길이를 반환하는 함수
  
  int idx=0;
  
  for(int i=start+1;i<=end;i++)
  {
    if(arr[i] <= pivot)
    {
      result[idx++] = arr[i];
    }
  }
  return idx;
}

int getRight(int arr[],int start,int end,int pivot,int result[])
{
  //start부터 end 까지에서 pivot 보다 큰 값을 
  //result 에 저장하고 그 길이를 반환하는 함수
  
  int idx=0;
  
  for(int i=start+1;i<=end;i++)
  {
    if(arr[i] > pivot)
    {
      result[idx++] = arr[i];
    }
  }
  return idx;
  
}

void QuickSort(int arr[],int start,int end)
{//start부터 end까지 퀵 정렬함 ( 0부터가 아님!!!!!!!)

  int pivot = arr[start];
  int i;
  int left[100000];
  int right[100000];
  int leftLen;
  int rightLen;
 
  if(start>=end)
    return;
  
  leftLen = getLeft(arr,start,end,pivot,left);
  rightLen = getRight(arr,start,end,pivot,right);
  
  for(i=0;i<leftLen;i++)
    arr[i+start] = left[i];
  
  arr[i+start] = pivot;
  
  for(i=0;i<rightLen;i++)
    arr[i+start+leftLen+1] = right[i];
  
  QuickSort(arr,start,start+leftLen-1);
  QuickSort(arr,start+leftLen+1,end);
  
  
}

int main() {

  int arr[100000];
  int n;
  
  scanf("%d", &n);
  
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);
    
  QuickSort(arr,0,n-1);
  
  for(int i=0;i<n;i++)
    printf("%d ", arr[i]);

  return 0;
}
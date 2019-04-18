/*


합병정렬


*/


#include <stdio.h>

void merging(int arr[],int s1,int e1,int s2,int e2)
{
  int p,q;
  int tmp[100000];
  int idx=s1;
  
  p=s1;
  q=s2;
  
  while(p<=e1 && q<=e2)
  {
    if(arr[p] < arr[q])
    {
      tmp[idx++] = arr[p];
      p++;
    }
    else
    {
      tmp[idx++] = arr[q];
      q++;
    }
  }
  
  if(p>e1)
  {
    for(int i=q;q<=e2;q++)
      tmp[idx++] = arr[q];
  }
  else if(q>e2)
  {
    for(int i=p;p<=e1;p++)
      tmp[idx++] = arr[p];
  }
  
  for(int i=s1;i<e2+1;i++)
    arr[i] = tmp[i];
}

void mergeSort(int arr[],int start,int end)
{
  int mid = (start+end)/2;
  
  if(start >= end)
    return;
    
  mergeSort(arr,start,mid);
  mergeSort(arr,mid+1,end);
  
  merging(arr,start,mid,mid+1,end);
}

int main() {

  int n;
  int arr[100000];
  
  scanf("%d", &n);
  
  for(int i=0; i<n ;i++)
    scanf("%d", &arr[i]);
  
  mergeSort(arr,0,n-1);  
    
  for(int i=0; i<n ;i++)
    printf("%d ", arr[i]);
    
  return 0;
}
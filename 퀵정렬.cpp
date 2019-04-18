/*


������ 


*/


#include <stdio.h>

int getLeft(int arr[],int start,int end,int pivot,int result[])
{ //start���� end �������� pivot ���� �۰ų� ���� ����
// result �� �����ϰ� �� ���̸� ��ȯ�ϴ� �Լ�
  
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
  //start���� end �������� pivot ���� ū ���� 
  //result �� �����ϰ� �� ���̸� ��ȯ�ϴ� �Լ�
  
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
{//start���� end���� �� ������ ( 0���Ͱ� �ƴ�!!!!!!!)

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
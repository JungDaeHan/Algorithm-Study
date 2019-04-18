/*

�� ���

KOI �μ� ���п����ҿ����� ���� ������ �꼺 ��װ� ��Į���� ����� �����ϰ� �ִ�. 

�� ��׿��� �� ����� Ư���� ��Ÿ���� �ϳ��� ������ �־����ִ�. 

�꼺 ����� Ư������ 1���� 1,000,000,000������ ���� ������ ��Ÿ����, ��Į���� ����� Ư������ -1���� -1,000,000,000������ ���� ������ ��Ÿ����. 

���� ���� �� ����� ȥ���� ����� Ư������ ȥ�տ� ���� �� ����� Ư������ ������ �����Ѵ�. 

�� �����ҿ����� ���� ���� �� ����� ȥ���Ͽ� Ư������ 0�� ���� ����� ����� ������� �Ѵ�. 

���� ���, �־��� ��׵��� Ư������ [-2, 4, -99, -1, 98]�� ��쿡�� Ư������ -99�� ��װ� Ư������ 98�� ����� ȥ���ϸ� Ư������ -1�� ����� ���� �� �ְ�, 

�� ����� Ư������ 0�� ���� ����� ����̴�. �����, �� ������ ��Į���� ��׸����γ� Ȥ�� �� ������ �꼺 ��׸����� Ư������ 0�� ���� ����� ȥ�� ����� ����� ��쵵 ������ �� �ִ�. 

�꼺 ��װ� ��Į���� ����� Ư������ �־����� ��, �� �� �� ���� ���� �ٸ� ����� ȥ���Ͽ� Ư������ 0�� ���� ����� ����� ������ �� ����� ã�� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ��� ��ü ����� �� N�� �Էµȴ�. N�� 2 �̻� 100,000 �����̴�. 

��° �ٿ��� ����� Ư������ ��Ÿ���� N���� ������ ��ĭ�� ���̿� �ΰ� �־�����. 

�� ������ ��� -1,000,000,000 �̻� 1,000,000,000 �����̴�. N���� ��׵��� Ư������ ��� �ٸ���, 

�꼺 ��׸����γ� ��Į���� ��׸����� �Է��� �־����� ��쵵 ���� �� �ִ�.  


���

ù° �ٿ� Ư������ 0�� ���� ����� ����� ������ �� ����� Ư������ ����Ѵ�. 

����ؾ��ϴ� �� ����� Ư������ ������������ ����Ѵ�. 

Ư������ 0�� ���� ����� ����� ������ ��찡 �� �� �̻��� ��쿡�� Ư������ �ּڰ��� ���� ���� ���ڸ� ����Ѵ�. 

�ش� ��쿡�� Ư������ �ּڰ��� ���� ���� ���ٰ� �����Ѵ�. 

*/

#include <stdio.h>
#include<algorithm>
using namespace std;

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

/*
int getLeft(int arr[],int start,int end,int result[],int pivot)
{
  int idx=0;
  
  for(int i=start+1;i<=end;i++)
  {
    if(arr[i] <= pivot)
      result[idx++] = arr[i];
  }
  return idx;
}

int getRight(int arr[],int start,int end,int result[],int pivot)
{
  int idx = 0;
  
  for(int i=start+1;i<=end;i++)
  {
    if(arr[i] > pivot)
      result[idx++] = arr[i];
  }
  return idx;
}

void QuickSort(int arr[],int start,int end)
{
  int pivot = arr[start];
  int left[100000];
  int right[100000];
  int leftLen;
  int rightLen;
  int i;
  
  if(start>=end)
    return;
    
  leftLen = getLeft(arr,start,end,left,pivot);
  rightLen = getRight(arr,start,end,right,pivot);
  
  for(i=0;i<leftLen;i++)
    arr[start+i] = left[i];
  
  arr[start + i] = pivot;
  
  for(i=0;i<rightLen;i++)
    arr[start+leftLen+1+i] = right[i];
    
  QuickSort(arr,start,start+leftLen-1);
  QuickSort(arr,start+leftLen+1,end);
  
}
*/

int distance(int num1,int num2)
{
  if(num1+num2 < 0)
    return -(num1 + num2);
  else
    return (num1+num2);
}

/*int BinarySearch(int fixidx, int arr[],int start, int end,int *min,int minidx)
{//min�� �Ǵ� ��, �װ��� �����ͷ� min ���� �����ϰ� 
 //������ �ּҰ� �Ǵ� arr�� index�� ��ȯ��

  int mid = (start+end)/2;
  int tmp = distance(arr[mid] + arr[fixidx]);
  
  if(start < end && start == fixidx)
    return BinarySearch(fixidx,arr,start+1,end,min,minidx);
  else if(start < end && end == fixidx)
    return BinarySearch(fixidx,arr,start,end-1,min,minidx);
    
  
  if(start+1 >= end)
  {
    if(distance(arr[start] + arr[fixidx]) > distance(arr[end] + arr[fixidx]))
    {
      if(*min > distance(arr[end] + arr[fixidx]))
      {
        *min = distance(arr[end]+arr[fixidx]);
        return end;
      }
      return minidx;
    }
    else if(distance(arr[start] + arr[fixidx]) < distance(arr[end] + arr[fixidx]))
    {
      if(*min > distance(arr[start] + arr[fixidx]))
      {
         *min = distance(arr[start] + arr[fixidx]);
          return start;
      }
      return minidx;
    }
    return minidx;
  }
  
  if(tmp == 0)
  {
    if(fixidx > minidx)
    {  printf("%d %d", arr[minidx], arr[fixidx]);
       *min = 0;
       return minidx;
    }
    else
    {
      printf("%d %d", arr[fixidx], arr[minidx]);
      *min = 0;
      return minidx;
    }
  }
  
  if(*min > tmp)
  {
    *min =tmp;
    minidx = mid;
    
    if(arr[mid] + arr[fixidx] > 0)
      return BinarySearch(fixidx,arr,mid+1,end,min,minidx);
    else
      return BinarySearch(fixidx,arr,start,mid-1,min,minidx);
  }
  else
  {
    if(arr[mid] + arr[fixidx] > 0)
      return BinarySearch(fixidx,arr,mid+1,end,min,minidx);
    else
      return BinarySearch(fixidx,arr,start,mid-1,min,minidx);
  }
}*/

int main() {

  int N;
  int arr[100000];
  //int sumArr[100000];
  int idx=0,j;
  int fixidx,min,tmp,minidx;
  int funcmin;
  int start,end,mid;
  int value1, value2;
  
  scanf("%d", &N);
  
  for(int i=0;i<N;i++)
    scanf("%d", &arr[i]);
    
  mergeSort(arr,0,N-1);
  // sort(arr,arr+N);
  
//  for(int i=0;i<N;i++)
//    printf("%d ", arr[i]);
//  printf("\n");
  
  min = 1000000000;
//  minidx = (N-1)/2;
 // funcmin = 1000010000;
  
  for(int i=0;i<N;i++)
  {
    fixidx = i;
    start = 0;
    end = N-1;
    //idx = BinarySearch(i,arr,0,N-1,&funcmin,minidx);
   
    if(fixidx > start)
    {
      if(min > distance(arr[fixidx],arr[start]))
      {
        min = distance(arr[fixidx],arr[start]);
        value1 = arr[start];
        value2 = arr[fixidx];
      }
    }
    
    if(fixidx < end)
    {
      if(min > distance(arr[fixidx],arr[end]))
      {
        min = distance(arr[fixidx],arr[end]);
        value1 = arr[fixidx];
        value2 = arr[end];
      }
    }
    
    while(start +1 < end)
    {
      mid = (start + end)/2;
      
      if(fixidx == mid)
      {
        start++;
        continue;
      }
      
      if(arr[fixidx] + arr[mid] == 0 )
      {
        printf("%d %d", arr[fixidx], arr[mid]);
        return 0;
      }
      
      //printf("%d---\n", min);
      if(min > distance(arr[fixidx],arr[mid]))
      {
        min = distance(arr[fixidx],arr[mid]);
        value1 = arr[fixidx];
        value2 = arr[mid];
        //printf("%d %d \n", value1, value2);
      }
      
      if(arr[fixidx] + arr[mid] < 0)
        start = mid;
      else
        end = mid;
    }
    
  }
  
  printf("%d %d", value1, value2);
  
  /*
  if(minidx > fixidx)
    printf("%d %d", arr[fixidx], arr[minidx]);
  else
    printf("%d %d", arr[minidx], arr[fixidx]);
  */
  
  return 0;
}
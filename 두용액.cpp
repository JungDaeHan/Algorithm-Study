/*

두 용액

KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다. 

각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다. 

산성 용액의 특성값은 1부터 1,000,000,000까지의 양의 정수로 나타내고, 알칼리성 용액의 특성값은 -1부터 -1,000,000,000까지의 음의 정수로 나타낸다. 

같은 양의 두 용액을 혼합한 용액의 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의한다. 

이 연구소에서는 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 한다. 

예를 들어, 주어진 용액들의 특성값이 [-2, 4, -99, -1, 98]인 경우에는 특성값이 -99인 용액과 특성값이 98인 용액을 혼합하면 특성값이 -1인 용액을 만들 수 있고, 

이 용액이 특성값이 0에 가장 가까운 용액이다. 참고로, 두 종류의 알칼리성 용액만으로나 혹은 두 종류의 산성 용액만으로 특성값이 0에 가장 가까운 혼합 용액을 만드는 경우도 존재할 수 있다. 

산성 용액과 알칼리성 용액의 특성값이 주어졌을 때, 이 중 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액을 찾는 프로그램을 작성하시오.


입력

첫째 줄에는 전체 용액의 수 N이 입력된다. N은 2 이상 100,000 이하이다. 

둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 

이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다. N개의 용액들의 특성값은 모두 다르고, 

산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 경우도 있을 수 있다.  


출력

첫째 줄에 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력한다. 

출력해야하는 두 용액은 특성값의 오름차순으로 출력한다. 

특성값이 0에 가장 가까운 용액을 만들어내는 경우가 두 개 이상일 경우에는 특성값의 최솟값이 가장 작은 숫자를 출력한다. 

해당 경우에서 특성값의 최솟값이 같은 경우는 없다고 가정한다. 

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
{//min값 판단 후, 그것을 포인터로 min 값에 저장하고 
 //절댓값이 최소가 되는 arr의 index를 반환함

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
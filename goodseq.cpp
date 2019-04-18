/*

goodseq

숫자 1, 2, 3으로만 이루어지는 수열이 있다. 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것 이 있으면, 그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 수열이다.

다음은 나쁜 수열의 예이다.

33

32121323

123123213

다음은 좋은 수열의 예이다.

2

32

32123

1232123

길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 구하는 프로그램 을 작성하라. 

예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 그 중에서 작은 수를 나타내는 수 열 1213121이다.


입력

입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.


출력

첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내 는 수열만 출력한다. 

수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.

*/

#include <stdio.h>

int isReat(int *arr, int len)
{
  int i,j;
  
  if(len == 2 || len == 3)
    return 0;
    
  for(i=2;i<=len/2 ; i++)
  {
    for(j=1;j<=i;j++)
    {
      if(arr[len-j] != arr[len-i-j])
        break;
    }
    if(j==i+1)
      return 1;
  }
  return 0;
  
}

void makeSeq(int *arr,int N,int idx,int *flag)
{
  int i;
  
  if(*flag == 1)
    return;
    
  if(isReat(arr,idx) == 1)
    return;
  
  if(idx == N)
  {
    for(int i=0;i<N;i++)
      printf("%d", arr[i]);
    *flag = 1;
    return;
  }
  
  if(arr[idx-1] == 1)
  {
    arr[idx] = 2;
    makeSeq(arr,N,idx+1,flag);
    arr[idx] = 3;
    makeSeq(arr,N,idx+1,flag);
  }
  else if(arr[idx-1] == 2)
  {
    arr[idx] = 1;
    makeSeq(arr,N,idx+1,flag);
    arr[idx] = 3;
    makeSeq(arr,N,idx+1,flag);
  }
  else if(arr[idx-1] == 3)
  {
    arr[idx] = 1;
    makeSeq(arr,N,idx+1,flag);
    arr[idx] = 2;
    makeSeq(arr,N,idx+1,flag);
  }
  
  
}

int main() {

  int N;
  int arr[100];
  int flag=0;
  
  scanf("%d", &N);
  
  arr[0] = 1;
  
  makeSeq(arr,N,1,&flag);
  
  //for(int i=0;i<N;i++)
  //  printf("%d", arr[i]);
  
  
  return 0;
}
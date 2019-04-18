/*

구간의 합집합

구간은 [s, e] 로 나타내고, 이 의미는 s, (s+1), (s+2), …, (e-1), e 와 같이 숫자를 나열한 것을 의미한다. 

예를 들어, [1, 4]는 1, 2, 3, 4로 숫자를 나열한 것을 의미한다. 

n개의 구간이 있고, 이 구간들의 숫자를 모두다 새로운 배열 S에 넣어 정렬을 한다. 

이 때 S[i] 의 값이 무엇인지 출력하는 프로그램을 작성하시오. 

예를 들어, 3개의 구간 [1, 3], [2, 10], [1, 8] 이 있고, S[5]를 알고싶다고 하자. 

그러면 S = [1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10] 이 되고, 따라서 S[5]는 3이 된다. 

배열의 인덱스는 0부터 시작한다는 것에 주의하자.


입력

첫 번째 줄에 구간의 개수 n이 주어진다 ( 1 ≤ n ≤ 10,000 ) 두 번째 줄부터 각 구간을 나타내는 숫자 s, e가 주어진다. ( 1 ≤ s ≤ e ≤ 1,000,000,000 ) 그 후, 마지막 줄에는 값을 알고 싶은 숫자의 위치 i가 주어진다. ( 1 ≤ i ≤ 10,000,000,000,000 ) i번째 위치에는 항상 숫자가 존재한다고 가정한다.  


출력

S[i]를 출력한다.  

*/

#include <stdio.h>

/*long long int check(long long int arr[], long long int interval,int S,long long int fixmid,long long int mididx)
{
  // 정렬된 배열, 0부터 interval 까지의 tmp = (interval+1)*(interval+2)/2 의 값이
  // S보다 작다면 -1을 반환
  // S보다 크다면 tmp에서 (interval)*(interval+1)/2 빼고 (Stmp) 
  // mid의 개수 즉 fixmid((1 + N)/2) - mididx 의 차가 Stmp보다 작다면 min 값을반환
  
  //int tmp = fixmid - distance(fixmid,mididx) + 1;
  
  int sum=0;
  
  for(int i=0 ; i<=interval ; i++)
  {

    if(arr[i] == arr[i+1])
      continue;
  
    sum+= (fixmid - distance(fixmid,i) + 1)*(arr[i+1] - arr[i]);
   //   printf("%d\n",sum );
    if(sum == S) return arr[i+1];
  }
 // printf("%d\n",sum );
  if(sum > S) return -1;
  else return -2;
  
  /*else
  {
    Stmp = tmp - (interval)*(interval+1)/2;
    if(S - (interval)*(interval+1)/2 < Stmp) return arr[interval+1];
    else return -2;
  }/
  
  
}*/

long long int check(long long int arr[][2],long long int mid,long long int S,long long int N)
{
  long long int sum=0;
  long long int midcnt=0;
  
 // long long tmp;
  
  //printf("---%d---\n", mid);
  
  for(int i=0;i<N;i++)
  {
    if(arr[i][0] > mid)
      continue;
    
    if(arr[i][0] == mid)
    {
      sum++;
      midcnt++;
    }
    
    if(arr[i][1] > mid && arr[i][0] < mid)
    {
      sum += mid - arr[i][0] +1;
      midcnt++;
    }
    
    if(arr[i][1] == mid)
    {
      sum += mid - arr[i][0] +1;
      midcnt++;
    }
    
    if(arr[i][1] < mid)
    {
      sum += arr[i][1] - arr[i][0] + 1;
     // midcnt++;
    }
  
   // printf("%d %d\n", sum, midcnt);
  }
  
  //printf("%d %d\n", sum, midcnt);
  //sum--;
 // S++;
  //tmp = sum + midcnt -1;
  
  for(int i=midcnt ; i>=1 ; i--)
  {
    if(sum - i == S)
      return mid;
    
  }
  
  if(sum >S+1) return -1;
  if(sum <S+1) return -2;
  
  
}


int main() {

  long long int n;
  long long int s,e,i;
  long long int arr[10500][2];
  long long int idx=0;
  long long int mid,tmp;
  long long int S;
  long long int start=1000000000;
  long long int end=0;
  scanf("%d", &n);
  
  for(int i=0;i<n;i++)
  {
    scanf("%lld %lld", &s, &e);
   // for(int j=s;j<=e;j++)
    arr[i][0] = s;
    arr[i][1] = e;
   // printf("-%d-", idx);
  }
  
  scanf("%lld", &S);
  
  for(int i=0;i<n;i++)
  {
    if(start > arr[i][0])
      start = arr[i][0];
    
    if(end < arr[i][1])
      end = arr[i][1];
  }
  
  tmp = check(arr,start,S,n);
  
  if(tmp >0)
  {
    printf("%lld", tmp);
    return 0;
  }
  
  tmp = check(arr,end,S,n);
  
  if(tmp > 0)
  {
    printf("%lld", tmp);
    return 0;
  }
  
  while(start +1 < end)
  {
    mid = (start+end)/2;
    tmp = check(arr,mid,S,n);
    
    if(tmp >0)
    {
      printf("%lld", tmp);
      return 0;
    }
    
    if(tmp == -1)
      end = mid;
    else if(tmp == -2)
      start = mid;
      
  }
  
  printf("%d", arr[end]);
  
  return 0;
}
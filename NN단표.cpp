/*

NN단표

알랩이는 구구단표처럼 NN단표를 만들었다고 한다.

NN단표는 2차원 배열의 모양으로 곱셈 1단부터 N단까지의 값들을 적어놓은 형태이다.

NN단표의 배열을 A라고 했을 때, 배열의 들어가는 수 A[i][j]=i*j이다.(즉, 4행 7열에는 28, 7행 5열에는 35가 들어가 있다.)

알랩이는 N단까지 나온 숫자들 중에서 K번째로 작은 수를 찾고 싶어한다.

이때, 중복되는 여러 수들을 고려한다. 즉 N*N개의 모든 수들 중에서 K번째 수를 구하는 것이다.  


입력

첫째 줄에 배열의 크기 N이 주어진다. N은 100,000보다 작거나 같은 자연수이다. 둘째 줄에 K가 주어진다. K는 N*N보다 작거나 같은 자연수이다.  


출력

K번째 원소를 출력한다.

*/

#include <stdio.h>

/*
int count(int num) //약수의 개수도 아니었다 ..
{
  int i=2;
  int sum=1;
  int cnt=1;
  
  while(num!=1)
  {
    if(num%i==0)
    {
      sum+=1;
      num/=i;
      //printf("%d %d\n", sum,num);
      continue;
    }
    cnt*=sum;
    sum=1;
    i++;
  }
  cnt*=sum;
  
  return cnt;
}
*/
long long int check(long long int K,long long int N,long long int value)
{
  // 33 7 49
  long long int sum = 0;
  long long int valuecnt = 0;
  
  for(int i=0;i<N;i++)
  {
    if((value-N*(i+1))/(i+1)>=1)
      sum += value/(i+1)-(value-N*(i+1))/(i+1);
    else
      sum += value/(i+1);
    
    if(value%(i+1) == 0 && value <= N*(i+1))
      valuecnt++;
    
  }
 // printf("%d %d %d\n", sum, value, valuecnt);
  for(int i=valuecnt-1; i>=0 ; i--)
  {
    if(sum - i == K)
      return value;
  }
  
  if(sum > K) return -1;
  else if(sum < K) return -2;
}

int main() {

  //1줄씩 N 단 ?
  //  N = 7
  // 1 2  3  4  5  6  7     8 9 10 11 12 13 14 15 16 
  // 2 4  6  8  10 12 14    7개 , 25-N*2 = 11/2 = 5 K/(i+1)-(K-N*(i+1)) 
  // 3 6  9  12 15 18 21    7게,  25-N*3 = 4/3 = 1 25/3-1 = 7
  // 4 8  12 16 20 24 28    6개, 25-N*4 = -3/4 , 25/4 = 6
  // 5 10 15 20 25 30 35    5개   
  // 6 12 18 24 30 36 42
  // 7 14 21 28 35 42 49    7개, 49-N*7 = -0/7 = - 고려안함=0
  // 8 16
  // 9
  // 10
  // 11
  // 12
  // 13
  // 14
  // 15
  // 16
  
  
  
  //i 와 j의 곱셈으로 이루어져 있다는 걸생각하자 (index)
  
  
  // 5번째 찾을경우 n(n+1)/2 해서 15개만 봐주면 되나.
  
  // 1 * (1~100000)
  // 2 * (1~100000)
  // 3 * (1~100000)
  // 4 * (1~100000)
  // 5 * (1~100000)
  
  long long int N,K;
  long long int arr[100500];
  long long int start,end,mid;
  long long int tmp;
  
  scanf("%d %d", &N, &K);
  
  start = 1;
  end = N*N;
  
  tmp = check(K,N,start);
  
  if((tmp != -1) && (tmp != -2) )
  {
    printf("%lld", start);
    return 0;
  }
  
  tmp = check(K,N,end);
  if((tmp != -1) && (tmp != -2))
  {
    printf("%lld", end);
    return 0;
  }
  
  while(start+1<end)
  {
    mid = (start+end)/2;
    tmp = check(K,N,mid);
    
    if((tmp != -1) && (tmp != -2)) 
    {
      printf("%lld", mid);
      return 0;
    }
    else if(tmp == -1) end = mid;
    else if(tmp == -2) start = mid;
  }
  
  printf("%lld", end);
  

  return 0;
}
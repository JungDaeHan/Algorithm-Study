/*

NN��ǥ

�˷��̴� ������ǥó�� NN��ǥ�� ������ٰ� �Ѵ�.

NN��ǥ�� 2���� �迭�� ������� ���� 1�ܺ��� N�ܱ����� ������ ������� �����̴�.

NN��ǥ�� �迭�� A��� ���� ��, �迭�� ���� �� A[i][j]=i*j�̴�.(��, 4�� 7������ 28, 7�� 5������ 35�� �� �ִ�.)

�˷��̴� N�ܱ��� ���� ���ڵ� �߿��� K��°�� ���� ���� ã�� �;��Ѵ�.

�̶�, �ߺ��Ǵ� ���� ������ ����Ѵ�. �� N*N���� ��� ���� �߿��� K��° ���� ���ϴ� ���̴�.  


�Է�

ù° �ٿ� �迭�� ũ�� N�� �־�����. N�� 100,000���� �۰ų� ���� �ڿ����̴�. ��° �ٿ� K�� �־�����. K�� N*N���� �۰ų� ���� �ڿ����̴�.  


���

K��° ���Ҹ� ����Ѵ�.

*/

#include <stdio.h>

/*
int count(int num) //����� ������ �ƴϾ��� ..
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

  //1�پ� N �� ?
  //  N = 7
  // 1 2  3  4  5  6  7     8 9 10 11 12 13 14 15 16 
  // 2 4  6  8  10 12 14    7�� , 25-N*2 = 11/2 = 5 K/(i+1)-(K-N*(i+1)) 
  // 3 6  9  12 15 18 21    7��,  25-N*3 = 4/3 = 1 25/3-1 = 7
  // 4 8  12 16 20 24 28    6��, 25-N*4 = -3/4 , 25/4 = 6
  // 5 10 15 20 25 30 35    5��   
  // 6 12 18 24 30 36 42
  // 7 14 21 28 35 42 49    7��, 49-N*7 = -0/7 = - �������=0
  // 8 16
  // 9
  // 10
  // 11
  // 12
  // 13
  // 14
  // 15
  // 16
  
  
  
  //i �� j�� �������� �̷���� �ִٴ� �ɻ������� (index)
  
  
  // 5��° ã����� n(n+1)/2 �ؼ� 15���� ���ָ� �ǳ�.
  
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
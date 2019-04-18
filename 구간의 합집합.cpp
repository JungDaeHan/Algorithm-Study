/*

������ ������

������ [s, e] �� ��Ÿ����, �� �ǹ̴� s, (s+1), (s+2), ��, (e-1), e �� ���� ���ڸ� ������ ���� �ǹ��Ѵ�. 

���� ���, [1, 4]�� 1, 2, 3, 4�� ���ڸ� ������ ���� �ǹ��Ѵ�. 

n���� ������ �ְ�, �� �������� ���ڸ� ��δ� ���ο� �迭 S�� �־� ������ �Ѵ�. 

�� �� S[i] �� ���� �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

���� ���, 3���� ���� [1, 3], [2, 10], [1, 8] �� �ְ�, S[5]�� �˰�ʹٰ� ����. 

�׷��� S = [1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10] �� �ǰ�, ���� S[5]�� 3�� �ȴ�. 

�迭�� �ε����� 0���� �����Ѵٴ� �Ϳ� ��������.


�Է�

ù ��° �ٿ� ������ ���� n�� �־����� ( 1 �� n �� 10,000 ) �� ��° �ٺ��� �� ������ ��Ÿ���� ���� s, e�� �־�����. ( 1 �� s �� e �� 1,000,000,000 ) �� ��, ������ �ٿ��� ���� �˰� ���� ������ ��ġ i�� �־�����. ( 1 �� i �� 10,000,000,000,000 ) i��° ��ġ���� �׻� ���ڰ� �����Ѵٰ� �����Ѵ�.  


���

S[i]�� ����Ѵ�.  

*/

#include <stdio.h>

/*long long int check(long long int arr[], long long int interval,int S,long long int fixmid,long long int mididx)
{
  // ���ĵ� �迭, 0���� interval ������ tmp = (interval+1)*(interval+2)/2 �� ����
  // S���� �۴ٸ� -1�� ��ȯ
  // S���� ũ�ٸ� tmp���� (interval)*(interval+1)/2 ���� (Stmp) 
  // mid�� ���� �� fixmid((1 + N)/2) - mididx �� ���� Stmp���� �۴ٸ� min ������ȯ
  
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
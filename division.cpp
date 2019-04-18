/*

division

임의의 자연수는 그보다 작은 자연수들의 합으로 표현될 수 있다. 예를 들어 4의 경우,

4 = 3+1
  = 2+2 
  = 2+1+1 
  = 1+1+1+1

위와 같은 방법으로 표현 될 수 있다. 이 때 , 숫자의 구성이 같으면서 그 순서만이 다른 경우는 같은 경우로 생각하는데, 예를 들어 다음 세 가지 경우는 모두 같은 경우이다.

2 + 1 + 1, 1 + 2 + 1 , 1 + 1 + 2

자연수 n을 입력 받아 이를 n보다 작은 자연수들의 합으로 나타내는 방법을 모두 출력하는 프로그램을 재귀 호출을 사용하여 작성하시오.

 
입력

첫 줄에 2 이상 20 이하의 자연수 n이 주어진다.


출력

첫째 줄부터 모든 방법을 한 줄에 하나씩 출력한다. 하나의 식 안에는 큰 숫자가 앞으로 오도록 하고, 전체적으로는 앞의 숫자가 큰 식이 먼저 출력되도록 한다. 

숫자와 더하기 사이에는 공백이 없다. 그리고 마지막 줄에는 나누어진 자연수의 개수를 출력한다.

*/


#include <stdio.h>
#include <string.h>

int division(int n,char arr[],int idx,int *cnt)
{
  
  int i,j,sum=0;

  for(i=0;i<strlen(arr);i++)
    sum += arr[i];
 
  
  for(i=0;i<strlen(arr);i++)
  {
    if(arr[i] < arr[i+1])
      return *cnt;
  }
 
  if(sum>n)
    return *cnt;
  
  if(sum == n)
  {
    printf("%d",arr[0]);
    for(i=1;i<strlen(arr);i++)
      printf("+%d",arr[i]);
    printf("\n");
    *cnt+=1;
    i-=1;
    while(arr[i] == 1) // 이렇게 하지말고 sum 계산때 index로 범위두기
      arr[i--] = 0;
    return *cnt;
  }

  for(i=n-1;i>0;i--)
  {
    arr[idx] = i;
    
    division(n,arr,idx+1,cnt);
    
  }
  
  
   /*if(n==0)
  {
    printf("%d",arr[0]);
    for(i=1;i<strlen(arr);i++)
      printf("+%d",arr[i]);
    printf("\n");
    return cnt;
  }*/
  
    /*if(n==1)
  {
    printf("%d",arr[0]);
    for(i=1;i<strlen(arr);i++)
      printf("+%d",arr[i]);
    printf("+1\n");
    return cnt;
  }*/
  
  
  /*if(arr[0] == n-1)
  {
    printf("%d+%d\n", arr[0],arr[1]);
    return;
  }
  
  for(i=2;i<n;i++)
  {
    for(j=0;j<i;j++)
    {
      if(arr[j] == 1)
        tmp[j] += tmp[j+1];
    }
    division(n,tmp,len-1);
  }
  */
  
  
  
  /*if(len == 2 && arr[1] == 1)
  {
    printf("%d+%d\n", arr[0], arr[1]);
    return;
  }
  
  printf("%d", arr[0]);
  for(int i=1;i<len;i++)
  {
    printf("+%d", arr[i]);
  }
  printf("\n");
  
  
  for(int i=0;i<len;i++)
  {
    if(len == 2)
    {
      arr[0] += 1;
      arr[1] -= 1;
      break;
    }
    if(arr[i] == 1 && arr[i+1] ==1)
    {
      arr[i] = 2;
      len -= 1;
      break;
    }
    else if(i == len-1)
    {
      arr[len-2] += arr[len-1];
      len -=1;
    }
  }
  
  
  division(n,arr,len);*/
  
  /*printf("%d", arr[0]);
  for(int i=1;i<len;i++)
  {
    printf("+%d", arr[i]);
  }
  printf("\n");*/
  
  
  
  
  
  
 /* int sum=0;
  
  for(int i=0;i<strlen(arr);i++)
  {
    printf("---%d---\n", arr[i]);
    sum+= arr[i];
  }
  printf("asdf\n");
  
  if(sum==n || f==1)
  {
    printf("%d", arr[0]);
    for(int i=1;i<strlen(arr);i++)
    {
      printf("+");
      printf("%d", arr[i]);
    }
    printf("\n");
    return;
  }
  //if(arr[0]==1)
  //  return;
  printf("===%d===%d====%d\n", f, b, cnt);
  
  while(f>=1)
  {
  arr[cnt] = f;
  
  if(f-1 < b+1)
  {
    arr[cnt+2]=1;
    division(n,arr,cnt+1,f,b-1);
  }
  else
  {
    arr[cnt+1]=b;
    division(n,arr,cnt,f-1,b+1);
  }
  f--;
  }
  
  */
}

int main() {

  int n,cnt=0;
  char arr[30]={0,};
  
  scanf("%d", &n);
   
  cnt = division(n,arr,0,&cnt);

  printf("%d", cnt);
  return 0;
}
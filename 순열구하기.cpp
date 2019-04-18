/*


순열구하기

서로 다른 n개의 원소들 중에서 r개만을 뽑아 일렬로 나열하는 것을 순열이라 한다. 

예를 들어, 3개의 원소 a, b, c 중에서 2개만을 뽑아 나열하면 ab, ac, ba, bc, ca, cb 의 6가지 경우가 있다.

n과 r이 주어질 때, n개의 소문자 중에서 r개만을 뽑아 나열하는 모든 경우를 출력하는 프로그램을 작성하시오. 

단, a부터 시작하여 연속으로 n개의 알파벳을 갖고 있다고 하자. 
 

입력

첫 번째 줄에 n과 r이 주어진다. ( 1 ≤ n ≤ 10, 0 ≤ r ≤ min(n, 7) )  

출력

각 줄에 n개의 소문자 중에서 r개만을 뽑아 나열하는 경우를 사전순으로 나열한 결과를 출력한다.


*/


#include <stdio.h>
#include <string.h>

void perm(int n,int r,char alpha[],char result[],int cnt)
{
  int i=0;
  
  if(r==0)
  {
    printf("%s", result);
    printf("\n");
    return;
  }

  for(i=0;i<n;i++)
  {
   // alpha[i-1] = 1;
    if(alpha[i] == 0)
      continue;
      
    result[cnt] =i+97; 
    
    alpha[i]=0;
    perm(n,r-1,alpha,result,cnt+1);
    alpha[i]=1;
  }
  
  
  
}

int main() {

  int n,r;
  char alpha[28] = {0,};
  char result[10]={0,};
  
  scanf("%d %d", &n, &r);
  
  for(int i=0;i<n;i++)
  {
    alpha[i] = 1;
  }
  
  perm(n,r,alpha,result,0);
  
  return 0;
}
/*

inequal

두 종류의 부등호 기호 ‘<’와 ‘>’가 k 개 나열된 순서열 A가 있다. 

우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다. 

예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자.

A ⇒ < < < > < < > < >

부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 아래는 부등호 순서열 A를 만족시키는 한 예이다.

3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다. 

그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 

예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다.

5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

여러분은 제시된 k 개의 부등호 순서를 만족하는 (k+1) 자리의 정수 중에서 최대값과 최소값을 찾아야 한다. 

앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } 중에서 선택해야 하며 선택된 숫자는 모두 달라야 한다. 

프로그램의 실행시간은 0.5초를 넘을 수 없다.


입력

첫 줄에 부등호 문자의 개수를 나타내는 정수 가 주어진다. 그 다음 줄에는 k 개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k 의 범위는 2 <= k <= 9이다.


출력

여러분은 제시된 부등호 관계를 만족하는 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력해야 한다. 

단 아래 예(1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 

모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다.

*/

#include <stdio.h>

//0~9 까지 10자리 중복x, 최대와 최소
void inequal(int k,char arr[],int numArr[],int idx,int min[],int max[]) 
{
  int i,j;
  int tmp[10]={0,};
  
  
  
  for(i=0;i<idx; i++)
    tmp[numArr[i]] = 1;
  
  if(idx>1)
  {
    if(arr[idx-2] == 60)
    {
      if(numArr[idx-2] > numArr[idx-1])
        return;
    }
    else if(arr[idx-2] == 62)
    {
      if(numArr[idx-2] < numArr[idx-1])
        return;
    }
  }
  
  if(idx==k+1) // 대소비교 이게 어떻게 되지
  {
    
    for(i=0;i<idx;i++)
    {
      if(numArr[i] > min[i])
        break;
    }
    if(i == idx)
    {
      for(i=0;i<idx;i++)
        min[i] = numArr[i];
    }
  
    for(i=0;i<idx;i++)
    {
      if(numArr[i] == max[i])
        continue;
      if(numArr[i] > max[i])
      {
        for(j=0;j<idx;j++)
          max[j] = numArr[j];
        break;
      }
    }
   // for(i=0;i<idx;i++)
    //  printf("%d", numArr[i]);
    //printf("\n");
    return;
  }
  
  for(i=0;i<10;i++)
  {
    if(tmp[i] == 1)
      continue;
    
    numArr[idx] = i;
    
    inequal(k,arr,numArr,idx+1,min,max);
  }
  
}

int main() {

  int k;
  char arr[10];
  int numArr[10];
  int min[10]={9,9,9,9,9,9,9,9,9,9};
  int max[10]={0,};
  scanf("%d", &k); 
  getchar();
  for(int i=0;i<k;i++)
  {
    scanf("%c", &arr[i]);
    getchar();
  }
    
  inequal(k,arr,numArr,0,min,max);
  
  for(int i=0;i<k+1;i++)
    printf("%d", max[i]);
  printf("\n");
  for(int i=0;i<k+1;i++)
    printf("%d", min[i]);

  return 0;
}
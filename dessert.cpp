/*


dessert

농부 존은 소들의 저녁식사 줄 세우는 새로운 방법을 개발 했다.

N(1~15)마리의 소들을 순서대로 세 워놓은 후, 각 소들 사이에 +, - , . 셋 중 1가지가 써져있는 냅킨을 배치해서 최종 결과가 0 이 되게 해야 하는 것이다. 

점(.)이 써져있는 냅킨을 통해 더 큰 수를 만들 수 있게 된다. 아래와 같은 경우를 보자. 

(ps .이 써져있는 냅킨은 '공백'이라고 생각하면 된다.) 1-2.3-4.5+6.7 이와 같은 배치는 1-23-45+67 을 나타낸다. 

결과는 0 이다. 10.11은 1011 로 해석된다.


입력

첫 째 줄에는 소들의 수 N(1 ≤ N ≤ 15)이 입력된다.


출력

처음 20줄에 대해 가능한 20가지 답을 출력하는데, 사전 순으로 앞선 것을 출력한다. 

순서는 +가 가장 앞서고 -와 . 이 순서대로 뒤따른다. 

답이 20개 미만이면 가능한 답을 각 숫자와 문자 사이에 공백을 두고 출력한다. 모두 출력한다.

마지막 줄에는 가능한 답의 총 가지수를 출력한다.

*/

#include <stdio.h>
#include <string.h>

int dessert(int n,int result[],int idx,int *cnt)
{
  int sum=0,i,j;
  int tmp;
  int temp[40]={0,};//. result값을 살려놔야 하기 때문에 temp 생성
  int tmpi=0;
  
  if(idx >= n*2 -3)
  {
    for(i=0;i<n*2-1;i++)
      temp[i] = result[i];
    
    for(i=1;i<n*2-1;i+=2)
    {
      if(temp[i] == 300)
      {
        if(temp[i-1]==0)
        {//10 일때는 어떻게 붙여야할까
          if(temp[i+1] >= 10)
            temp[i] = temp[i-2]*100 + temp[i+1];
          else
            temp[i] = temp[i-2]*10 + temp[i+1];
          temp[i-1] = 0;
          temp[i+1] = 0;
          temp[i-2] = 0;
        }
        else
        {
          if(temp[i+1] >= 10)
            temp[i] = temp[i-1]*100 + temp[i+1];
          else
            temp[i] = temp[i-1]*10 + temp[i+1];
          temp[i-1] = 0;
          temp[i+1] = 0;
        }
      }
    }
  
    for(i=0;i<n*2-1;i++)
      if(temp[i] != 0 && temp[i] != 100 && temp[i] != 200)
      {  
        sum = temp[i];
        break;
      }
      
    for(;i<n*2-1;i++)
    {
      if(result[i] == 0)
        continue;
        
      if(temp[i] == 100)
        tmp = 100;
      else if(temp[i] == 200)
        tmp = 200;
      else
      {
        if(tmp == 100)
          sum += temp[i];
        else if(tmp == 200)
          sum -= temp[i];
      }
    }

    if(sum==0)
    {
      if(*cnt<=19)
      {
        for(i=0;i<n*2-1;i++)
        {
          if(result[i] == 100)
          {
            printf("+ ");
            continue;
          }
          else if(result[i] == 200)
          {
            printf("- ");
            continue;
          }
          else if(result[i] == 300)
          {
            printf(". ");
            continue;
          }
          else
            printf("%d ", result[i]);
        }
        printf("\n");
      }
      *cnt +=1;
    }
    return *cnt;
  }
 
 // for(i=0;i<n*2-1;i++)
  //  printf("%d ", result[i]);
  //printf("\n");
  
  /*if(idx >= n*2 -3)
  {
    for(int i=1;i<n*2-1;i+=2)
    {
     // printf("%d  aaa ", result[i]);
      if(result[i] == '.')
      {
        if(dot==0)
        {
        tmp = result[i-1]*10 + result[i+1];
        _result[tmpi++] = tmp;
        dot=1;
        }
        else
        {
          tmp = tmp*10 + result[i+1];
          _result[tmpi-1] = tmp;
          dot=1;
        }
      }
      else
      {
        if(_result[tmpi-1]>=10)
        {
          _result[tmpi++] = result[i];
          _result[tmpi++] = result[i+1];
          dot=0;
        }
        else
        {
          _result[tmpi++] = result[i-1];
          _result[tmpi++] = result[i];
          _result[tmpi++] = result[i+1];
          dot=0;
        }
      }
    }
    
    for(i=0;i<tmpi;i++)
      printf("%d ", _result[tmpi]);
    printf("\n");
    
    return;
  }*/
  
  result[idx+2] = 100;

  //for(i=0;i<n*2-1;i++)
  //  printf("%d ", result[i]);
  //printf("\n");


  dessert(n,result,idx+2,cnt);
  result[idx+2] = 200;
  dessert(n,result,idx+2,cnt);
  result[idx+2] = 300;
  dessert(n,result,idx+2,cnt);
  
  
  
}

int main() {

  int N,tmp=1;
  int cnt=0;
  //char op[20]={0,};
  int result[40];
  scanf("%d", &N);
  
  for(int i=0;i<N*2;i+=2)
    result[i] = tmp++;
  
  //for(int i=0;i<N*2;i++)
    //printf("%d ", result[i]);
  
  cnt = dessert(N,result,-1,&cnt);
  
  printf("%d", cnt);

  return 0;
}
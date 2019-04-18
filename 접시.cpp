/*

접시

접시가 a, b, c, d 가 있고, 알파벳 순으로 한쪽이 막혀 있는 세척기에 들어간다고 할 때, 

b a c d 순으로 꺼내기 위해서는 push, push, pop, pop, push, pop, push, pop을 하면 된다. 

세척기에서 꺼내는 순서가 주어질 때 그 동작을 출력하는 프로그램을 작성하시오. 

만약 주어진 순서대로 접시를 꺼낼 수 없다면 “impossible”을 출력한다.


입력

첫째 줄에 소문자 알파벳이 주어진다. 중복된 소문자 알파벳은 입력되지 않는다. 알파벳 소문자는 26개이다.  


출력

접시를 꺼내는 것이 가능한 경우 push, pop의 순서를 출력한다. 이것이 불가능하다면 impossible을 출력한다. 

*/

#include <stdio.h>
#include <string.h>

typedef struct
{
  char data[30];
  int len=0;
  int capacity; // 25개 까지가 full로 차는 것일 것
  
  void create(int num)
  {
    capacity  = num;
  }
  
  void Push(char al)
  {
    if(len >= capacity)
    {
      printf("Overflow\n");
      return;
    }
    
   //printf("push\n");
    data[len] = al;
    len++;
  }
  
  void Pop()
  {
    if(len<=0)
    {
      printf("Underflow\n");
      return;
    }
    
    //printf("pop\n");
    data[len-1] = 0;
    len--;
  }
  
  int Top()
  {
    if(len<=0)
    {
      return -1;
    }
    return data[len-1];
  }
  
  
} S;



int main() {

  S s;
  
 // int i=0;
  int capa=0;
  char arr[30];
  char alpha[30] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  int series[2000]={0,};
  int idx=0;
  char tmp;
  int l;
  
  fgets(arr,30,stdin);
  
  capa = strlen(arr);
  
  s.create(30);
  //printf("%c --\n", arr[capa-1]);
  //e를 찾았으면 그 전까지의 모두를 s에 push한다음 마지막 e 까지 집어넣고
  //pop을 한다. 그러면 e는 찾음. 그다음 알파벳이 스택 top에 있다면 바로 팝.
  //근데 그다음 알파벳이 top에 없고, alpha에도 없으면 impossible.
  //alpha에 있으면 처음 e 한것처럼 똑같이 하면됨.

  for(int i=0;i<capa;i++)
  {
    if( (s.Top() != -1) && (s.Top() != arr[i]) ) // s.Top() != -1 같이넣으면 깎이는 이유 
    {
      tmp = arr[i];
      //printf("---%c---\n", tmp);
      for(l=0;l<26;l++)
      {
        if(alpha[l] == tmp)
          break;
      }
      
      if(l == 26)
      {
        printf("impossible\n");
        return 0;
      }
    
    }
   
    if(s.Top() == arr[i])
    {
      s.Pop();
      series[idx++] = 200;
      continue;
    }
    
    for(int j=0;j<26;j++)
    {
      if(alpha[j] == arr[i])
      {
       // printf("%d %d\n", j, i);
        for(int k=0; k<=j;k++)
        {
          //printf("%c--```\n", alpha[k]);
          if(alpha[k] == -1)
            continue;
          
          s.Push(alpha[k]);
          series[idx++] = 100;
          alpha[k] = -1;
        }
        //printf("%c--\n", s.Top());
        // printf("%c --- \n", s.Top());
        s.Pop();
        series[idx++] = 200;
        //printf("%c --- \n", s.Top());
        break;
      }
    }
  }
 
  
  
  for(int i=0;i<idx;i++)
  {
    if(series[i] == 100)
      printf("push\n");
    else
      printf("pop\n");
  }
  
  return 0;
}
/*

괄호의값

4개의 기호 ‘(’, ‘)’, ‘[’, ‘]’를 이용해서 만들어지는 괄호열 중에서 올바른 괄호열이란 다음과 같이 정의된다.

한 쌍의 괄호로만 이루어진 ‘()’와 ‘[]’는 올바른 괄호열이다. 

만일 X가 올바른 괄호열이면 ‘(X)’이나 ‘[X]’도 모두 올바른 괄호열이 된다. 

X와 Y 모두 올바른 괄호열이라면 이들을 결합한 XY도 올바른 괄호열이 된다. 

예를 들어 ‘(()[[]])’나 ‘(())[][]’ 는 올바른 괄호열이지만 ‘([)]’ 나 ‘(()()[]’ 은 모두 올바른 괄호열이 아니다. 

우리는 어떤 올바른 괄호열 X에 대하여 그 괄호열의 값(괄호값)을 아래와 같이 정의하고 값(X)로 표시한다.

‘()’ 인 괄호열의 값은 2이다.
‘[]’ 인 괄호열의 값은 3이다.
‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.

올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다.

예를 들어 ‘(()[[]])([])’ 의 괄호값을 구해보자. 

‘()[[]]’ 의 괄호값이 2 + 3×3=11 이므로 ‘(()[[ ]])’의 괄호값은 2×11=22 이다. 

그리고 ‘([])’의 값은 2×3=6 이므로 전체 괄호열의 값은 22 + 6 = 28 이다. 

여러분이 풀어야 할 문제는 주어진 괄호열을 읽고 그 괄호값을 앞에서 정의한대로 계산하여 출력하는 것이다.
 

입력

첫째 줄에 괄호열을 나타내는 문자열(스트링)이 주어진다. 단 그 길이는 1 이상, 30 이하이다.  

출력

첫째 줄에 그 괄호열의 값을 나타내는 정수를 출력한다. 만일 입력이 올바르지 못한 괄호열이면 반드시 0을 출력해야 한다.

*/

#include <stdio.h>

typedef struct
{
  int data[1000];
  int len=0;
  int capacity;
  
  void Create(int n)
  {
    capacity = n;
  }
  
  void Push(int n)
  {
    if(len >= capacity)
    {
      printf("Overflow\n");
      return ;
    }
    
    data[len] = n;
    len++;
  }
  
  void Pop()
  {
    if(len<=0)
    {
      printf("Underflow\n");
      return;
    }
    
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


/*
int cal(char arr[],int len,int *idx,S s)
{
  int tmp=0;
 
  if(*idx >= len)
    return 1;
    
  if(arr[*idx] == ']' || arr[*idx] == ')')
  {
    s.Pop();
   // (*idx)++;
    return 1;
  }
    
  if(arr[*idx] == '(')
  {
    s.Push(arr[*idx]);
    (*idx)++;
    tmp = 2 * cal(arr,len,idx,s);
  }
  else if(arr[*idx] == '[')
  {
    s.Push(arr[*idx]);
    (*idx)++;
    tmp = 3 * cal(arr,len,idx,s);
  }
  
  if(s.Top() != -1)
  {
    (*idx)++;
    tmp = tmp + cal(arr,len,idx,s);
  }
  
  return tmp;
  
}*/

int main() {

  char arr[100];
  S s,s2;
  int i=0;
  int sum=0;
  int tmp=1;
  int tmp2=0;
  int tmp3=1;
  int idx=0;
  int cnt=0;
  
  fgets(arr,40,stdin);
  
  s.Create(1000);
  
  for(; arr[idx] != 0 ; idx++){}
 
  for(int i=0; arr[i] != 0;i++)
  {
    if(arr[i] == '(' || arr[i] == '[')
    {
      s.Push(arr[i]);
      continue;
    }
   
    if((s.Top()=='(' && arr[i] == ')') || (s.Top() == '[' && arr[i] == ']'))
      s.Pop();
    else
    {
      printf("0");
      return 0;
    }
  
  }
  
  if(s.Top() != -1)
  {
    printf("0");
    return 0;
  }
  //여기까지 0을 출력하는 경우를 모음
  
  
  
  //이제부터 괄호에 대한 값 계산
  
  //왼괄호가 나오는대로 전부 푸쉬, 그 후 오른괄호가 나왔을 때
  // tmp 에 2 혹은 3을 저장함. 그 후 바로 왼괄호가 나온다면 
  // 이 tmp 값에 그 왼괄호에 대한 값을 더해줘야함 
  // 그 후, 이 더하기가 끝나고 나서 오른괄호가 나왔을 때 
  // tmp 값 에 2 혹은 3을 곱해야 한다. 
  // tmp에 2 혹은 3 저장 후 오른괄호 나온다면 그냥 바로 tmp 에 곱하기 진행하면 됨
  // 개인적으론 이거 재귀로 해야할 것 같음. 안해 못하겠음
  
 // sum = cal(arr,i,&idx,s);
  
  
  //숫자를 스택에 같이 넣어줄 생각을 했었어야함 !!!!! 
  
  tmp=0;
  
  for(i=0; i<idx ; i++)
  {
   // printf("aa %c aa\n", arr[i]);
    tmp = 0;
    
    if(arr[i] == '(' || arr[i] == '[')
    {
      s.Push(arr[i]);
      continue;
    }
    
    if(arr[i] == ')')
    {
      if(s.Top() == '(')
      {
        tmp=2;
        s.Pop();
        
        while(s.Top() != '(' && s.Top() != '[' && s.Top() != -1)
        {
          tmp+= s.Top();
          s.Pop();
        }
        
        s.Push(tmp);
        //printf("%d--\n", s.Top());
      }
      else
      {
        while(s.Top() != '(' && s.Top() != '[' && s.Top() != -1)
        {
          tmp +=s.Top();
          s.Pop();
        //  printf("%d---aaa \n", tmp);
        }
        if(s.Top() == '(')
        {
          tmp*=2;
          s.Pop();
        }
        
        s.Push(tmp);
       // printf("abd %d abd \n", s.Top());
      }
    }
    else if(arr[i] == ']')
    {
      
      if(s.Top() == '[')
      {
        tmp=3;
        s.Pop();
          
        while(s.Top() != '(' && s.Top() != '[' && s.Top() != -1)
        {
          tmp+= s.Top();
          s.Pop();
        }
        
        s.Push(tmp);
      }
      else
      {
        while(s.Top() != '(' && s.Top() != '[' && s.Top() != -1)
        {
          tmp+= s.Top();
          s.Pop();
        }
        
        if(s.Top() == '[')
        {
          tmp*=3;
          s.Pop();
        }
        s.Push(tmp);
        
      }
    }
  }
  if(s.Top() != -1)
  {
    tmp=s.Top();
    s.Pop();
  }
  
  while(s.Top() != -1)
  {
    tmp += s.Top();
    s.Pop();
  }
  
  if(tmp <0)
    printf("%d", -tmp);
  else
    printf("%d", tmp);
  
  return 0; 
  
  
}

/*

히스토그램에서 가장 큰 직사각형 찾기

히스토그램이란, 아래 그림과 같이 직사각형이 배열되어 있는 것을 말한다. 

각 직사각형의 가로 길이는 1로 모두 같고, 세로 길이는 다를 수 있다. 

예를 들어, 높이가 2, 1, 4, 5, 1, 3, 3 인 직사각형으로 이루어진 히스토그램이 있다고 할 때,

최대 직사각형의 너비는 4,5 부분에서 (4*2) = 8 이 되어 8 이 된다.

히스토그램이 주어질 때, 가장 큰 직사각형의 너비를 출력하는 프로그램을 작성하시오.


입력

첫째 줄에 히스토그램을 이루는 직사각형의 개수 N이 주어진다. ( 1 ≤ N ≤ 100,000 ) 둘째 줄에는 각 직사각형의 높이가 주어진다. 높이는 10,000보다 작은 양의 정수이다.  


출력

최대 직사각형의 너비를 출력한다.

*/

#include <stdio.h>

typedef struct
{
  int data[100500];
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
      printf("Over flow다\n");
      return;
    }
    
    data[len] = n;
    len++;
  }
  
  void Pop()
  {
    if(len<=0)
    {
      printf("언더 플로우다\n");
      return;
    }
    
    data[len-1] = 0;
    len--;
  }
  
  int Top()
  {
    if(len<=0)
      return -1;
      
    return data[len-1];
  }
} S;

int fmax(int a,int b)
{
  if(a>=b)
    return a;
  return b;
}

int main() {

  int N;
  int arr[100500];
  S s;
  int max=0;
  int tmplen;
  int tmp;

  scanf("%d", &N);
  
  s.Create(N);
  
  for(int i=0;i<N;i++)
    scanf("%d", &arr[i]);
    
  s.Push(0);
    
  for(int i=1;i<N;i++)
  {
    if(arr[s.Top()] < arr[i])
    {
      s.Push(i);
    }
    else if(arr[s.Top()] >= arr[i])
    {
      //tmplen = 1;
      while(arr[s.Top()] >= arr[i] && s.Top() != -1)
      {
        //printf("%d aaa %d aaa\n", arr[s.Top()], arr[i]);
        
        tmp = s.Top();
        s.Pop();
        //printf("%")
        //printf("%d %d %d --\n", i, tmp, max);
        max = fmax(max,arr[tmp]*( (i - tmp) + (tmp-s.Top()-1) ));
        max = fmax(max,arr[i]*(i-tmp+1));
        //printf("%d %d --- \n", i, tmp);
        //printf("%d %d\n", arr[tmp]*(i-tmp), arr[i]*(i-tmp+1));
        
        // s.Pop();
        
      
      }
      s.Push(i);
    }
    
  }
  
  
  
  tmp = s.Top();
  s.Pop();
  
  if(s.Top() == -1)
    max = fmax(max, arr[tmp]*N);
  else
  {
    while(s.Top() != -1)
    {
      tmp = s.Top(); // 2
      s.Pop();
      if(s.Top() == -1)
        max = fmax(max, arr[tmp] * N);
      else
      {
        max = fmax(max, arr[tmp] * (N - s.Top() -1));
      }
      // s.Pop();
    }
  }
  max = fmax(max, arr[tmp] * N);
  
  /*
  tmp = s.Top();
  tmplen= tmp;
  s.Pop();
  
  if(s.Top() != -1)
      max = fmax(max,arr[tmp]);
  else
      max = fmax(max,arr[tmp]*N);
      
  while(s.Top() != -1)
  {
    tmp = s.Top();
   
    //printf("aaa %d\n", arr[tmp]);
    //printf("%d bbb \n", max);
   
    s.Pop();
    //printf("%d %d\n", tmp, tmplen);
   
    if(s.Top() != -1)
    {
      max = fmax(max,arr[tmp]*(tmplen-tmp+1));
      //max = fmax(max,arr[tmplen]*(tmplen-tmp));
    }
    else
      max = fmax(max,arr[tmp]*N);
      
    tmplen = tmp;
  }*/
  
  printf("%d", max);
  
  return 0;
}
/*

������׷����� ���� ū ���簢�� ã��

������׷��̶�, �Ʒ� �׸��� ���� ���簢���� �迭�Ǿ� �ִ� ���� ���Ѵ�. 

�� ���簢���� ���� ���̴� 1�� ��� ����, ���� ���̴� �ٸ� �� �ִ�. 

���� ���, ���̰� 2, 1, 4, 5, 1, 3, 3 �� ���簢������ �̷���� ������׷��� �ִٰ� �� ��,

�ִ� ���簢���� �ʺ�� 4,5 �κп��� (4*2) = 8 �� �Ǿ� 8 �� �ȴ�.

������׷��� �־��� ��, ���� ū ���簢���� �ʺ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ� ������׷��� �̷�� ���簢���� ���� N�� �־�����. ( 1 �� N �� 100,000 ) ��° �ٿ��� �� ���簢���� ���̰� �־�����. ���̴� 10,000���� ���� ���� �����̴�.  


���

�ִ� ���簢���� �ʺ� ����Ѵ�.

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
      printf("Over flow��\n");
      return;
    }
    
    data[len] = n;
    len++;
  }
  
  void Pop()
  {
    if(len<=0)
    {
      printf("��� �÷ο��\n");
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
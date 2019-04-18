/*

��ȣ�ǰ�

4���� ��ȣ ��(��, ��)��, ��[��, ��]���� �̿��ؼ� ��������� ��ȣ�� �߿��� �ùٸ� ��ȣ���̶� ������ ���� ���ǵȴ�.

�� ���� ��ȣ�θ� �̷���� ��()���� ��[]���� �ùٸ� ��ȣ���̴�. 

���� X�� �ùٸ� ��ȣ���̸� ��(X)���̳� ��[X]���� ��� �ùٸ� ��ȣ���� �ȴ�. 

X�� Y ��� �ùٸ� ��ȣ���̶�� �̵��� ������ XY�� �ùٸ� ��ȣ���� �ȴ�. 

���� ��� ��(()[[]])���� ��(())[][]�� �� �ùٸ� ��ȣ�������� ��([)]�� �� ��(()()[]�� �� ��� �ùٸ� ��ȣ���� �ƴϴ�. 

�츮�� � �ùٸ� ��ȣ�� X�� ���Ͽ� �� ��ȣ���� ��(��ȣ��)�� �Ʒ��� ���� �����ϰ� ��(X)�� ǥ���Ѵ�.

��()�� �� ��ȣ���� ���� 2�̴�.
��[]�� �� ��ȣ���� ���� 3�̴�.
��(X)�� �� ��ȣ���� 2����(X) ���� ���ȴ�.
��[X]�� �� ��ȣ���� 3����(X) ���� ���ȴ�.

�ùٸ� ��ȣ�� X�� Y�� ���յ� XY�� ��ȣ���� ��(XY)= ��(X)+��(Y) �� ���ȴ�.

���� ��� ��(()[[]])([])�� �� ��ȣ���� ���غ���. 

��()[[]]�� �� ��ȣ���� 2 + 3��3=11 �̹Ƿ� ��(()[[ ]])���� ��ȣ���� 2��11=22 �̴�. 

�׸��� ��([])���� ���� 2��3=6 �̹Ƿ� ��ü ��ȣ���� ���� 22 + 6 = 28 �̴�. 

�������� Ǯ��� �� ������ �־��� ��ȣ���� �а� �� ��ȣ���� �տ��� �����Ѵ�� ����Ͽ� ����ϴ� ���̴�.
 

�Է�

ù° �ٿ� ��ȣ���� ��Ÿ���� ���ڿ�(��Ʈ��)�� �־�����. �� �� ���̴� 1 �̻�, 30 �����̴�.  

���

ù° �ٿ� �� ��ȣ���� ���� ��Ÿ���� ������ ����Ѵ�. ���� �Է��� �ùٸ��� ���� ��ȣ���̸� �ݵ�� 0�� ����ؾ� �Ѵ�.

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
  //������� 0�� ����ϴ� ��츦 ����
  
  
  
  //�������� ��ȣ�� ���� �� ���
  
  //�ް�ȣ�� �����´�� ���� Ǫ��, �� �� ������ȣ�� ������ ��
  // tmp �� 2 Ȥ�� 3�� ������. �� �� �ٷ� �ް�ȣ�� ���´ٸ� 
  // �� tmp ���� �� �ް�ȣ�� ���� ���� ��������� 
  // �� ��, �� ���ϱⰡ ������ ���� ������ȣ�� ������ �� 
  // tmp �� �� 2 Ȥ�� 3�� ���ؾ� �Ѵ�. 
  // tmp�� 2 Ȥ�� 3 ���� �� ������ȣ ���´ٸ� �׳� �ٷ� tmp �� ���ϱ� �����ϸ� ��
  // ���������� �̰� ��ͷ� �ؾ��� �� ����. ���� ���ϰ���
  
 // sum = cal(arr,i,&idx,s);
  
  
  //���ڸ� ���ÿ� ���� �־��� ������ �߾������ !!!!! 
  
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

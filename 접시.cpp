/*

����

���ð� a, b, c, d �� �ְ�, ���ĺ� ������ ������ ���� �ִ� ��ô�⿡ ���ٰ� �� ��, 

b a c d ������ ������ ���ؼ��� push, push, pop, pop, push, pop, push, pop�� �ϸ� �ȴ�. 

��ô�⿡�� ������ ������ �־��� �� �� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

���� �־��� ������� ���ø� ���� �� ���ٸ� ��impossible���� ����Ѵ�.


�Է�

ù° �ٿ� �ҹ��� ���ĺ��� �־�����. �ߺ��� �ҹ��� ���ĺ��� �Էµ��� �ʴ´�. ���ĺ� �ҹ��ڴ� 26���̴�.  


���

���ø� ������ ���� ������ ��� push, pop�� ������ ����Ѵ�. �̰��� �Ұ����ϴٸ� impossible�� ����Ѵ�. 

*/

#include <stdio.h>
#include <string.h>

typedef struct
{
  char data[30];
  int len=0;
  int capacity; // 25�� ������ full�� ���� ���� ��
  
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
  //e�� ã������ �� �������� ��θ� s�� push�Ѵ��� ������ e ���� ����ְ�
  //pop�� �Ѵ�. �׷��� e�� ã��. �״��� ���ĺ��� ���� top�� �ִٸ� �ٷ� ��.
  //�ٵ� �״��� ���ĺ��� top�� ����, alpha���� ������ impossible.
  //alpha�� ������ ó�� e �Ѱ�ó�� �Ȱ��� �ϸ��.

  for(int i=0;i<capa;i++)
  {
    if( (s.Top() != -1) && (s.Top() != arr[i]) ) // s.Top() != -1 ���̳����� ���̴� ���� 
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
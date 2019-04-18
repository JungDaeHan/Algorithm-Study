/*

¿øÇüÅ¥ 

*/

#include <stdio.h>

typedef struct
{
  int f,r;
  int capacity;
  int arr[101];
  int len=0;
  
  void Create(int n)
  {
    capacity = n;
    f=0;
    r=0;
  }
  
  void Push(int X)
  {
    if(len >= capacity || r >= capacity)
    {
      printf("Overflow\n");
      return;
    }
    
    len++;
    arr[r] = X;
    r = (r+1)%capacity;
  }
  
  void Pop()
  {
    if(len <= 0)
    {
      printf("Underflow\n");
      return;
    }
    
    len--;
    arr[f] = 0;
    f = (f+1)%capacity;
  }
  
  void Front()
  {
    if(len <=0)
    {
      printf("NULL\n");
      return;
    }
    
    printf("%d\n", arr[f]);
  }
} Q;

int main() {

  int n,m;
  Q queue;
  int sel;
  
  scanf("%d %d", &n, &m);
  
  queue.Create(n);
  
  for(int i=0;i<m;i++)
  {
    scanf("%d", &sel);
    
    if(sel == 1)
    {
      scanf("%d", &sel);
      queue.Push(sel);
    }
    else if(sel == 2)
      queue.Pop();
    else if(sel == 3)
      queue.Front();
  }

  return 0;
}
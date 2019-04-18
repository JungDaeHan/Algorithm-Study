/*

������ ( by Queue )

ö���� �������� ���ڱ� �������� �����ϱ� �����Ͽ���. �� �������� ������ �ſ� ���ؼ�, �̿��� ���������� �����Ǵ� ���� ���� �� ����.

ö���� ������ 1������ N������ ��ȣ�� �Ű��� �ִ�. 

ö���� ������ ������ �ϳ� �����ѵ�, i�� �������� ����ϸ� i * 2 �� ������ �� �� �ְ�, ���� i / 3(i�� 3���� ���� ��) ��° �������� �� �� �ִ�. 

�������� ����� ���Ͽ� �Ŵ� ������ �˷��� �ִ�. ���� i�� ������ �������� ���� �Ǹ�, i * 2 �� ������ i / 3(i�� 3���� ���� ��) �� ���� ���� �������� ���� �ȴ�.


K�� ������ ���� ó������ �������� ���� �������� ��, �������� ���� �ʴ� ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ� ��ü ������ ���� N��, ó������ �������� ���� ������ ���� ��ȣ K�� �־�����. ( 1 �� N, K �� 100,000 )  


���

�������� ���� �ʴ� ������ ������ ����Ѵ�.

*/

#include <stdio.h>

typedef struct
{
  int f,r;
  int capacity;
  int len=0;
  int arr[200000];
  
  void Create(int n)
  {
    f=0;
    r=0;
    capacity=n;
  }
  
  void Push(int x)
  {
    if(len >=capacity)
    {
      printf("Overflow\n");
      return ;
    }
    
    arr[r] = x;
    r = (r+1)%capacity;
    len++;
  }
  
  void Pop()
  {
    if(len <= 0)
    {
      printf("Underflow\n");
      return ;
    }
    
    arr[f] = 0;
    f = (f+1)%capacity;
    len--;
  }
  
  int Front()
  {
    if(len <=0)
    {
      return -1;
    }
    
    return arr[f];
  }
  
  int Size()
  {
    return len;
  }
  
} Q;

int main() {

  int N,K;
  int arr[100010]={0,}; // 0 �� �� �������� ���� �� �� 0�� ���� ���� 
  Q queue;
  int tmp;
  int sum=0;

  scanf("%d %d ", &N, &K);
  
  queue.Create(N);
  
  queue.Push(K);
  
  //printf("%d\n", queue.Size());
  
  while(queue.Size() != 0)
  {
    tmp = queue.Front();
    queue.Pop();
    //printf("%d\n", tmp);
    
    if(arr[tmp] == 1 || tmp == 0)
      continue;
    
    arr[tmp] = 1;
    
    if(tmp*2 > N)
    { 
      //arr[tmp/3] = 1;
      queue.Push(tmp/3);
    }
    else
    {
      //arr[tmp*2] = 1;
      //arr[tmp/3] = 1;
      queue.Push(tmp*2);
      queue.Push(tmp/3);
    }
    
    /*
    if(tmp*2 < N && tmp/3 != 0)
    {
      queue.Push(tmp*2);
      queue.Push(tmp/3);
    }
    else if(tmp/3 != 0)
    {
      queue.Push(tmp/3);
    }
    else if(tmp*2 <N)
    {
      queue.Push(tmp*2);
    }*/
  
    
  }
  
  for(tmp=1;tmp<=N;tmp++)
  {
    if(arr[tmp] == 0)
      sum++;
  }
  
  printf("%d", sum);
  
  return 0;
}

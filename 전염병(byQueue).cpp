/*

전염병 ( by Queue )

철수네 마을에는 갑자기 전염병이 유행하기 시작하였다. 이 전염병은 전염이 매우 강해서, 이웃한 마을끼리는 전염되는 것을 피할 수 없다.

철수네 마을은 1번부터 N번까지 번호가 매겨져 있다. 

철수네 마을의 구조는 꽤나 복잡한데, i번 마을에서 출발하면 i * 2 번 마을에 갈 수 있고, 또한 i / 3(i를 3으로 나눈 몫) 번째 마을에도 갈 수 있다. 

전염병은 사람에 의하여 옮는 것으로 알려져 있다. 따라서 i번 마을에 전염병이 돌게 되면, i * 2 번 마을과 i / 3(i를 3으로 나눈 몫) 번 마을 역시 전염병이 돌게 된다.


K번 마을이 가장 처음으로 전염병이 돌기 시작했을 때, 전염병이 돌지 않는 마을의 개수를 구하는 프로그램을 작성하시오.


입력

첫째 줄에 전체 마을의 개수 N과, 처음으로 전염병이 돌기 시작한 마을 번호 K가 주어진다. ( 1 ≤ N, K ≤ 100,000 )  


출력

전염병이 돌지 않는 마을의 개수를 출력한다.

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
  int arr[100010]={0,}; // 0 인 게 전염병이 없는 거 즉 0의 개수 세야 
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

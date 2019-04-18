/*

PRIME PATH

4자리 소수가 2개 주어질때, 시작 수에서 도착 수까지 아래에 주어지는 규칙에 맞게 변경할때 최소 변경 횟수를 구하는 프로그램을 작성해보자. 

규칙은 어떤 수에서 다음 수로 넘어갈때 어떤 수의 한 자리수 만 변경해서 이동한다. 각 단계별 수는 소수이다. 만약 1033에서 8179로 가야한다면, 다음과 같은 순서로 이동하게되어 최소 변경 횟수는 6이된다.

1733, 3733, 3739, 3779, 8779, 8179

입력은 항상 네 자리 소수만(1000 이상의 소수) 주어진다고 가정하자. 

주어진 두 소수는 ‘네 자리 수’라 하였기 때문에 0013 과 같은 1000 미만의 소수는 입력되지않는다.


입력

첫 줄에 소수 쌍의 수 T(1 ≤ T ≤ 100)가 주어진다. 다음 T줄에 걸쳐 각 줄에 시작 수, 끝 수에 해당하는 네 자리 소수가 주어진다.


출력

각 소수 쌍에 대해 두 소수 사이의 최소 변경 횟수를 출력한다. 불가능한 경우 Impossible을 출력한다.

*/

#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

bool prime[10000] = {false,};
queue<int> Queue;
int BFScnt[10000] = {0,};

int BFS(int e)
{
  int tmp;
  
  while(Queue.empty() != 1)
  {
    int x = Queue.front();
    Queue.pop();
    if(x == e)
    {
      while(Queue.empty()!= 1)
        Queue.pop();
    
      return BFScnt[x];
    }
    
    tmp = x%1000;
    
    for(int i=1;i<=9;i++)
    {
      int next = tmp+i*1000;
      
      if(next == x)
        continue;
        
      if(prime[next] == true && BFScnt[next] == 0)
      {
        BFScnt[next] = BFScnt[x] + 1;
        Queue.push(next);
      }
    }
    
    tmp = x - (x/100%10*100);
    
    for(int i=0;i<=9;i++)
    {
      int next = tmp + i*100;
      if(next== x)
        continue;
        
      if(prime[next] == true && BFScnt[next] == 0)
      {
        BFScnt[next] = BFScnt[x] + 1;
        Queue.push(next);
      }
    }
    
    tmp = x - (x/10%10*10);
    
    for(int i=0;i<=9;i++)
    {
      int next = tmp + i*10;
      
      if(next == x)
        continue;
        
      if(prime[next] == true && BFScnt[next] == 0)
      {
        BFScnt[next] = BFScnt[x] + 1;
        Queue.push(next);
      }
    }
    
    tmp = x - (x%10);
    
    for(int i=0;i<=9;i++)
    {
      int next = tmp + i;
      
      if(next == x)
        continue;
        
      if(prime[next] == true && BFScnt[next] == 0)
      {
        BFScnt[next] = BFScnt[x] + 1;
        Queue.push(next);
      }
    }
  }
  
  
  
  return -1;
}

int main() {

  int T;
  int s,e;
  
  scanf("%d", &T);
  
  for(int i=0;i<10000;i++)
    prime[i] = true;
  
  for(int i=2;i<100;i++)
  {
    if(prime[i] == false)
      continue;
      
    for(int j=i*2; j<10000 ; j+=i)
    {
      prime[j] = false;
    }
  }
  
  //true 면 소수
 
  
  for(int i=0;i<T;i++)
  {
    scanf("%d %d", &s, &e);
    
    Queue.push(s);
  
    int cnt = BFS(e);
    
    if(cnt == -1)
      printf("Impossible\n");
    else
      printf("%d\n", cnt);
      
      
    for(int i=1000;i<=9999;i++)
      BFScnt[i] = 0;
  }

  return 0;
}
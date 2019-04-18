/*

PRIME PATH

4�ڸ� �Ҽ��� 2�� �־�����, ���� ������ ���� ������ �Ʒ��� �־����� ��Ģ�� �°� �����Ҷ� �ּ� ���� Ƚ���� ���ϴ� ���α׷��� �ۼ��غ���. 

��Ģ�� � ������ ���� ���� �Ѿ�� � ���� �� �ڸ��� �� �����ؼ� �̵��Ѵ�. �� �ܰ躰 ���� �Ҽ��̴�. ���� 1033���� 8179�� �����Ѵٸ�, ������ ���� ������ �̵��ϰԵǾ� �ּ� ���� Ƚ���� 6�̵ȴ�.

1733, 3733, 3739, 3779, 8779, 8179

�Է��� �׻� �� �ڸ� �Ҽ���(1000 �̻��� �Ҽ�) �־����ٰ� ��������. 

�־��� �� �Ҽ��� ���� �ڸ� ������ �Ͽ��� ������ 0013 �� ���� 1000 �̸��� �Ҽ��� �Էµ����ʴ´�.


�Է�

ù �ٿ� �Ҽ� ���� �� T(1 �� T �� 100)�� �־�����. ���� T�ٿ� ���� �� �ٿ� ���� ��, �� ���� �ش��ϴ� �� �ڸ� �Ҽ��� �־�����.


���

�� �Ҽ� �ֿ� ���� �� �Ҽ� ������ �ּ� ���� Ƚ���� ����Ѵ�. �Ұ����� ��� Impossible�� ����Ѵ�.

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
  
  //true �� �Ҽ�
 
  
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
/*

전염병(by BFS)

철수네 마을에는 갑자기 전염병이 유행하기 시작하였다. 이 전염병은 전염이 매우 강해서, 이웃한 마을끼리는 전염되는 것을 피할 수 없다.

철수네 마을은 1번부터 N번까지 번호가 매겨져 있다. 

철수네 마을의 구조는 꽤나 복잡한데, i번 마을에서 출발하면 i * 2 번 마을에 갈 수 있고, 또한 i / 3(i를 3으로 나눈 몫) 번째 마을에도 갈 수 있다. 

전염병은 사람에 의하여 옮는 것으로 알려져 있다. 

따라서 i번 마을에 전염병이 돌게 되면, i * 2 번 마을과 i / 3(i를 3으로 나눈 몫) 번 마을 역시 전염병이 돌게 된다.

K번 마을이 가장 처음으로 전염병이 돌기 시작했을 때, 전염병이 돌지 않는 마을의 개수를 구하는 프로그램을 작성하시오.


입력

첫째 줄에 전체 마을의 개수 N과, 처음으로 전염병이 돌기 시작한 마을 번호 K가 주어진다. ( 1 ≤ N, K ≤ 100,000 )  


출력

전염병이 돌지 않는 마을의 개수를 출력한다.

*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int infect[100010] = {0,}; // 1이 전염당한거임 ㅇㅇㅇ
queue<int> Queue;

void BFS(int N, int K)
{
  //K부터 시작해서 2 곱하고 3 나눠서 큐에 넣어버림
  //근데 3 나눠서 0 나오면 예외처리.
  // 2 곱해서 N 넘으면 예외처리. 그러면 됨 
  // 그리고 넣을 시점에 infect에 1넣고 인덱스를 큐에 넣음
  
  int tmp; 
  
  infect[K] = 1;
  Queue.push(K);
  
  while(1)
  {
    if(Queue.empty() == 1)
      break;
      
    tmp = Queue.front();
    Queue.pop();
    
    if(tmp*2 <= N && infect[tmp*2] != 1)
    {
      infect[tmp*2] = 1;
      Queue.push(tmp*2);
    }
    
    if(tmp/3 != 0 && infect[tmp/3] != 1)
    {
      infect[tmp/3] = 1;
      Queue.push(tmp/3);
    }
  }
}

int main() {

  int N,K;
  int sum =0;
  
  scanf("%d %d", &N, &K);
  
  BFS(N,K);
  
  for(int i=1;i<=N;i++)
  {
    if(infect[i] == 0)
      sum+= 1;
  }
  
  printf("%d", sum);
  return 0;
}
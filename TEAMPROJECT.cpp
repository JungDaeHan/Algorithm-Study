/*

TEAM PROJECT

이번 가을학기에 '문제 해결' 강의를 수강하는 학생들은 팀 프로젝트를 수행해야 한다. 

프로젝트 팀원 수에는 제한이 없다. 심지어 모든 학생들이 같은 팀의 팀원으로 구성된 한 팀도 허락된다. 

프로젝트 팀을 구성하기 위해, 모든 학생들은 프로젝트를 같이하고 싶은 학생 딱 한 명을 선택해야 한다. 

혼자 하고 싶어하는 학생은 자기 자신을 선택하는 것도 가능하다.

과목을 수강한 학생 수가 1명이고, 그 한 명이 자기 자신을 선택하는 경우. 혹은, 학생 수가 N명이고, 1번 학생이 2번 학생을 선택하고, 2번 학생이 3번 학생을 선택하고,..., 

N-1번 학생이 N번 학생을 선택하고, N번 학생이 1번 학생을 선택하는 경우에만 한 팀이 될 수 있다.

예를 들어, 수업에 7명의 학생이 있다고 하자. 학생들을 1번부터 7번으로 표현할 때, 선택의 결과는 다음과 같다.

1	2	3	4	5	6	7
3	1	3	7	3	4	6

위의 결과를 통해, (3)과 (4, 7, 6)이 팀을 이룰 수 있다. 1, 2, 5는 어느 팀에도 속하지 않는다.

주어진 선택의 결과를 보고 어느 팀에도 속하지 않는 학생들의 수를 계산하는 프로그램을 작성하라.


입력

첫 줄에는 학생의 수가 정수 n (2 ≤ n ≤ 100,000)으로 주어진다. 둘째 줄에는 선택된 학생들의 번호가 주어진다. (모든 학생들은 1부터 n까지 번호가 부여된다.)


출력

첫 줄에 팀에 속하지 못한 학생들의 수를 나타내면 된다.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[100010];

int cycle[100010] = {0,};
//이 사이클에서 0 인 애들 뽑으면 됨
int visited[100010] = {0,};

void DFS(int n,int fix)
{
  if(n == fix)
  {
    cycle[fix] = 1;
    visited[fix] = 0;
    int tmp = Graph[fix][0];
    
    while(tmp != fix)
    {
      cycle[tmp] = 1;
      visited[tmp] = 0;
      tmp = Graph[tmp][0];
    }
    
    return;
    
  }
  
  if(visited[n] == 0)
  {
    visited[n] = 1;
    DFS(Graph[n][0],fix);
  }
  
  visited[n] = 0;
  
}

int main() {

  int n;
  int sel;
  
  scanf("%d", &n);
  
  for(int i=1;i<=n;i++)
  {
    scanf("%d", &sel);
    
    Graph[i].push_back(sel);
  }
  
  for(int i=1;i<=n;i++)
  {
    visited[i] = 1;
    DFS(Graph[i][0],i);
  
  }
  
  int sum = 0;
  
  for(int i=1;i<=n;i++)
  {
    if(cycle[i] == 0)
      sum++;
  }
  
  printf("%d", sum);
  
  
  

  return 0;
}
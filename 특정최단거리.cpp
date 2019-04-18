/*

Ư�� �ִܰŸ�(by ���ͽ�Ʈ��)

������ �׷����� �־��� ��, ���� 1������ ���� N������ ���� �ִܰŸ��� ���Ϸ� �ϴµ�, �� �������� �� ���� ������ �ݵ�� ���ľ� �Ѵ�. 

�� �� �湮�ߴ� ������ �� �ٽ� �湮�ϴ� �͵� ����ϰ�, ������ ���������� ������ �湮�ϴ� ���� ����Ѵٰ� �� ��, 

1������ N������ ���� ��Ư����" �ִܰŸ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. ( 1 �� N �� 1,000, 1 �� M �� 100,000 ) 

��° �ٺ��� ������ ������ �־�����. �� ���� �� ���� ���� a, b, c�� �̷���� ������, �̴� ���� a�� ���� b�� ����ġ c�� �������� ����Ǿ� �ִٴ� �ǹ��̴�. 

������ �ٿ��� �ݵ�� ���ľ� �ϴ� �� ���� A, B�� �־�����. ( 1 �� a, b, A, B �� 1,000, 1 �� c �� 50,000 )
 

���

1�� �������� N�� �������� ���� ��Ư����" �ִܰŸ��� ����Ѵ�. 

��, ��Ư����" �ִܰŸ���, �־��� ���� A�� B�� �ݵ�� �湮�� ���� �ִܰŸ��� �ǹ��Ѵ�.

*/

#include<cstdio>
#include<vector>

using namespace std;

vector<int> Graph[1010];
vector<int> Cost[1010];

int main() {

  int N,M;
  
  scanf("%d %d", &N,&M);
  
  for(int i=0; i<M; i++)
  {
    int a,b,c;
    
    scanf("%d %d %d", &a,&b,&c);
    
    Graph[a].push_back(b);
    Graph[b].push_back(a);
    
    Cost[a].push_back(c);
    Cost[b].push_back(c);
  }
  
  int A,B; // �� ������ �ݵ�� �����鼭 1~N�� �ִܰŸ�
  
  scanf("%d %d", &A, &B);
  
  int Table[1010]; // 1���� A��
  int Table2[1010]; // A���� B��
  int Table3[1010]; // B���� N����
  
  int Check[1010] = {0,}; // 1�̸� ������ �ִܰŸ�
  int Check2[1010] = {0,};
  int Check3[1010] = {0,};
  
  for(int i=0;i<=N;i++)
  {
    Table[i] = 987987987;
    Table2[i] = 987987987;
    Table3[i] = 987987987;
  }
    
  Table[1] = 0;
  Table2[A] = 0;
  Table3[B] = 0;
  
  for(int i=0;i<=N;i++)
  {
    int minValue= 987987987;
    int minIndex = -1;
    
    for(int i=0;i<=N;i++)
    {
      if(!Check[i] && minValue > Table[i])
      {
        minValue = Table[i];
        minIndex = i;
      }
    }
    
    Check[minIndex] = 1;
    
    for(int i=0;i<Graph[minIndex].size() ; i++)
    {
      int Node = Graph[minIndex][i];
      int cost = Cost[minIndex][i];
      
      if(Table[Node] > Table[minIndex] + cost)
        Table[Node] = Table[minIndex] + cost;
    }
  }
  
  for(int i=0;i<=N;i++)
  {
    int minValue= 987987987;
    int minIndex = -1;
    
    for(int i=0;i<=N;i++)
    {
      if(!Check2[i] && minValue > Table2[i])
      {
        minValue = Table2[i];
        minIndex = i;
      }
    }
    
    Check2[minIndex] = 1;
    
    for(int i=0;i<Graph[minIndex].size() ; i++)
    {
      int Node = Graph[minIndex][i];
      int cost = Cost[minIndex][i];
      
      if(Table2[Node] > Table2[minIndex] + cost)
        Table2[Node] = Table2[minIndex] + cost;
    }
  }
  
  for(int i=0;i<=N;i++)
  {
    int minValue= 987987987;
    int minIndex = -1;
    
    for(int i=0;i<=N;i++)
    {
      if(!Check3[i] && minValue > Table3[i])
      {
        minValue = Table3[i];
        minIndex = i;
      }
    }
    
    Check3[minIndex] = 1;
    
    for(int i=0;i<Graph[minIndex].size() ; i++)
    {
      int Node = Graph[minIndex][i];
      int cost = Cost[minIndex][i];
      
      if(Table3[Node] > Table3[minIndex] + cost)
        Table3[Node] = Table3[minIndex] + cost;
    }
  }
  
  /*for(int i=1;i<=N;i++)
    printf("%d ", Table[i]);
  printf("\n");
  for(int i=1;i<=N;i++)
    printf("%d ", Table2[i]);
  printf("\n");
  for(int i=1;i<=N;i++)
    printf("%d ", Table3[i]);*/
  
  //Table : 1 ���� ��� ���������� �ִܰŸ� 
  //Table2 : A ���� ��� ���������� �ִܰŸ� 
  //Table3 : B ���� ��� ���������� �ִܰŸ� 
  
  //1���� A , A ���� B, B ���� N 
  //1���� B, B ���� A, A ���� N 
  
  int min = 987987987;
  
  if(min > Table[B] + Table3[A] + Table2[N])
    min = Table[B] + Table3[A] + Table2[N];
    
  if(min > Table[A] + Table2[B] + Table3[N])
    min = Table[A] + Table2[B] + Table3[N];
    
  printf("%d",min);
  
  return 0;
}
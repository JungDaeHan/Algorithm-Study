/*

��Ƽ

ö���� �������� N���� ���� ������, �� ���� ������ ��ȣ�� �ο��޴´�. 

�� ��ȣ�� 1���� ũ�ų� ����, N���� �۰ų� ����. ö���� ���� K�� ��� �ִ�. 

���� �� ���̿��� �ܹ��� ���ΰ� �����ϱ� ������, �� ���θ� ���Ͽ� ���� �̵��� �� �ִ�. 

��, N���� ������ �׷��� ������ �̷��. ���ǻ� �� ������ �� ������� ��� �ִٰ� ��������. 

ũ���������� ����, ö���� ������ ������ ��Ƽ�� ������ �Ѵ�. 

���� �ٸ� ��� ������� ö���� ���� �� ��Ƽ�� ����, ��Ƽ�� ���� �Ŀ��� �ٽ� ������ ������ ���ư��� �Ѵ�. 

������� ������ ������ ö���� ������ �̵��ϱ� ���Ͽ� �׻� �ִܰŸ��� �̵��ϱ⸦ ���ϰ�, 

���������� ö���� ������ ������ ���� �� ���� �ִܰŸ��� �̵��ϱ⸦ ���Ѵ�. 

���� ������ �� ���� �մ� �ܹ��� ������ ����, �׸��� ö���� �� ��ȣ�� �־��� ��, 

���� ������� ��Ƽ�� ���� ���ؼ� �̵��ؾ� �ϴ� �� �Ÿ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�

ù° �ٿ� ������ ���� N�� ������ ���� M, �׸��� ö���� �� ��ȣ K�� �־�����. ( 1 �� N, K �� 1,000, 1 �� M �� 100,000 ) 

��° �ٺ��� ������ ������ �־�����. �� ���� �� ���� ���� a, b, c�� �̷���� ������, �̴� ���� a���� ���� b�� �̵��ϴ� �� �ð��� c��ŭ �ɸ��ٴ� �ǹ��̴�. 

����� ���ΰ� �ƴԿ� ��������.


���

���� ������� ��Ƽ�� ���� ���ؼ� �̵��ؾ� �ϴ� �� �Ÿ��� ���� ����Ѵ�.

*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> Graph[1010];
vector<int> Cost[1010];

int mat[1010][1010] =  {0,};

int main() {

  //1���� N ���� �� ��ȣ
  //ö���� K ��
  // ������ �ܹ���
  
  int N,M,K;
  
  scanf("%d %d %d", &N, &M, &K);
  
  for(int i=0;i<M;i++)
  {
    int a,b,c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    mat[a][b] = c;
    
    //Graph[a].push_back(b);
    
    //Cost[a].push_back(c);
  }
  
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
    {
      if(i==j)
        continue;
        
      if(mat[i][j] == 0)
        mat[i][j] = 987987987;
    }
  
  for(int m=1;m<=N;m++)
    for(int s=1;s<=N;s++)
      for(int e=1;e<=N;e++)
      {
        if(mat[s][e] > mat[s][m] + mat[m][e])
          mat[s][e] = mat[s][m] + mat[m][e];
      }
  
  
  
  
  /*int Table[1010][1010];
  int Check[1010][1010] = {0,};
  
  for(int i=0;i<=N;i++)
  {
    for(int j=0;j<=N;j++)
      Table[i][j] = 987987987;
  }
  
  for(int i=1;i<=N;i++)
    Table[i][i] = 0;
  
  //1���� N ���� �� ��ȣ
  //ö���� K ��
  // ������ �ܹ���
  // ��� �������� ��� ���������� �ִܰŸ� -> �÷��̵�? �׷��� ���ͽ�Ʈ��� �غ���
  
  for(int i=1;i<=N;i++)
  { //i�� �� ������ ����ų ��
    for(int j=1;j<=N;j++)
    {
      //j�� �ٸ� �������� ����ų ��
      
      int minValue = 987987987;
      int minIndex = -1;
      
      for(int j=1;j<=N;j++)
      {
        if(!Check[i][j] && minValue > Table[i][j])
        {
          minValue = Table[i][j];
          minIndex = j;
        }
      }
      
      Check[i][minIndex] = 1;
      
      for(int j=0;j<=Graph[minIndex].size();j++)
      {
        int Node = Graph[minIndex][j];
        int cost = Cost[minIndex][j];
        
        if(Table[i][Node] > Table[i][minIndex] + cost)
          Table[i][Node] = Table[i][minIndex] + cost;
      }
    }
  }
  
  int sum = 0;
  
  for(int i=1;i<=N;i++)
    sum+= Table[K][i];
    
  for(int i=1;i<=N;i++)
  {
    sum+= Table[i][K];
  }*/
  
  int sum=0;
  
  for(int i=1;i<=N;i++)
  {
    sum+= mat[K][i];
    sum+= mat[i][K];
  }
  
  
  printf("%d", sum);
  
  return 0;
}
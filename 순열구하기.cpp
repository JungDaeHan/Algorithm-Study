/*


�������ϱ�

���� �ٸ� n���� ���ҵ� �߿��� r������ �̾� �Ϸķ� �����ϴ� ���� �����̶� �Ѵ�. 

���� ���, 3���� ���� a, b, c �߿��� 2������ �̾� �����ϸ� ab, ac, ba, bc, ca, cb �� 6���� ��찡 �ִ�.

n�� r�� �־��� ��, n���� �ҹ��� �߿��� r������ �̾� �����ϴ� ��� ��츦 ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

��, a���� �����Ͽ� �������� n���� ���ĺ��� ���� �ִٰ� ����. 
 

�Է�

ù ��° �ٿ� n�� r�� �־�����. ( 1 �� n �� 10, 0 �� r �� min(n, 7) )  

���

�� �ٿ� n���� �ҹ��� �߿��� r������ �̾� �����ϴ� ��츦 ���������� ������ ����� ����Ѵ�.


*/


#include <stdio.h>
#include <string.h>

void perm(int n,int r,char alpha[],char result[],int cnt)
{
  int i=0;
  
  if(r==0)
  {
    printf("%s", result);
    printf("\n");
    return;
  }

  for(i=0;i<n;i++)
  {
   // alpha[i-1] = 1;
    if(alpha[i] == 0)
      continue;
      
    result[cnt] =i+97; 
    
    alpha[i]=0;
    perm(n,r-1,alpha,result,cnt+1);
    alpha[i]=1;
  }
  
  
  
}

int main() {

  int n,r;
  char alpha[28] = {0,};
  char result[10]={0,};
  
  scanf("%d %d", &n, &r);
  
  for(int i=0;i<n;i++)
  {
    alpha[i] = 1;
  }
  
  perm(n,r,alpha,result,0);
  
  return 0;
}
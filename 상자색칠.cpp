
/* 

���� ��ĥ ����

���� 6���� ���ڰ� �ִ�. �̸� ���� ���� ������ ĥ�Ϸ� �ϴµ�, �� ������ �ִ�. 
������ �鿡 ���� ������ ĥ�ϸ� �� �ȴٴ� ���̴�. 
���� ���� ������ �־����� ��, �� ������ ������ �����Ͽ� ������ ��� ���� ĥ�� �� �ִ��� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.

 
�Է�

ù° �ٿ� ������ ���� N ( 1 <= N <= 1,000 ) �� �־�����. 
��° �ٿ� ������ ��Ÿ���� N���� ���ڰ� �־�����. ������ ���� ������ �̷���� �ְ�, 
1���� N������ ������ ���̴�.

 
���

������ �����ϸ鼭 ���ڸ� ĥ�� �� ������ ��YES��, �ƴϸ� ��NO���� ����Ѵ�.

*/



#include <stdio.h>
#include <malloc.h>

int arrChange(int arr[], int j,int N) // j��°�� ���� ���ְ�, ���� ������ ������
{
  for(int i=j;i<N-1;i++)
    arr[i] = arr[i+1];
    
  return N-1;
}

int main() {

  int N;
  int *cor;
  int *tmp; // tmp ���� 
  int len;
  int i,j,a;
  int flag =1;
  
  scanf("%d", &N);

  len = N;
  cor = (int*)malloc(sizeof(int)*N);
  tmp = (int*)malloc(sizeof(int)*6);
  
  for(i=0;i<N;i++)
    scanf("%d", &cor[i]);

  tmp[0] = cor[0];
  len = arrChange(cor,0,N);

  a=len;
  for(j=0;j<len;j++)
  {
    if(tmp[0] != cor[j])
    {
      tmp[1] = cor[j];
      len = arrChange(cor,j,len);
      break;
    }
  }
  if(j==a)
    flag = 0;
  a=len;
  for(j=0;j<len;j++)
  {
   if(tmp[0] != cor[j])
    if(tmp[1] != cor[j])
    {
      tmp[2] = cor[j];
      len = arrChange(cor,j,len);
      break;
    }
  }
  if(j==a)
    flag = 0;
  a=len;
  for(j=0;j<len;j++)
  {
    if(tmp[0] != cor[j])
      if(tmp[2] != cor[j])
      {
        tmp[3] = cor[j];
        len = arrChange(cor,j,len);
        break;
      }
  }
  if(j==a)
    flag= 0;
  a=len;
  for(j=0;j<len;j++)
  {
    if(tmp[0] != cor[j])
      if(tmp[1] != cor[j])
        if(tmp[3] != cor[j])
        {
          tmp[4] = cor[j];
          len = arrChange(cor,j,len);
          break;
        }
  }
  if(j==a)
    flag = 0;
  a=len;
  for(j=0;j<len;j++)
  {
    if(tmp[1] != cor[j] && tmp[2] != cor[j] && tmp[3] != cor[j] && tmp[4] != cor[j])
          {
            tmp[5] = cor[j];
            break;
          }
  }
  if(j==a)
    flag = 0;
    
  if(flag)
    printf("YES");
  else
    printf("NO");
    
  
 return 0;
}
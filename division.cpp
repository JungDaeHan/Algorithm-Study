/*

division

������ �ڿ����� �׺��� ���� �ڿ������� ������ ǥ���� �� �ִ�. ���� ��� 4�� ���,

4 = 3+1
  = 2+2 
  = 2+1+1 
  = 1+1+1+1

���� ���� ������� ǥ�� �� �� �ִ�. �� �� , ������ ������ �����鼭 �� �������� �ٸ� ���� ���� ���� �����ϴµ�, ���� ��� ���� �� ���� ���� ��� ���� ����̴�.

2 + 1 + 1, 1 + 2 + 1 , 1 + 1 + 2

�ڿ��� n�� �Է� �޾� �̸� n���� ���� �ڿ������� ������ ��Ÿ���� ����� ��� ����ϴ� ���α׷��� ��� ȣ���� ����Ͽ� �ۼ��Ͻÿ�.

 
�Է�

ù �ٿ� 2 �̻� 20 ������ �ڿ��� n�� �־�����.


���

ù° �ٺ��� ��� ����� �� �ٿ� �ϳ��� ����Ѵ�. �ϳ��� �� �ȿ��� ū ���ڰ� ������ ������ �ϰ�, ��ü�����δ� ���� ���ڰ� ū ���� ���� ��µǵ��� �Ѵ�. 

���ڿ� ���ϱ� ���̿��� ������ ����. �׸��� ������ �ٿ��� �������� �ڿ����� ������ ����Ѵ�.

*/


#include <stdio.h>
#include <string.h>

int division(int n,char arr[],int idx,int *cnt)
{
  
  int i,j,sum=0;

  for(i=0;i<strlen(arr);i++)
    sum += arr[i];
 
  
  for(i=0;i<strlen(arr);i++)
  {
    if(arr[i] < arr[i+1])
      return *cnt;
  }
 
  if(sum>n)
    return *cnt;
  
  if(sum == n)
  {
    printf("%d",arr[0]);
    for(i=1;i<strlen(arr);i++)
      printf("+%d",arr[i]);
    printf("\n");
    *cnt+=1;
    i-=1;
    while(arr[i] == 1) // �̷��� �������� sum ��궧 index�� �����α�
      arr[i--] = 0;
    return *cnt;
  }

  for(i=n-1;i>0;i--)
  {
    arr[idx] = i;
    
    division(n,arr,idx+1,cnt);
    
  }
  
  
   /*if(n==0)
  {
    printf("%d",arr[0]);
    for(i=1;i<strlen(arr);i++)
      printf("+%d",arr[i]);
    printf("\n");
    return cnt;
  }*/
  
    /*if(n==1)
  {
    printf("%d",arr[0]);
    for(i=1;i<strlen(arr);i++)
      printf("+%d",arr[i]);
    printf("+1\n");
    return cnt;
  }*/
  
  
  /*if(arr[0] == n-1)
  {
    printf("%d+%d\n", arr[0],arr[1]);
    return;
  }
  
  for(i=2;i<n;i++)
  {
    for(j=0;j<i;j++)
    {
      if(arr[j] == 1)
        tmp[j] += tmp[j+1];
    }
    division(n,tmp,len-1);
  }
  */
  
  
  
  /*if(len == 2 && arr[1] == 1)
  {
    printf("%d+%d\n", arr[0], arr[1]);
    return;
  }
  
  printf("%d", arr[0]);
  for(int i=1;i<len;i++)
  {
    printf("+%d", arr[i]);
  }
  printf("\n");
  
  
  for(int i=0;i<len;i++)
  {
    if(len == 2)
    {
      arr[0] += 1;
      arr[1] -= 1;
      break;
    }
    if(arr[i] == 1 && arr[i+1] ==1)
    {
      arr[i] = 2;
      len -= 1;
      break;
    }
    else if(i == len-1)
    {
      arr[len-2] += arr[len-1];
      len -=1;
    }
  }
  
  
  division(n,arr,len);*/
  
  /*printf("%d", arr[0]);
  for(int i=1;i<len;i++)
  {
    printf("+%d", arr[i]);
  }
  printf("\n");*/
  
  
  
  
  
  
 /* int sum=0;
  
  for(int i=0;i<strlen(arr);i++)
  {
    printf("---%d---\n", arr[i]);
    sum+= arr[i];
  }
  printf("asdf\n");
  
  if(sum==n || f==1)
  {
    printf("%d", arr[0]);
    for(int i=1;i<strlen(arr);i++)
    {
      printf("+");
      printf("%d", arr[i]);
    }
    printf("\n");
    return;
  }
  //if(arr[0]==1)
  //  return;
  printf("===%d===%d====%d\n", f, b, cnt);
  
  while(f>=1)
  {
  arr[cnt] = f;
  
  if(f-1 < b+1)
  {
    arr[cnt+2]=1;
    division(n,arr,cnt+1,f,b-1);
  }
  else
  {
    arr[cnt+1]=b;
    division(n,arr,cnt,f-1,b+1);
  }
  f--;
  }
  
  */
}

int main() {

  int n,cnt=0;
  char arr[30]={0,};
  
  scanf("%d", &n);
   
  cnt = division(n,arr,0,&cnt);

  printf("%d", cnt);
  return 0;
}
/*

큰 자릿수 곱셈

두 자연수가 주어질 때 그들의 곱셈을 계산하는 프로그램을 작성하시오. 각 수는 1 이상 10^100 미만의 범위를 가진다.  


입력

첫 번째 줄과 두 번째 줄에 각각 하나의 자연수가 주어진다.  

출력

첫 번째 줄에 곱셈의 결과를 출력한다.  

*/


#include <stdio.h>
#include <string.h>

int front(char arr[], int len)
{
  for(int i=0;i<len;i++)
    arr[i] = arr[i+1];
    
  return len-1;
}

int main() {

  char num1[110];
  char num2[110];
  char mat[110][220]={0,};
  int i,j,c=0,xidx=0,yidx=0,tmp;
  int len1,len2,xlen,sum=0;
  int resultlen=0;
  
  scanf("%s %s", num1, num2);
  len1 = strlen(num1);
  len2 = strlen(num2);
  
  for(i=0;i<len1 ; i++)
    num1[i] -= 48;
  for(i=0;i<len2 ; i++)
    num2[i] -= 48;
  
  if(len1>len2)
  {
    j=len2-1;
    while(j>=0)
    {
    
      yidx = len1*2 -1 -xidx;
      c=0;
 
      for(i=len1-1;i>=0;i--)
      {
        
        sum = 0;
        
        if(c!=0)
          sum += c;
      
        sum += num1[i]*num2[j];
      
        if(sum>= 10)
        {
          mat[xidx][yidx] = sum%10;
          c = sum/10;
        }
        else
        {
          mat[xidx][yidx] = sum%10;
          c=0;
        }
        yidx--;
      }
      if(c!=0)
        mat[xidx][yidx] += c;
        
      xidx++;
      j--;
    }
    // 결과의 최대 index = len1*2-1
    /*for(i=0;i<xidx;i++)
    {
      for(j=0;j<len1*2; j++)
        printf("%d", mat[i][j]);
      printf("\n");
    }*/
    
    c=0;
    for(j=len1*2-1;j>=0;j--)
    {
      sum=0;
      
      if(c!=0)
        sum += c;
      
      for(i=0;i<xidx;i++)
        if(mat[i][j] != 0 )
          sum += mat[i][j];
      
      if(sum>=10)
      {
        mat[xidx][j] = sum%10;
       // printf("%d---%d\n", mat[xidx][j],sum);
        c = sum/10;
      }
      else
      {
        mat[xidx][j] += sum;
        c=0;
      }
    }

    resultlen = len1*2;
    while(mat[xidx][0] == 0)
    {
      if(resultlen == 1)
        break;
      resultlen = front(mat[xidx],resultlen);
    }
  }
 else
{
  i=len1-1;
  while(i>=0)
  {
    yidx = len2*2 -1 -xidx;
    c=0;

    for(j=len2-1;j>=0;j--)
    {
      sum=0;
    
      if(c!=0)
        sum += c;
   
      sum += num1[i]*num2[j];

      if(sum>=10)
      {
        mat[xidx][yidx] = sum%10;
        c=sum/10;
      }
      else
      {
        mat[xidx][yidx] = sum%10;
        c=0;
      }
      yidx--;
    }
      if(c!=0)
        mat[xidx][yidx] += c;

      xidx++;
      i--;
    }

  c=0;
  
  for(j=len2*2-1;j>=0;j--)
  {
    sum=0;
  
    if(c!=0)
      sum += c;
  
    for(i=0;i<xidx;i++)
       if(mat[i][j] != 0 )
         sum+= mat[i][j];
  
      if(sum>=10)
      {
        mat[xidx][j] = sum%10;
        c = sum/10;
      }
      else
      {
        mat[xidx][j] += sum;
        c=0;
      }
    }
  
    resultlen = len2*2;
    while(mat[xidx][0] == 0)
    {
      if(resultlen == 1)
        break;
      resultlen = front(mat[xidx],resultlen);
    }
}

    for(i=0;i<resultlen;i++)
      printf("%d", mat[xidx][i]);
  
  return 0;
}
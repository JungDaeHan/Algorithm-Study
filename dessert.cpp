/*


dessert

��� ���� �ҵ��� ����Ļ� �� ����� ���ο� ����� ���� �ߴ�.

N(1~15)������ �ҵ��� ������� �� ������ ��, �� �ҵ� ���̿� +, - , . �� �� 1������ �����ִ� ��Ų�� ��ġ�ؼ� ���� ����� 0 �� �ǰ� �ؾ� �ϴ� ���̴�. 

��(.)�� �����ִ� ��Ų�� ���� �� ū ���� ���� �� �ְ� �ȴ�. �Ʒ��� ���� ��츦 ����. 

(ps .�� �����ִ� ��Ų�� '����'�̶�� �����ϸ� �ȴ�.) 1-2.3-4.5+6.7 �̿� ���� ��ġ�� 1-23-45+67 �� ��Ÿ����. 

����� 0 �̴�. 10.11�� 1011 �� �ؼ��ȴ�.


�Է�

ù ° �ٿ��� �ҵ��� �� N(1 �� N �� 15)�� �Էµȴ�.


���

ó�� 20�ٿ� ���� ������ 20���� ���� ����ϴµ�, ���� ������ �ռ� ���� ����Ѵ�. 

������ +�� ���� �ռ��� -�� . �� ������� �ڵ�����. 

���� 20�� �̸��̸� ������ ���� �� ���ڿ� ���� ���̿� ������ �ΰ� ����Ѵ�. ��� ����Ѵ�.

������ �ٿ��� ������ ���� �� �������� ����Ѵ�.

*/

#include <stdio.h>
#include <string.h>

int dessert(int n,int result[],int idx,int *cnt)
{
  int sum=0,i,j;
  int tmp;
  int temp[40]={0,};//. result���� ������� �ϱ� ������ temp ����
  int tmpi=0;
  
  if(idx >= n*2 -3)
  {
    for(i=0;i<n*2-1;i++)
      temp[i] = result[i];
    
    for(i=1;i<n*2-1;i+=2)
    {
      if(temp[i] == 300)
      {
        if(temp[i-1]==0)
        {//10 �϶��� ��� �ٿ����ұ�
          if(temp[i+1] >= 10)
            temp[i] = temp[i-2]*100 + temp[i+1];
          else
            temp[i] = temp[i-2]*10 + temp[i+1];
          temp[i-1] = 0;
          temp[i+1] = 0;
          temp[i-2] = 0;
        }
        else
        {
          if(temp[i+1] >= 10)
            temp[i] = temp[i-1]*100 + temp[i+1];
          else
            temp[i] = temp[i-1]*10 + temp[i+1];
          temp[i-1] = 0;
          temp[i+1] = 0;
        }
      }
    }
  
    for(i=0;i<n*2-1;i++)
      if(temp[i] != 0 && temp[i] != 100 && temp[i] != 200)
      {  
        sum = temp[i];
        break;
      }
      
    for(;i<n*2-1;i++)
    {
      if(result[i] == 0)
        continue;
        
      if(temp[i] == 100)
        tmp = 100;
      else if(temp[i] == 200)
        tmp = 200;
      else
      {
        if(tmp == 100)
          sum += temp[i];
        else if(tmp == 200)
          sum -= temp[i];
      }
    }

    if(sum==0)
    {
      if(*cnt<=19)
      {
        for(i=0;i<n*2-1;i++)
        {
          if(result[i] == 100)
          {
            printf("+ ");
            continue;
          }
          else if(result[i] == 200)
          {
            printf("- ");
            continue;
          }
          else if(result[i] == 300)
          {
            printf(". ");
            continue;
          }
          else
            printf("%d ", result[i]);
        }
        printf("\n");
      }
      *cnt +=1;
    }
    return *cnt;
  }
 
 // for(i=0;i<n*2-1;i++)
  //  printf("%d ", result[i]);
  //printf("\n");
  
  /*if(idx >= n*2 -3)
  {
    for(int i=1;i<n*2-1;i+=2)
    {
     // printf("%d  aaa ", result[i]);
      if(result[i] == '.')
      {
        if(dot==0)
        {
        tmp = result[i-1]*10 + result[i+1];
        _result[tmpi++] = tmp;
        dot=1;
        }
        else
        {
          tmp = tmp*10 + result[i+1];
          _result[tmpi-1] = tmp;
          dot=1;
        }
      }
      else
      {
        if(_result[tmpi-1]>=10)
        {
          _result[tmpi++] = result[i];
          _result[tmpi++] = result[i+1];
          dot=0;
        }
        else
        {
          _result[tmpi++] = result[i-1];
          _result[tmpi++] = result[i];
          _result[tmpi++] = result[i+1];
          dot=0;
        }
      }
    }
    
    for(i=0;i<tmpi;i++)
      printf("%d ", _result[tmpi]);
    printf("\n");
    
    return;
  }*/
  
  result[idx+2] = 100;

  //for(i=0;i<n*2-1;i++)
  //  printf("%d ", result[i]);
  //printf("\n");


  dessert(n,result,idx+2,cnt);
  result[idx+2] = 200;
  dessert(n,result,idx+2,cnt);
  result[idx+2] = 300;
  dessert(n,result,idx+2,cnt);
  
  
  
}

int main() {

  int N,tmp=1;
  int cnt=0;
  //char op[20]={0,};
  int result[40];
  scanf("%d", &N);
  
  for(int i=0;i<N*2;i+=2)
    result[i] = tmp++;
  
  //for(int i=0;i<N*2;i++)
    //printf("%d ", result[i]);
  
  cnt = dessert(N,result,-1,&cnt);
  
  printf("%d", cnt);

  return 0;
}
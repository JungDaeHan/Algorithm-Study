/*

fly me to the alpha

��ȫ��� � ����, ���� ���� �ٸ� �༺������ �η����� ��ư� �� �ִ� �̷��� ������ �Ͼ���. 

�׸��� 2037���� �� ����, ȫ��� ���� ����簡 �Ǿ� ���ο� ���迡 ���� ���� ���� ������ ������ ��ٸ��� �ִ�.

�װ� ž���ϰ� �� ���ּ��� Alpha Centauri��� ���ο� �η��� �����ڸ��� ��ô�ϱ� ���� ��Ը� ��Ȱ ���� �ý����� ž���ϰ� �ֱ� ������, 

�� ũ��� ������ ��û�� ������ �ֽű������ �� �����Ͽ� ������ �����̵� ��ġ�� ž���Ͽ���. 

������ �� �����̵� ��ġ�� �̵� �Ÿ��� �ް��ϰ� �ø� ��� ��迡 �ɰ��� ������ �߻��ϴ� ������ �־, 

���� �۵��ñ⿡ k������ �̵��Ͽ��� ���� k-1 , k Ȥ�� k+1 ���⸸�� �ٽ� �̵��� �� �ִ�. 

���� ���, �� ��ġ�� ó�� �۵���ų ��� -1 , 0 , 1 ������ �̷л� �̵��� �� ������ ��ǻ� ���� Ȥ�� 0 �Ÿ���ŭ�� �̵��� �ǹ̰� �����Ƿ� 1 ������ �̵��� �� ������, 

�� �������� 0 , 1 , 2 ������ �̵��� �� �ִ� ���̴�. ( ���⼭ �ٽ� 2������ �̵��Ѵٸ� ���� �ñ⿣ 1, 2, 3 ������ �̵��� �� �ִ�. )

��ȫ��� �����̵� ��ġ �۵����� ������ �Ҹ� ũ�ٴ� ���� �� �˰� �ֱ� ������ x�������� y������ ���� �ּ����� �۵� Ƚ���� �̵��Ϸ� �Ѵ�. 

������ y������ �����ؼ��� ���� �̵���ġ�� �������� ���Ͽ� y������ �����ϱ� �ٷ� ������ �̵��Ÿ��� �ݵ�� 1�������� �Ϸ� �Ѵ�.

��ȫ�츦 ���� x�������� ��Ȯ�� y�������� �̵��ϴµ� �ʿ��� ���� �̵� ��ġ �۵� Ƚ���� �ּҰ��� ���ϴ� ���α׷��� �ۼ��϶�.  



�Է�

ù�ٿ� ���� ��ġ x �� ��ǥ ��ġ y �� ������ �־�����, x�� �׻� y���� ���� ���� ���´�. ( 0 �� x < y �� 100,000,000)

 
���

�� �׽�Ʈ ���̽��� ���� x�������κ��� y�������� ��Ȯ�� �����ϴµ� �ʿ��� �ּ����� �����̵� ��ġ �۵� ȸ���� ����Ѵ�.

*/



#include <stdio.h>

int main() {

  long long int x,y;
  long long int i,j;
  long long int num;
  long long int tmpi,tmp=0;
  scanf("%lld %lld", &x, &y);
  
  num = y-x;
  j=2;
  
  for(i=1;i<num;i++)
  {
    //printf("%d %d ---\n", i,j);
    if(num==i*i)
    {
      printf("%d", 1+(i-1)*2);
      return 0;
    }
    else if(num>i*i && num<j*j)
    {
      for(tmpi=1;tmpi<i+1;tmpi++)
        tmp+= tmpi;
      if(num > tmp*2)
      {
        printf("%d", i*2 +1 );
        return 0;
      }
      else
      {
        printf("%d", i*2);
        return 0;
      }
    }
    else if(num==j*j)
    {
      printf("%d", 3+(i-1)*2);
      return 0;
    }
    j++;
  }
  
  
  
  return 0;
}
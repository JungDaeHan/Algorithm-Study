/*

2���� ���� ����

2���� f(x) = x*x+ x �� �ְ�, ���� a�� �־�����. �츮�� f(x) = a �� �����ϴ� x�� ���� ã�� ������, ���� �� ���� ������ �������� �ʴ� ��찡 ����. 

���� ���, f(x) = 20 �� Ǯ���� �Ѵٸ�, x = 4�̱� ������ �̴� ����������, f(x) = 103 �� Ǯ���� �Ѵٸ� �̴� x = 9.6612... �ν� ������ �ƴϴ�.

�� ���������� x�� �����κ��� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���, f(x) = 103 �� Ǯ���� �Ѵٸ�, x = 9.6612... �̱� ������ �����κ��� 9�� �ȴ�.


�Է�

ù ��° �ٿ� ���� a�� �־�����. ( 1 �� a �� 1,000,000,000,000,000,000 )  


���

f(x) = a �� �����ϴ� x�� �����κ��� ����Ѵ�.  

*/

#include <stdio.h>

long long int BinarySearch(long long int start,long long int end,long long int value)
{
  long long int mid=(start+end)/2;
  
  if(start>end)
    return -1;
  if(start==end)
  {
    if(start*start + start <= value && (start+1)*(start+1) + start+1 > value)
      return start;
    else return -1;
  }
  
  if(mid*mid + mid <= value && (mid+1)*(mid+1) + mid+1 > value)
    return mid;
  else if(mid*mid + mid > value)
    return BinarySearch(start,mid-1,value);
  else if((mid+1)*(mid+1) + mid <= value)
    return BinarySearch(mid+1,end,value);

}

int main() {

  long long int a;
  long long int b;
  
  scanf("%lld", &a);

  b = BinarySearch(0,1000000000,a);
  
  printf("%lld", b);

  return 0;
}
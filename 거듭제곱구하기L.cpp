/*

�ŵ��������ϱ�L

n�� m�� �־��� ��, n�� m���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, n�� m���� ���� Ŀ�� �� �ֱ� ������, ������ 10,007 ���� ���� �������� ����Ѵ�.


�Է�

ù ��° �ٿ� ���� n�� m�� �־�����. ( 1 �� n �� 100, 1 �� m �� 1,000,000,000,000,000,000 )  


���

ù° �ٿ� n�� m���� 10,007 ���� ���� �������� ����Ѵ�.

*/

#include <stdio.h>
// �̰� ��ͷ� ??
int main() {

  long long int n;
  long long int m;
  long long int arr[100000];
  long long int idx=1;
  long long int i;
  long long int tmp;
  
  scanf("%lld %lld", &n, &m);
  
  // n�� �ѹ� ���Ҷ����� 10007 �� ���� �������� �迭�� ����
  // �迭�� ù��°�� ���� ���� ���´ٸ� break �� �ٳ��´ٸ�
  // m�� idx �� ������ � �������� �������� �ݺ��Ǵ����� Ȯ���Ѵ�.
  
  arr[0] = n%10007;
  tmp = n;
  for(int i=1;i<m;i++)
  {
    tmp = tmp*n;  
    //printf("%lld\n", tmp);
    if(tmp > 10007)
      tmp %= 10007;
    if(tmp%10007 == arr[0])
      break;
    arr[idx++] = tmp%10007;
  }
  // ���⼭ idx �� arr�� ���̷� ����
  
  //for(int i=0;i<idx;i++)
  //  printf("%lld ",arr[i]);
  if(m%idx == 0)
    printf("%lld", arr[idx-1]);
  else
    printf("%lld", arr[m%idx-1]);
  

  return 0;
}
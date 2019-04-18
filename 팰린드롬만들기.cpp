/*

팰린드롬만들기

팰린드롬이란, 앞으로 읽으나 뒤로 읽으나 똑같은 문자열을 말한다. 

예를 들어, “abcba”, “abccba” 등이 있을 수 있다. 문자열이 주어질 때, 

이를 팰린드롬으로 만들기 위하여 추가해야 하는 최소의 문자 개수를 출력하는 프로그램을 작성하시오. 

예를 들어, 문자열이 “abca” 로 주어질 경우, ‘b’만 추가하면 “abcba” 를 만들 수 있으므로, 이 때는 1개의 문자만 추가하면 된다. 

또 다른 예로써, 문자열이 “adcba” 로 주어질 경우에는, 문자 2개를 추가해야 한다.


입력

첫 번째 줄에 문자열이 주어진다. 이 문자열의 길이는 1,000 을 넘지 않는다.  


출력

주어진 문자열을 팰린드롬으로 만들기 위해서 추가해야 하는 문자 개수의 최솟값을 출력한다.

*/

#include <stdio.h>
#include <string.h>

int main() {

  char arr[1010];
  int len;
  int mat[1010][1010]={0,};
  
  fgets(arr,1010,stdin);
  
  len = strlen(arr);
  
  for(int i=len-1;i>=0;i--)
  {
    for(int j=i;j<len;j++)
    {
      if( i == j)
        continue;
      if( arr[i] == arr[j])
      {
        mat[i][j] = mat[i+1][j-1];
        continue;
      }
      else
      {
        if(mat[i+1][j] > mat[i][j-1])
          mat[i][j] = 1 + mat[i][j-1];
        else
          mat[i][j] = 1 + mat[i+1][j];
      }
    }
  }
  
  /*for(int i=0;i<len;i++)
  {
    for(int j=0;j<len;j++)
      printf("%d", mat[i][j]);
    printf("\n");
  }*/
  
  printf("%d", mat[0][len-1]);

  return 0;
}
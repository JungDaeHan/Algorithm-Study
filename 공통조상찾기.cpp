/*

��������ã��

Ʈ���� ��� X�� ���Ͽ� ������"�� ������ �� �ִ�. X�� ������"�̶�, ��Ʈ���� �ö󰡴� �߿� ������ ��� ��带 ���Ѵ�. 

���� ���, �Ʒ��� ���� Ʈ���� �־��� ���, ��� 8�� ������"�� ��� 0, ��� 2, ��� 6�� �ȴ�.

Ʈ���� �־�����, �� ��� X, Y�� �־��� ��, ���� ����� ���� ������ ã�� ���α׷��� �ۼ��Ͻÿ�.

 
�Է�

ù ��° �ٿ� Ʈ���� ��� ���� n, �� ��� X, Y�� ��ȣ�� �־�����. 

( 1 �� X, Y �� n �� 1000 ) �� ��° �ٺ��� Ʈ���� ���� ������ �־�����. 

�� ���� 2���� ���� a, b�� �̷������, �̴� ��� a�� ��� b�� �θ����� ���� �ǹ��Ѵ�. ��Ʈ�� ��� 0�̶�� �����Ѵ�.  


���

�� ��� X, Y�� ���� ������ ����Ѵ�.

*/

#include <stdio.h>

struct Tree
{
  int num;
  
  Tree * parent = NULL;
  
};



int main() {

  int n,X,Y;
  int node1, node2;
  int data1[1001],data2[1001];
  int i=0;
  int idx1,idx2;
  
  scanf("%d %d %d", &n, &X, &Y);
  
  struct Tree tree[1001];
  tree[0].num = 0;
  struct Tree *tmp = NULL;
  
  for(int i=0;i<n-1;i++)
  {
    scanf("%d %d", &node1, &node2);
    
    tree[node2].parent = &tree[node1];
    tree[node2].num = node2;
  
  }
  
  tmp = &tree[X];
  
  for(i=0; tmp->num != 0 ;i++)
  {
    tmp = tmp->parent;
    data1[i] = tmp->num;
    
  }
  idx1 = i;
  tmp = &tree[Y];
  
  for(i=0; tmp->num != 0 ; i++)
  {
    tmp = tmp->parent;
    data2[i] = tmp->num;
  }
  idx2 = i;
  
  for(i=0 ;i<idx1; i++)
  {
    for(int j=0; j<idx2; j++ )
    {
      if(data1[i] == data2[j])
      {
        printf("%d", data1[i]);
        return 0;
      }
    }
  }

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include"Graph.h"
//�洢��ʽΪ���� 
int main(int argc, char *argv[])
{
  int v;
  MGraph G;
  CraeteUDG(G);
  scanf("%d",&v);
  DFS(G,v);
  system("PAUSE");	
  return 0;
}

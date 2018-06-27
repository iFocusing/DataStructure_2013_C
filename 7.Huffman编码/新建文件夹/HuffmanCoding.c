#include <stdio.h>
#include <stdlib.h>
#include"HuffmanCoding.h"

int main(int argc, char *argv[])
{
  HuffmanTree HT;
  HuffmanCode HC;
  unsigned int *w;
  int n,i;
  printf("������Ҫ������ַ�������\n");
  scanf("%d",&n);
  w=(int*)malloc(n*sizeof(int));
  printf("�밴˳������ÿ���ַ���Ȩֵ��\n");
  for(i=1;i<=n;++i)
     scanf("%d",w+i); 
  HuffmanCoding(&HT,&HC,w,n);
  for(i=1;i<=2*n-1;i++)
    {printf("%d\t%d\t%d\t%d\n",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);}
  for(i=1;i<=n;i++)
    {
     printf("%d:",HT[i].weight);
     puts(HC[i]);
    }
 getchar(); getchar(); getchar();  
 system("PAUSE");	
 return 0;
}

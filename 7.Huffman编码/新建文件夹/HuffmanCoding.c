#include <stdio.h>
#include <stdlib.h>
#include"HuffmanCoding.h"

int main(int argc, char *argv[])
{
  HuffmanTree HT;
  HuffmanCode HC;
  unsigned int *w;
  int n,i;
  printf("请输入要编码的字符个数：\n");
  scanf("%d",&n);
  w=(int*)malloc(n*sizeof(int));
  printf("请按顺序输入每个字符的权值：\n");
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

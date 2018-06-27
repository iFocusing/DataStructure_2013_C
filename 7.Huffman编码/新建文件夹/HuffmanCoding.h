#ifndef _HUFFMANCODING_H
#define _HUFFMANCODING_H
#include<stdio.h>
#include<string.h>

typedef struct{
   unsigned int weight;
   unsigned int parent,lchild,rchild;        
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

void Select(HuffmanTree HT,int n,int *s1,int *s2)
{
   unsigned int m1,m2;
   int k;
   m1=m2=32767;
   for(k=1;k<=n;k++)
   {
      if((HT[k].parent==0)&&(HT[k].weight<m1))
      {
         m2=m1;*s2=*s1;
         m1=HT[k].weight;
         *s1=k;
       }
     else if((HT[k].parent==0)&&(HT[k].weight<m2))
          {
              m2=HT[k].weight;
              *s2=k;
          }
   }
}


void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,unsigned int *w,int n)
{  
printf("***************\n");
   char *cd;
   int m,i,c,start,f,s1=0,s2=0;
   HuffmanTree p;
   if(n<=1) return;
   m=(n*2)-1;
   *HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
   for(p=*(HT+1),i=1;i<=n;++i,++p,++w)   
    {
       p->weight=*w;
       p->parent=0;
       p->lchild=0;
       p->rchild=0;
    }
   for(;i<=m;++i,++p)   
    {
       p->weight=0;
       p->parent=0;
       p->lchild=0;
       p->rchild=0;
    }
   //建赫夫曼树；
   for(i=n+1;i<=m;++i)
   {
      Select(*HT,i-1,&s1,&s2);
      (*HT)[s1].parent=i;  (*HT)[s2].parent=i;
      if(s1<s2)
      {(*HT)[i].lchild=s1;(*HT)[i].rchild=s2;}
      else
      {(*HT)[i].lchild=s2;(*HT)[i].rchild=s1;}
      (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;                
   } 
   //-----从叶子到根逆向求每个字符的赫夫曼编码------
   *HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
   cd=(char*)malloc(n*sizeof(char));
   cd[n-1]='\0';
   for(i=1;i<=n;++i)
   {
      start=n-1;
      for(c=i,f=(*HT)[i].parent;f!=0;c=f,f=(*HT)[f].parent) 
          if((*HT)[f].lchild==c)  cd[--start]='0';
          else  cd[--start]='1';
      (*HC)[i]=(char*)malloc((n-start)*sizeof(char));
      strcpy((*HC)[i],&cd[start]);                
   } 
free(cd);
printf("##################\n");
}
#endif

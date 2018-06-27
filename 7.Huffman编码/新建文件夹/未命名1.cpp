#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
  unsigned int weight;
  int parent,lchild,rchild;
}HTNode,*HuffmanTree;      //��̬��������洢�շ�����
typedef char **HuffmanCode;//��̬��������洢�շ��������

void Select(HuffmanTree HT,int n,int &s1,int &s2)
{
 unsigned int m1,m2;
 int k;
 m1=m2=32767;
 for(k=1;k<=n;k++)
 {
  if((HT[k].parent==0)&&(HT[k].weight<m1))
  {
   m2=m1;s2=s1;
   m1=HT[k].weight;
   s1=k;
  }
  else if((HT[k].parent==0)&&(HT[k].weight<m2))
  {
   m2=HT[k].weight;
   s2=k;
  }
 }
}

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,unsigned int *w,int n)
{
 int i,m,start,c,f;
 int s1=0,s2=0;
 char *cd;
 HuffmanTree p;
 if(n<=1) return;
 m=2*n-1;
 HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//0�ŵ�Ԫδ��
 for(p=HT+1,i=1;i<=n;++i,++p,++w)
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
 for(i=n+1;i<=m;++i)//���շ�����
 {//----��HT[1...i-1]ѡ��parentΪ0��weight��С�������ӵ㣬����ŷֱ�Ϊs1,s2----
  Select(HT,i-1,s1,s2);
  HT[s1].parent=i;HT[s2].parent=i;
  if(s1<s2)
  {HT[i].lchild=s1;HT[i].rchild=s2;}
  else
  {HT[i].lchild=s2;HT[i].rchild=s1;}
  HT[i].weight=HT[s1].weight+HT[s2].weight;
 }
 //----��Ҷ�ӵ���������ÿ���ַ��ĺշ�������----
 HC=(HuffmanCode)malloc((n+1)*sizeof(char*));//����n���ַ������ͷָ������
 cd=(char*)malloc(n*sizeof(char));           //���������Ĺ����ռ�
 cd[n-1]='\0';                               //���������
 for(i=1;i<=n;++i)                           //����ַ���շ�������
 {
  start=n-1;                              //���������λ��
  for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)//��Ҷ�ӵ������������
   if(HT[f].lchild==c)
    cd[--start]='0';
   else
    cd[--start]='1';
  HC[i]=(char*)malloc((n-start)*sizeof(char));
  strcpy(HC[i],&cd[start]);              //��cd���Ʊ��뵽HC
 }
 free(cd);
}

int main()
{
 unsigned int *weigh;
 int i,n;
 HuffmanTree ht;
    HuffmanCode hc;
 printf("������Ȩֵ������");
 scanf("%d",&n);
 weigh=(unsigned int *)malloc(n*sizeof(unsigned int));
 printf("������%d��Ȩֵ��",n);
 for(i=0;i<n;i++)
  scanf("%u",weigh+i);
 HuffmanCoding(ht,hc,weigh,n);
 for(i=1;i<=2*n-1;i++)
    {printf("%u\t%d\t%d\t%d\n",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);}
 for(i=1;i<=n;i++)
    {
  printf("%u:",ht[i].weight);
  puts(hc[i]);
 }
 getchar(); getchar(); getchar(); getchar(); getchar(); 
}

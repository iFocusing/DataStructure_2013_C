#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100010;
struct node
{
   int a[6];
   node *next;
};
struct node *table[maxn];// 邻接表  存放六个数和求余 余数相同的数组节点
struct node snow[maxn];//存放 输入的数组
bool flag[maxn];
int n;
bool tcmp(int temp1[],int temp2[],int b[])
{
   int i;
   int flag1=1,flag2=1;
   for(i=0;i<6;++i)
   {
      if(temp1[i]!=b[i])flag1=0;
      if(temp2[i]!=b[i])flag2=0;
   }
   if(flag1||flag2)return 1;
   else return 0;
}
bool cmpare(node *a,node *b)
{
     int temp1[6],temp2[6];
     int i,j;
    while(a)
    {
       int i=-1;
       while(i<6)
       {
          i++;
          for(;a->a[i]!=b->a[0]&&i<6;++i);
          if(i==7)break;
          for(j=0;j<6;++j)
          temp1[j]=a->a[(i+j)%6];
          for(j=0;j<6;++j)
          temp2[j]=a->a[(i-j+6)%6];
          if(tcmp(temp1,temp2,b->a))return 1;
       }
       a=a->next;
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j;
    
    
   while(scanf("%d",&n)&&n)
   {int yes=0;
   memset(flag,0,sizeof(flag));
   for(i=0;i<n;++i)
    {
       int sum=0;
       for(j=0;j<6;++j)
       {
          scanf("%d",&snow[i].a[j]);
          sum+=snow[i].a[j];
       }
       int key=sum%maxn;
       if(!flag[key])
       {
          flag[key]=1;
          table[key]=&snow[i];
          snow[i].next=NULL;
       }
       else if(cmpare(table[key],&snow[i]))
       {
          yes=1;
       }
       else
        {
           snow[i].next=table[key];
           table[key]=&snow[i];
        }
    }
    if(!yes)
    printf("No two snowflakes are alike.\n");
    else printf("Twin snowflakes found.\n");
   }
    //system("pause");
    return 0;
} 


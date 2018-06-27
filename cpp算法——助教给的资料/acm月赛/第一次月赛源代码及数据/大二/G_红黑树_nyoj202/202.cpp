 
#include"stdio.h"
int tree[12],r[12],l[12],l1[12],r1[12];

   void bianli(int a)
   {
          
    if(a!=-1)
	{
	     bianli(l[a]);
		 printf("%d\n",a);
		 bianli(r[a]);

	}

   }



int main()
{
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
int t,n,i,j,k,node,c,d;
 scanf("%d",&t);
 while(t--)
 {
      scanf("%d",&node);
	  for(i=0;i<node;i++)
        scanf("%d%d%d",&tree[i],&l1[i],&r1[i]);

   for(i=0;i<node;i++)
   {
        l[tree[i]]=l1[i];
		r[tree[i]]=r1[i];
   
   }


	  scanf("%d",&k);
	  while(k--)
	  scanf("%d%d",&c,&d);

	  
	  bianli(0);
	  printf("\n");

 }

return 0;
}        

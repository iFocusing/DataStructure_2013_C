 
#include <stdio.h>

int count=0;
int x_h(int y)
{
	int u,d,h,t,p,q,j,k,w,r;
    u=y%1000%100%10;
    d=y%1000%100/10;
	h=y%1000/100;
	t=y/1000;
    int a[4]={u,d,h,t};
	for (j=0;j<4;j++)
	    for (k=j+1;k<4;k++)
             if (a[j]<a[k])
			 {w=a[j];a[j]=a[k];a[k]=w;}
	p=a[0]*1000+a[1]*100+a[2]*10+a[3];
	q=a[3]*1000+a[2]*100+a[1]*10+a[0];
	r=p-q;	
	count++;
	if (r!=y)
		x_h(r);
   return count;
}
int main()
{
	int i,n,m,r;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
        count=0;//在这里添加 
		scanf("%d",&m);
	    r=x_h(m);
		printf("%d\n",r);
	}
	return (0);
}
        

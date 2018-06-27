#include<stdio.h>	
bool isp[9989900];
int p[1000];

//判断素数，筛法选素数 
void set()
{
	int i,j;
	for(i=5;i<=3163;i++)
		isp[i]=0;
	for(i=2;i<=3163;i++)
	{
		if(isp[i])continue;
		for(j=i*i;j<=9989899;j+=i)
			isp[j]=true;
	}
}

//判断回文数 
bool test(int a)
{
	int temp=a;
	int b=0;
	while(temp!=0)
	{
		b=b*10;
		b+=temp%10;
		temp/=10;
	}
	return a==b;
}
int main()
{
	int a,b;
	int i,k=0;
	set();
	for(i=5;i<=9989899;i+=2)
		if(!isp[i] && test(i))
			p[k++]=i;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		for(i=0;i<k;i++)
		{
			if(p[i]<a)
				continue;
			else if(p[i]<=b)
				printf("%d\n",p[i]);
			else
				break;
		}
		printf("\n");
	}
	return 0;
}

 
#include<stdio.h>
int Soldier[1000002]={0};
int main()
{
	int n,m,i,sum,a,b,so;
	scanf("%d%d",&n,&m);
	for(i=1;i<n+1;i++){
		scanf("%d",&so);
		Soldier[i]=Soldier[i-1]+so;
	}
	while(m--){
		scanf("%d%d",&a,&b);
		sum=0;
		printf("%d\n",Soldier[b]-Soldier[a-1]);
	
	}
}        

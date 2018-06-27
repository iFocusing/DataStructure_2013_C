 
#include<iostream>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int i,j,k,yshu,bshu,temp1,a,b;
	cin>>k;
	while(k--)
	{
		cin>>i>>j;
		a=i;
		b=j;
		if(i<j)
		{
			i=i^j;
			j=i^j;
			i=i^j;
		}
		while(i%j!=0)
		{
			temp1=j;
			j=i%j;
			i=temp1;
		}
		yshu=j;
		bshu=(a*b)/yshu;
		cout<<yshu<<" "<<bshu<<endl;

	}
	return 0;
}        

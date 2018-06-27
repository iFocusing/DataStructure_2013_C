 
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int T,L,D,R,n;
	float sum,temp;
	cin>>T;
	while(T--)
	{
		cin>>L>>D>>R;
		if(R<=D/2||(R*R-D*D/4.0)<0.5*0.5)
		{
			cout<<"impossible"<<endl;
			goto loop;
		}
		else
		{
			temp=2*sqrt((R*R-D*D/4.0));
			sum=0;
			n=0;
			while(sum<L)
			{
				sum+=temp;
				n++;
			}
		}
		cout<<n<<endl;
loop:{}
	}
	return 0;
}        

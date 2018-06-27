 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	char chars[8];
	int a,b,c,d,m,n,t,temp1,temp2;
	while(scanf("%s",chars)!=EOF)
	{
		a=chars[0]-48;
		b=chars[2]-48;
		c=chars[4]-48;
		d=chars[6]-48;
		if(chars[3]=='+')m=a*d+b*c;
		else
			m=a*d-b*c;
		if(m==0)
		{
			cout<<"0"<<endl;
			goto loop;
		}
		n=b*d;
		temp1=m;
		temp2=n;
		if(m<0)m=-m;
		t=n%m;
		while(t)
		{
			n=m;
			m=t;
			t=n%m;
		}
		n=temp2/m;
		m=temp1/m;
		if(m%n==0)
			cout<<m/n<<endl;
		else
		cout<<m<<"/"<<n<<endl;
loop:;
	}
	return 0;
}        

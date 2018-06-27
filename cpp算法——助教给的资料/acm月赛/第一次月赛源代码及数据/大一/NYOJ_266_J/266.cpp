 
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	stack <char> S;
	char a[41];
	int n,i;
	cin>>n;
	n++;
	while(n--)
	{
		gets(a);
		i=0;
		while(a[i]!='\0')
		{
			if(a[i]<='z'&&a[i]>='a')
				S.push(a[i]);
			i++;
		}
		while(!S.empty())
		{
		cout<<S.top();
		S.pop();
		}
		cout<<endl;

	}
	return 0;
}        

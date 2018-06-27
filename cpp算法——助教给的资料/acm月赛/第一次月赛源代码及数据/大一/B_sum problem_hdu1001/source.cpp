#include<iostream>
using namespace std;
int main()
{    
	int n,count;
	while(cin>>n)
	{
		count=0;
		for(int i=1;i<=n;i++)
		{
            count+=i;
		}
		cout<<count<<endl;
		cout<<endl;
	}
	return 0;
}

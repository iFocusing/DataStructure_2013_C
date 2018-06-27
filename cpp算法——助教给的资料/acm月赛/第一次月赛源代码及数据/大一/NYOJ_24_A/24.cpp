#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n)
{
	for(int k=2;k<=sqrt((double)n);k++)
		if((n%k)==0)
			return false;
		return true;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		int num,i,j;
		cin>>num;
		if(num==1)
		{
			cout<<"2 1"<<endl;
			continue;
		}
		for(i=num;!isprime(i);i--);
		for(j=num;!isprime(j);j++);
		if((num-i)<=(j-num))
			cout<<i<<" "<<(num-i)<<endl;
		else 
			cout<<j<<" "<<(j-num)<<endl;

	}
	return 0;
}        

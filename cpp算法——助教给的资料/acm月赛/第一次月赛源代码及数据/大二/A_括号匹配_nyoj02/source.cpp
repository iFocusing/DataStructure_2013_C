 
#include <iostream>
#include <stack>
using namespace std;
char str[10000];
bool judge( char s[])
{
	stack<char> stack;
	while(*s)
	{
		if(*s=='('||*s=='[')stack.push(*s);
		if(*s==')')
			if(stack.empty())return 0;
			else if(stack.top()=='(')stack.pop();
			else return 0;
		 if(*s==']')
			 if(stack.empty())return 0;
			 else if(stack.top()=='[')stack.pop();
			 else return 0;
		s++;
	}
	if(stack.empty())return 1;
	else return 0;
}
int main()
{

	int n;
	cin>>n;
	while(n>0)
	{
		cin>>str;
		if(judge(str))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		n--;
	}
	return 0;
}        

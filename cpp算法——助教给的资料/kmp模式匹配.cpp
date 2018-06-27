#include <iostream> 
using namespace std;
void getnext(char t[],int next[])
{
    int i=1,j=0;
    next[1]=0;

	//这个不能相等
    while(i<t[0])
    {
        if(j==0 || t[i]==t[j])
        {
            i++;j++;
            if(t[i]!=t[j])next[i]=j;
            else next[i]=next[j];
        }
        else j=next[j];
    }

}
int main()
{
    int *next;
    char s[100],t[50];
    gets(s+1);
    gets(t+1);
    s[0]=strlen(s+1);
    t[0]=strlen(t+1);
//	cout<<(int)s[0]<<" "<<(int)t[0]<<endl;
    next=new int[sizeof(int)*t[0]];
    getnext(t,next);

//	 for(int i=1;i<=t[0];i++)
//    cout<<next[i]<<" ";
//  cout<<endl;
   int i=1;int j=1;

	//这个地方千万可以相等
    while(i<=s[0] && j<=t[0])
    {
        if(j==0||s[i]==t[j]){i++;j++;}
        else j=next[j];
    }

    if(j>t[0])cout<<i-t[0]<<endl;
       else cout<<"no find!"<<endl;
    delete []next;
    system("PAUSE");
    return 0;
}

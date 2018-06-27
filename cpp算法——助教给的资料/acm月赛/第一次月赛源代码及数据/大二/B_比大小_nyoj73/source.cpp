 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cmp(char a[],char b[])
{
    if( (a[0]-'0')*(b[0]-'0')<0)return a[0]-'0';
    if( a[0] < '0' && b[0] < '0')return -1*(cmp(a+1,b+1));
    int alen=strlen(a),blen=strlen(b);
    if(alen!=blen)return alen-blen;
    return strcmp(a,b);
}
int main()
{
 
    char a[1005],b[1005];
    while(cin>>a>>b,a[0]!='0' || b[0]!='0')
    {
        int res=cmp(a,b);
        if(res>0)puts("a>b");
        else if(res==0)puts("a==b");
        else puts("a<b");
    }
 //   system("pause");
    return 0;
}
        

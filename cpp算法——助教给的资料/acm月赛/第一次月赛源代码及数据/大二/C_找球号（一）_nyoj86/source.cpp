 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int hash[3125100],n,m;
int main()
{
   scanf("%d %d",&n,&m);
    int x,t,mod;
    char ch;
    for(int i=0; i<n; i++)
    {
        x=0;
        while(!((ch=getchar())>='0'&&ch<='9'))
        {
        }
        x=(ch-'0');
        while((ch=getchar())>='0' && ch<='9')
            x=x*10+(ch-'0');
        t=x>>5;
        mod=x-(t<<5);
        hash[t]|=(1<<mod);
    }
    for(int i=0; i<m; i++)
    {
        x=0;
        while(!((ch=getchar())>='0'&&ch<='9'))
        {
        }
        x=(ch-'0');
        while((ch=getchar())>='0' && ch<='9')
            x=x*10+(ch-'0');
        t=x>>5;
        mod=x-(t<<5);
        if(hash[t]&(1<<mod))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
        

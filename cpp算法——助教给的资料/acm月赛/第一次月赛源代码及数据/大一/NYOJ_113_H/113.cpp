 

     
 
#include <iostream>
#include <string>

using namespace std;

int main()
{freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    for(string str;getline(cin,str);)
    {
        string::iterator it=str.begin();
        for(int i=2;i<str.length();i++)
        {
            if(str[i-2]=='y'&&str[i-1]=='o'&&str[i]=='u')
            {
                str.erase(it+i);
                str[i-2]='w';
                str[i-1]='e';
            }
        }
        cout<<str<<endl;
    }
    //system("pause");
    return 0;
}
        

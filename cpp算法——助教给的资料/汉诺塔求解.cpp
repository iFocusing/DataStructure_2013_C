#include <iostream>
using namespace std;


void move( char a, char c){
     cout<<a<<"->"<<c<<endl;
}
void hanio(int n, char a,char b, char c){
     if(n==1) move(a,c);
     else{
          hanio(n-1,a,c,b);
          move(a,c);
          hanio(n-1,b,a,c);
     }
}
int main(){
    hanio(2,'a','b','c');
    system("PAUSE");
}

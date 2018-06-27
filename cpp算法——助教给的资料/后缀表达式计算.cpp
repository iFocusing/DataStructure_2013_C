#include <iostream>
#include <stack>
using namespace std;
int yxj(char );
char ee[100];
int ei =0;
int main(){
    void ins(char,stack<char> &);
    stack<char> s;
    char exp[100];
    cin>>exp;
    int i=0;
    while(exp[i]!='\0'){
       if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='('||exp[i]==')'){
          ins(exp[i],s);                                                                 
       }else{
         cout<<exp[i];
         ee[ei++]=exp[i];
       }
       i++;
    }
    while(!s.empty()){
      cout<<s.top();
      ee[ei++]=s.top();
      s.pop();
    }
    cout<<endl;
    cout<<"----------"<<endl;
    
    stack<int> s2;
    i =0;
    int a,b;
    while(ee[i]!='\0'){
       if(ee[i]>='0'&&ee[i]<='9'){
         s2.push(ee[i]-'0');
       }else{
       b = s2.top();
       s2.pop();
       a = s2.top();
       s2.pop();
       if(ee[i]=='+'){ s2.push(a+b);}
       if(ee[i]=='-'){ s2.push(a-b);}
       if(ee[i]=='*'){ s2.push(a*b);}
       if(ee[i]=='/'){ s2.push(a/b);}
       }
       i++;
    }
     cout<<"answer:"<<s2.top()<<endl;

    system("PAUSE");
}

void ins(char ch , stack<char> &s){
  if(s.empty()) s.push(ch);
  else if(ch=='(') s.push(ch);
  else if(ch==')'){
       while(s.top()!='('){
         cout<<s.top();
         ee[ei++]=s.top();
         s.pop();
       }
       s.pop();
  }
  else if(yxj(ch)>=yxj(s.top())) s.push(ch);
  else {
    cout<<s.top();
    ee[ei++]=s.top();
    s.pop();
    ins(ch,s);
  }
}

int yxj(char ch){
    if(ch=='*'||ch == '/')return 2;
    if(ch=='+'||ch == '-') return 1;
    if(ch=='(')return 0;
}

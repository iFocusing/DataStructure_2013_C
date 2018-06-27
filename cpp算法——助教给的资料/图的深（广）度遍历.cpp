#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;
typedef list<int> head;
typedef struct {
  char vex;
  head * first;
}vexNode;

vector<vexNode> vexs;
queue<int> q;

////
char * info[6]={"A41","B2","C3","D10","E2"};
int num = 5;
///
void init(){
  char * temp =NULL;
  for(int i = 0;i<num; i++){
    temp = info[i];
    vexNode v;
    head *h = new head(); 
    int j=0;
    while(*temp!='\0'){
      if(j==0)
        v.vex =*temp;
      else 
        h->push_back(*temp-'0');
      j++;
      temp++; 
    }
    v.first = h;
    vexs.push_back(v);
  }
}

void printOut(){
   vector<vexNode>::iterator  it ;
   it = vexs.begin();
   while(it != vexs.end()){
      vexNode n = *it;
      cout<<n.vex;
      head * first = n.first;
      head::iterator itt = first->begin();
      while(itt != first->end()){
        cout<< *itt;
        itt++;
      }
      it++;
      cout<<endl;
  }
}

void depth(int *a, int x){
  if(a[x] ==0){
    cout<< vexs.at(x).vex;
    a[x] = 1 ;
    head * first = vexs.at(x).first;
    head::iterator it = first->begin();
    while(it != first->end()){
      if(a[*it]==0){
        depth(a,*it); 
      } 
      it++;
    }
  } 
}

void width(int *a ,int x){
   int temp ;
   q.push(x);
   while(!q.empty()){
       temp = q.front();
       q.pop();
       if(a[temp]==0){
          cout<<vexs.at(temp).vex  ;
          a[temp]=1; 
       }
       head *first = vexs.at(temp).first;
       head::iterator it = first->begin();
       while(it!=first->end()){
          if( a[*it] ==0){
              cout<<vexs.at(*it).vex;
              a[*it] = 1;
              q.push(*it);
          }
          it++;
      } 
   }
}

int main(){
  init();
  printOut();
  
  int a[5] ={0};
  depth(a,0);
  memset(a,0,20);


  cout<<endl;
  width(a,4);
  system("PAUSE");
}

#include <iostream>
#include <stack>
using namespace std;
//1,1 5,5
class path{
      public :
              int x,y;
      };
char map[7][7]={{'b','b','b','b','b','b','b'},
                {'b','a','b','a','a','a','b'},
                {'b','a','a','a','b','b','b'},
                {'b','a','a','b','a','a','b'},
                {'b','a','b','a','a','a','b'},
                {'b','a','a','a','b','a','b'},
                {'b','b','b','b','b','b','b'}}; 

char map2[7][7]={{'b','b','b','b','b','b','b'},
                {'b','a','b','a','a','a','b'},
                {'b','a','a','a','b','b','b'},
                {'b','a','a','b','a','a','b'},
                {'b','a','b','a','a','a','b'},
                {'b','a','a','a','b','a','b'},
                {'b','b','b','b','b','b','b'}};   
stack<path> s;             
int main(){
    void find();
  map2[1][1] = 'c';
  path *start = new path();
  start->x = 1;
  start->y =1;
  
  s.push(*start);
  path p;
  while(1){
     if(s.empty()){ cout<<" error"<<endl;break;}
     p = s.top();
     if(p.x==5&&p.y==5){ cout<<"success"<<endl;break;}
     find();            
  }  
  int i,j;
  for(i = 0 ;i<7;i++){
  for(j=0;j<7;j++){
   cout<<map2[i][j];                
                   }
   cout<<endl;
                   }
  system("PAUSE");          
}

void find(){
  if(map2[s.top().x][s.top().y+1]=='a'){
  path *temp  = new path();
  temp->x=s.top().x;
  temp->y = s.top().y+1;
  s.push(*temp); 
  map2[s.top().x][s.top().y]='c';   
  cout<<"east,"<< s.top().x<<","<< s.top().y<<endl;    
  //system("PAUSE");                          
 }else if(map2[s.top().x+1][s.top().y]=='a'){
  path *temp  = new path();
  temp->x=s.top().x+1;
  temp->y = s.top().y;
     s.push(*temp);   
     map2[s.top().x][s.top().y]='c';
     cout<<"south,"<< s.top().x<<","<< s.top().y<<endl; 
    // system("PAUSE"); 
 }else if(map2[s.top().x][s.top().y-1]=='a'){
  path *temp  = new path();
  temp->x=s.top().x;
  temp->y = s.top().y-1;
     s.push(*temp);  
     map2[s.top().x][s.top().y]='c'; 
     cout<<"west,"<< s.top().x<<","<< s.top().y<<endl; 
     //system("PAUSE"); 
 }else if(map2[s.top().x-1][s.top().y]=='a'){
  path *temp  = new path();
  temp->x=s.top().x-1;
  temp->y = s.top().y;
     s.push(*temp);  
     map2[s.top().x][s.top().y]='c';  
     cout<<"north,"<< s.top().x<<","<< s.top().y<<endl; 
    // system("PAUSE"); 
 }else{
   map2[s.top().x][s.top().y] ='b'; 
   s.pop();
 }
}





#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m[10][10]={{0,0,0,0,0,0,0,0,0,0}, 
							 {0,1,0,0,0,0,0,0,0,0}, 
							 {0,0,0,0,2,0,0,0,0,0}, 
							 {0,0,0,0,0,0,0,0,0,0}, 
							 {0,0,0,0,0,0,0,0,0,6}, 
							 {0,0,0,0,0,0,0,0,0,0}, 
							 {0,0,0,3,0,0,0,4,0,0}, 
							 {0,0,0,0,0,0,0,0,0,0}, 
							 {0,0,0,0,0,0,0,0,0,0}, 
							 {0,0,0,0,0,0,5,0,0,0}};
int a[2][10] ={0};
struct triple{
  int row;
  int col;
  int val;
  triple(int r=0,int c=0,int v=0){row = r;col = c;val = v;}
};
vector<struct triple> v;
vector<struct triple> v2;

int main(){
  void fill();
  void fill2();
  void fill3();
  fill();
  fill2();
  fill3();
  system("PAUSE");
}

void fill(){

 for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(m[i][j]!=0){
        v.push_back( triple(i,j,m[i][j]));
      }
    }
  }
  vector<struct triple>::iterator it = v.begin();
  while(it!= v.end()){
   cout<<it->row<<","<<it->col<<","<<it->val<<endl;
   it++; 
  } 
}
void fill2(){
  vector<struct triple>::iterator it = v.begin();
  while(it!= v.end()){
   a[0][it->col]++;
   it++; 
  }
  for(int i=1 ;i<10;i++){
   a[1][i]= a[0][i-1]+a[1][i-1]; 
  }
  for(int j =0;j<10;j++){
    printf("%3d",j );
  }
  cout<<endl;
  for(int j =0;j<10;j++){
    printf("%3d",a[0][j] );
  }
  cout<<endl;
  for(int k =0;k<10;k++){
    printf("%3d",a[1][k] );
  }
  cout<<endl;
}

void fill3(){
  struct triple tri[v.size()];
  vector<struct triple>::iterator it = v.begin();
  while(it!= v.end()){
    tri[a[1][it->col]]= triple(it->col,it->row,it->val);
    a[1][it->col]++;
   it++; 
  } 
  for( int i = 0;i<v.size();i++){
   cout<<tri[i].row<<","<<tri[i].col<<","<<tri[i].val<<endl;
  }
}

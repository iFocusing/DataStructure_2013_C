#include <iostream>
#include <queue>
using namespace std;
int map[7][7]= {{-1,-1,-1,-1,-1,-1,-1},
                {-1,0 ,-1, 0, 0, 0,-1},
                {-1,0 , 0, 0,-1,-1,-1},
                {-1,0 , 0, 0, 0, 0,-1},
                {-1,0 ,-1, 0, 0, 0,-1},
                {-1,0 , 0, 0,-1, 0,-1},
                {-1,-1,-1,-1,-1,-1,-1}}; 
class path{
  public :
    int x;
    int y;
    int count;
    path(int a=0,int b=0,int c =0){x=a;y=b;count = c;}
};
queue<path> q;
int main(){
    void fillIn();
    path s ;
    s.x=1;
    s.y=1;
    s.count =1;
    map[1][1]=1;
    q.push(s);
    while(!q.empty())
      fillIn();
    for(int i =0;i<7;i++){
    for(int j=0;j<7;j++)
      //cout<<map[i][j];
      printf("%3d",map[i][j]);
    cout<<endl;
    }
    system("PAUSE");
}

void fillIn(){
  path aPath;
  if(!q.empty()){
    aPath = q.front();
    if(map[aPath.x][aPath.y+1]==0){
     map[aPath.x][aPath.y+1] = aPath.count+1;
     path * temp = new path(aPath.x,aPath.y+1,aPath.count+1);
     q.push(*temp);
    }
    if(map[aPath.x+1][aPath.y]==0){
     map[aPath.x+1][aPath.y] = aPath.count+1;
     path * temp = new path(aPath.x+1,aPath.y,aPath.count+1);
     q.push(*temp);
    }
    if(map[aPath.x][aPath.y-1]==0){
     map[aPath.x][aPath.y-1] = aPath.count+1;
     path * temp = new path(aPath.x,aPath.y-1,aPath.count+1);
     q.push(*temp);
    }
    if(map[aPath.x-1][aPath.y]==0){
     map[aPath.x-1][aPath.y] = aPath.count+1;
     path * temp = new path(aPath.x-1,aPath.y,aPath.count+1);
     q.push(*temp);
    }
    q.pop();     
  }
}



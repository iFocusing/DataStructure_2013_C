#include <iostream>
#include <queue>
using namespace std;
int map[9][9]= {{0,0,0,0,0,0,0,0,0},
                {0,0,0,1,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0},
                {0,0,0,0,0,1,0,0,0},
                {0,0,0,0,1,1,0,0,0},
                {0,0,1,0,0,1,0,1,0},
                {0,1,1,1,0,0,0,1,0},
                {0,1,1,1,0,0,1,1,0},
                {0,0,0,0,0,0,0,0,0}}; 
class Path{
 public :
    int x;
    int y;
    Path(int a=0, int b=0 ){x=a;y=b;} 
};
queue<Path> q;

int main(){
  void fill(int);
  int i,j;
  int count =1;
  for(i =1;i<=7;i++)
  for(j =1;j<=7;j++){
   if(map[i][j]==1){
     count ++;
     Path * temp = new Path(i,j );
     q.push(*temp);
     fill(count);
    } 
  }
  for(int i =0;i<9;i++){
    for(int j=0;j<9;j++)
      //cout<<map[i][j];
      printf("%3d",map[i][j]);
    cout<<endl;
    }
    cout<<"There are "<<count-1<<" graphics"<<endl;
    system("PAUSE");
}

void fill(int count){
  Path aPath;
 while( !q.empty()){
    aPath = q.front();
    if(map[aPath.x][aPath.y+1]==1){
     map[aPath.x][aPath.y+1] = count;
     Path * temp = new Path(aPath.x,aPath.y+1);
     q.push(*temp);
    }
    if(map[aPath.x+1][aPath.y]==1){
     map[aPath.x+1][aPath.y] = count;
     Path * temp = new Path(aPath.x+1,aPath.y);
     q.push(*temp);
    }
    if(map[aPath.x][aPath.y-1]==1){
     map[aPath.x][aPath.y-1] = count;
     Path * temp = new Path(aPath.x,aPath.y-1);
     q.push(*temp);
    }
    if(map[aPath.x-1][aPath.y]==1){
     map[aPath.x-1][aPath.y] = count;
     Path * temp = new Path(aPath.x-1,aPath.y);
     q.push(*temp);
    }
    q.pop(); 
  }
}

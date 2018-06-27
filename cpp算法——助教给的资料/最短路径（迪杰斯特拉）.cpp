#include<iostream>
#define N 6
#define MAX 10000
using namespace std;

int arcs[N][N]={{MAX,MAX,10 ,MAX,30 ,100},
                {MAX,MAX, 5 ,MAX,MAX,MAX},
                {MAX,MAX,MAX, 50,MAX,MAX},
                {MAX,MAX,MAX,MAX,MAX,10 },
                {MAX,MAX,MAX, 20,MAX, 60},
                {MAX,MAX,MAX,MAX,MAX,MAX}};

int s[N][3];
void initS(){
  for(int i =0;i<N;i++){
    s[i][0] = 0;
    s[i][1] = MAX;
    s[i][2] = -1; 
  } 
  s[0][1] = 0;
} 

int getSmallest()
{
  int min =-1;
  for(int i =0;i<N;i++){
    if(!s[i][0] )
	{
      min = i;
      break; 
    }
}
  for(int i = min;i<N;i++){
    if(s[i][0]==0 && s[i][1] <s[min][1]){
      min = i; 
    }
  } 
  return min;
}

void computer(){//以0号作为入口 
  int vex;
  
  while(true){
    vex = getSmallest();
    if(vex == -1) break;
    
    s[vex][0] = 1; //确立当前顶点为最短路径 
    cout<<"===="<<vex<<endl;
    for(int  i =0;i<N;i++){
      if (arcs[vex][i] != MAX){//当前是条边 
        if(s[i][0] == 0 ){
          if(s[vex][1]+ arcs[vex][i] < s[i][1]){
            s[i][1] = s[vex][1]+ arcs[vex][i]; // 赋值
            s[i][2] = vex;
          }   
        }
      } 
    }
  }
}

void printOut(){
  for(int i = 0;i<N;i++){
    printf("%6d%6d%6d\n",s[i][0],s[i][1],s[i][2]);
  }
}

void p(int x){
   if(x!=-1){
      p(s[x][2]);
      cout<<" "<<x;
    }
}

void printPath(){
  for(int i =0;i<N;i++){
    if(s[i][2] == -1){
      cout<<i<<": no path"<<endl; 
    } else{
      cout<<i<<": ";
      p(s[i][2]); 
      cout<<" "<<i<<"   :"<<s[i][1]<<endl; 
    }
  }
}


int main(){
  initS();
  computer();
  printOut();
  cout<<endl;
  printPath();
  system("pause");
}

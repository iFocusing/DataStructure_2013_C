#include<iostream>
#define MAX 20
using namespace std;

typedef struct gra{
  char vexs[MAX];
  int arcs[MAX][MAX];
  int vexnum;
  int arcnum;
}graph;

/*//////////////////////
char vexs[] ="ABCDEF";
int vexnum = 6;
int arcnum =7;
int a[6][6]={{0,1,0,0,1,0},
             {1,0,0,0,1,1},
             {0,0,0,1,0,1},
             {0,0,1,0,0,1},
             {1,1,0,0,0,0},
             {0,1,1,1,0,0}};
/*//////////////////////
char vexs[] ="ABCDE";
int vexnum = 5;
int arcnum =7;
int a[5][5]={{0,1,0,0,1},
             {0,0,1,0,0},
             {0,0,0,1,0},
             {1,1,0,0,0},
             {0,0,1,0,0}};


//////////////////////

void init(graph *g){
  g->vexnum = vexnum;
  g->arcnum = arcnum;
  strcpy(g->vexs,vexs);
  for(int i =0 ;i<vexnum;i++)
    for(int j = 0;j<vexnum;j++){
       g->arcs[i][j] = a[i][j]; 
    }
}

void  doVisit(graph *g , int *a ,int x){
  if(a[x]==0){
    cout<<g->vexs[x];
    a[x] = 1;
    for(int i=0;i<g->vexnum;i++){
      if(g->arcs[x][i]==1){
        doVisit(g,a,i); 
      } 
    } 
  }
}

void depthVisit(graph *g){
  int a[MAX] = {0};
  doVisit(g,a,0);
  /*
  for(int i =0;i<g->vexnmu;i++){
    if(a[i]==0)
      doVisit(g,a,i); 
  }
  
  */
}

void  doVisit2(graph *g , int *a ,int x){
  int flag = 0;
  if(a[x]==0){
    cout<<g->vexs[x];
    a[x] = 1; 
  }
  for(int i = 0 ;i<g->vexnum;i++){
    if(a[i]!=1&&g->arcs[x][i]==1){
      cout<<g->vexs[i];
      a[i]=1;
      flag = 1;
    } 
  }
  if(flag==0)return;
  for(int i =0;i<g->vexnum;i++){
     if(g->arcs[x][i]==1)
     {
        doVisit2(g,a,i);
      }
  }
}

void widthVisit(graph *g){
  int a[MAX]={0};
  doVisit2(g,a,3);
}

int main(){
  graph g;
  init(&g); 
  
  cout<<endl;
  depthVisit(&g);
  cout<<endl;
  widthVisit(&g);
  system("PAUSE");
}














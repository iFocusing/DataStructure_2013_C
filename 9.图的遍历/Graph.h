#ifndef _GRAPH_H
#define _GRAPH_H
#include"constant.h"

#include<stdio.h>

#define INFINITY  INT_MAX
#define MAX_VERTEX_NUM 20
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef VRType AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
   VextexType vexs[MAX_VERTEX_NUM];
   AdjMatrix arcs;
   int vexnum,arcnum;
   GraphKind kind;          
}MGraph;

Status CreateGraph(MGraph *G){
   scanf("%s",(*G).kind);
   switch((*G).kind){
     case DG:return:CreateDG(&G);
     case DN:return:CreateDN(&G);
     case UDG:return:CreateUDG(&G);
     case UDN:return:CreateUDN(&G);
     default :return ERROR;               
   }      
}

Status CreateUDG(MGraph *G){
    int i;
    scanf("%d,%d",&(*G).vexnum,&(*G).arcnum);
    for(i=0;i<(*G).vernum;++i)
       scanf("c",&(*G).vexs[i]);
    for(i=0;i<(*G).vernum;++i)
    {
       for(j=0;j<(*G).vexnum;++j)
         (*G).arcs[i][j]={INFINITY,NULL};                       
    }         
    for(k=0;k<(*G).arcnum;++k)
    {
       scanf(&v1,&v2,&w);
       i=LocateVex(G,v1); j=LocateVex(G,v2);
       (*G).arc[i][j].adj=w;                     
    } 
    return OK;             
}

//深度优先遍历
Boolean visited[MAX];
Status (*VisitFunc)(int v);
void DFSTraverse(Graph G,Status(*Visit)(int v){
    VisitFunc=Visit;
    for(v=0;v<G.vexnum;++v) visited[v]=FALSE;
    for(v=0;v<G.vexnum;++v) 
      if(!visited[w])  DFS(G,v);     
}

void DFS(Graph G,int v){
  visited[v]=TRUE;VisitFunc(v);
  for(w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G,v,w))
     if(!visited[w]) DFS(G,w);     
}

#endif

#include<iostream>
#include<queue>
using namespace std;

typedef char ElemType;
typedef struct tree_node{
  ElemType data;
  tree_node * l;
  tree_node * r;
}*Tree,*tree_node_ptr;

void printOut(tree_node_ptr n){
 cout << n->data; 
}

void preOrder(Tree t, void (* visit)(tree_node_ptr n)){
  if(t){
   visit(t);
   preOrder(t->l,visit);
   preOrder(t->r,visit);
  } 
}

char str[] ="AB#CD###E#F##";

void creatTree(Tree *t,char ** str){
  if(**str=='\0')return;
  if(**str=='#'){ *t=NULL; (*str)+=1;}
  else{
    *t = new tree_node();
    (*t)->data = **str;
    (*t)->l=(*t)->r=NULL;
    (*str)+=1;
    creatTree( &((*t)->l),str);
    creatTree( &((*t)->r),str);
  }
}

void handleTree(Tree t, void (*visit)(tree_node_ptr n)){
  queue<Tree> q;
  if(t){q.push(t);}
  while(!q.empty()){
   visit(q.front());
   if(q.front()->l)q.push(q.front()->l);
   if(q.front()->r)q.push(q.front()->r);
   q.pop();
  }
}

int main(){
 char * s = str;
 Tree t=NULL;
 creatTree(&t, &s);
 preOrder(t, printOut);
 cout<<endl;
 handleTree(t,printOut);
 system("PAUSE"); 
}

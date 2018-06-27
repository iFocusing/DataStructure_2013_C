#include<iostream>
#include"que.cpp"
using namespace std;

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
  MyQueueNode * temp = NULL;
  myQueue q;
  if(t){
    temp = new MyQueueNode();
    temp->data = t;
    enQueue(q,*temp);
  }
  while(!isEmpty(q)){
    visit(q.front->data);
    if(q.front->data->l){
      temp = new MyQueueNode();
      temp->data = q.front->data->l;
      enQueue(q,*temp);
    }
    if(q.front->data->r){
      temp = new MyQueueNode();
      temp->data = q.front->data->r;
      enQueue(q,*temp);
    }
    deQueue(q);
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

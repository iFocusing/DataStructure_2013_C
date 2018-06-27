#include<iostream>
using namespace std;

typedef struct BiThrNode{
  char data;
  struct BiThrNode *lchild,*rchild;
  int ltag,rtag;
}BiThrNode,*BiThrTree;

BiThrTree pre = NULL;

void creatTree(BiThrTree * t, char **str){
  if((**str)=='\0')return;
  if((**str)=='#') {*t=NULL;(*str)++;}
  else{
     *t = new BiThrNode();
     (*t)->data = **str;
     (*t)->ltag = 0;
     (*t)->rtag = 0;
     (*str)+=1;
     creatTree( &((*t)->lchild),str);
     creatTree( &((*t)->rchild),str);
  }
}

void printOut(BiThrNode n){
  cout<<n.data; 
}

void preOrder(BiThrTree t, void(* visit)(BiThrNode n)){
  if(t){
    visit(*t);
    preOrder(t->lchild,visit);
    preOrder(t->rchild,visit);
  } 
}

void InThread(BiThrTree t){
  if(t){
    InThread(t->lchild);
    
    if(t->lchild==NULL){t->ltag = 1;t->lchild = pre;}
    if(pre->rchild == NULL){pre->rtag = 1; pre->rchild = t;}
    pre = t;
    InThread(t->rchild);
  }
}

void doThread(BiThrTree t , BiThrTree *Head){
  if(*Head==NULL)
    *Head = new BiThrNode();
  (*Head)->ltag = 0;
  (*Head)->rtag = 1;
  (*Head)->rchild = (*Head);
  if(!t)(*Head)->lchild = (*Head);
  else{
    (*Head)->lchild = t;
    pre = (*Head);
    InThread(t);
    pre->rtag = 1;
    pre->rchild = (*Head);
    (*Head)->rchild = pre;
  }
}

void InOrder( BiThrTree head , void (*visit)(BiThrNode n)){
  BiThrTree p = NULL;
  if(head){
     p = head->lchild;
     while(p!=head){
       while(p->ltag ==0 )p=p->lchild;
       visit(*p);
       while(p->rtag ==1 && p->rchild != head){
          p=p->rchild;
          visit(*p);
        }
       p= p->rchild;
    }
  }
}

void revserseInOrder(BiThrTree head , void (*visit)(BiThrNode n)){
  BiThrTree p = NULL;
  if(head){
     p = head->rchild;
     while(p!=head){
       while(p->rtag ==0 )p=p->rchild;
       visit(*p);
       while(p->ltag ==1 && p->lchild != head){
          p=p->lchild;
          visit(*p);
        }
       p= p->lchild;
    }
  }
}


int main(){
  char str[] = "AB#CD###E#F##"; 
  BiThrTree t = NULL;
  char *s = str;
  creatTree( &t,&s);
  preOrder(t, printOut);
  cout<<endl;
  
  BiThrTree head;
  doThread(t, &head);
  InOrder( head, printOut);
  cout<<endl;
  revserseInOrder( head, printOut);
  system("PAUSE");
}

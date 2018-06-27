#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct Node * Node_ptr;
typedef struct Node{
   ElemType data;
   Node_ptr left;
   Node_ptr right;
}node,*Tree;

void visit( Node_ptr n){
   //cout<<"hello"<<endl;
   cout<<n->data;
}

void preOrder(Tree t, void(* visit )(Node_ptr)){
 if(t){
    //cout<<"not empty"<<endl;
   visit(t);
   preOrder(t->left,visit);
   preOrder(t->right,visit);
  } else{
   //cout<<"empty"<<endl; 
  }
}
void inOrder(Tree t, void(* visit )(Node_ptr)){
 if(t){
   inOrder(t->left,visit);
   visit(t);
   inOrder(t->right,visit);
  } 
}
void postOrder(Tree t, void(* visit )(Node_ptr)){
 if(t){
   postOrder(t->left,visit);
   postOrder(t->right,visit);
   visit(t);
  } 
}

void depth(Tree t, int level, int *height){
  if(t){
   if(level>*height) *height= level; 
   depth(t->left,level+1,height);
   depth(t->right,level+1,height);
  } 
}

void leves_num(Tree t, int &count){
  if(t){
   if(t->left==NULL && t->right==NULL) count++;
   leves_num(t->left,count);
   leves_num(t->right,count);
  }
}

void creat(Tree &t, char **str){
  if( **str=='#'){
    t=NULL;
    cout<<"creat #"<<**str<<endl;
    *str++;
    
  }else if(**str!='\0'){
    cout<<"creat x"<<**str<<endl;
    t = new node();
    t->data = **str;
    creat(t->left,&++*str);
    creat(t->right,&++*str);
 }
}

int main(){
  Tree t = NULL;
  int h =0;
  char *str = "AB#CD###E#F##";
  creat(t, &str);
  preOrder(t,visit);
  cout<<endl;
  inOrder(t,visit);
    cout<<endl;
  postOrder(t,visit);
  depth(t,0,&h);
  cout<<"height:"<<h<<endl;
  h=0;
  leves_num(t,h);
  cout<<"num:"<<h<<endl;
  system("PAUSE");
}

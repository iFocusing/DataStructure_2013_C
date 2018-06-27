#include <iostream>
using namespace std;

typedef struct TreeNode{
  int data ;
  struct TreeNode * left;
  struct TreeNode *right;
}TreeNode,*Tree;

Tree  Find(Tree t, int x){
   if(t){
      if(x<t->data)
        return Find(t->left,x);
      else if(x>t->data)
        return Find(t->right,x);
      else return t;
    }else
    return NULL;   
}

Tree FindMax(Tree t){
  if(t){
    while(t->right){
      t=t->right; 
    }
    return t;
  }else
    return NULL; 
}

Tree FindMin(Tree t){
  if(t){
    while(t->left){
      t = t->left; 
    }
    return t;
  }else
    return NULL; 
}

void Insert( Tree *t , int x){
  if(!*t){
     (*t) = new TreeNode();
     (*t)->data = x;
     (*t)->left = (*t)->right = NULL;
  } else{
   if(x<(*t)->data) Insert(&((*t)->left),x) ;
   else if(x>(*t)->data) Insert(&((*t)->right),x) ;
  }
}

void printOut(TreeNode n){
  cout<<n.data<<" "; 
}

void InOrder(Tree t, void(*visit)(TreeNode n)){
  if(t){
    InOrder(t->left,visit);
    visit(*t);
    InOrder(t->right,visit);
  } 
}

void Delete(Tree *t, int x){
  Tree temp = NULL;
  if(*t){
    if(x<(*t)->data){
      Delete(&(*t)->left,x) ;
    }else if(x>(*t)->data){
      Delete(&(*t)->right,x);  
    }else{
     if( (*t)->left ==NULL && (*t)->right == NULL){
        delete (*t);
        *t = NULL;
     }else if( (*t)->left !=NULL && (*t)->right ==NULL){
        temp =(*t)->left;
        (*t)->data = temp->data;
        (*t)->left = temp->left;
        (*t)->right = temp->right;
        delete(temp);
     }else if( (*t)->right !=NULL && (*t)->left ==NULL){
        temp =(*t)->right;
        (*t)->data = temp->data;
        (*t)->left = temp->left;
        (*t)->right = temp->right;
        delete(temp);
     }else{
        (*t)->data = FindMin((*t)->right)->data;
        Delete(&(*t)->right,   (*t)->data); 
     } 
    }
  } 
}

int main(){
  int num[1000]={50,30,40,80,20,36,90,40,38};
  int n = 9;
  Tree temp = NULL;
  Tree t = NULL;
  for(int i = 0 ;i< 9;i++){
    Insert(&t,num[i]); 
  }
  InOrder(t,printOut);
  cout<<endl;
  temp = FindMax(t);
  if(temp){
    cout<<"max:"<<temp->data;
  }
  temp = FindMin(t);
  cout<<endl;
  if(temp){
    cout<<"min:"<<temp->data; 
  }
  cout<<endl;
  for(int i = 0 ;i< 9;i++){
  Delete (&t,num[i]);
  InOrder(t,printOut);cout<<endl;
  }

  system("PAUSE"); 
}






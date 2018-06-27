#include<iostream>
using namespace std;
typedef struct TreeNode{
  int data ;
  struct TreeNode * left;
  struct TreeNode * right;
  int height;
  int del;
}TreeNode,*Tree;

int GetHeight(Tree t){
  if(t){
    return t->height; 
  } else{
    return -1; 
  }
}

int MaxHeight(Tree t1,Tree t2){
  return GetHeight(t1)>GetHeight(t1)?GetHeight(t1):GetHeight(t2); 
}

void RoateLeft(Tree *t){
  Tree temp = NULL;
  if(*t){
    temp = *t;
    *t = temp->right;
    temp->right = (*t)->left;
    (*t)->left = temp;
  } 
}

void RoateRight(Tree *t){
  Tree temp = NULL;
  if(*t){
    temp = *t;
    *t = temp->left;
    temp->left = (*t)->right;
    (*t)->right = temp; 
  } 
}

void RoateLeftRight(Tree *t){
  RoateLeft(&(*t)->left);
  RoateRight(t); 
}

void RoateRightLeft(Tree *t){
  RoateRight(&(*t)->right);
  RoateLeft(t); 
}

void Insert( Tree *t , int x){
  if(!*t) {
    *t = new TreeNode();
    (*t)->left = (*t)->right = NULL;
    (*t)->data = x;
    (*t)->height = 0;
    (*t)->del = 0;
  }else{
    if(x<(*t)->data){
      Insert(&(*t)->left,x);
      if(GetHeight((*t)->left) - GetHeight((*t)->right) ==2){
        if((*t)->left->right == NULL){
          RoateRight(t); 
        } else{
          RoateLeftRight(t); 
        }
      } 
    }else if(x>(*t)->data){
      Insert(&(*t)->right,x);
      if(GetHeight((*t)->right)- GetHeight((*t)->left)==2){
        if((*t)->right->left ==NULL){
          RoateLeft(t); 
        }else{
          RoateRightLeft(t); 
        }
      }
    }else{
      if((*t)->del )
        (*t)->del = 0; 
    }
    
    (*t)->height = MaxHeight((*t)->left,(*t)->right)+1;
  }
  
  
}

void printOut(TreeNode n){
  if(!n.del ){
    cout<<n.data<<" "; 
  }
}

void InOrder(Tree t, void (*visit)(TreeNode n)){
  if(t){
    InOrder(t->left,visit);
    visit(*t);
    InOrder(t->right,visit); 
  } 
}

void Delete ( Tree *t ,int x){
  if(*t){
    if(x<(*t)->data)
      Delete(&(*t)->left,x);
    else if(x>(*t)->data)
      Delete(&(*t)->right,x);
    else{
      (*t)->del = 1; 
    }  
  }
   
}

int main(){
  int num[] = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
  int n = 16;
  Tree t = NULL;
  for(int i = 0;i<16;i++){
    Insert (&t,num[i]);
    InOrder(t,printOut);
    cout<<endl;
  } 
  for(int i = 0 ;i<16;i++){
    Delete(&t,num[i]);
    InOrder(t,printOut);
    cout<<endl; 
  }
  system("PAUSE");
}





#include <stdio.h>
#include <stdlib.h>
#include "constant.h"
#include "BiTree.h"

int LeafCount(BiTree bt) 
{ 
    //------------------------------------- 
    // TODO (#1#):计算二叉树中叶子结点的个数 
    int lleaf,rleaf; 
    if(bt->lchild==0 && bt->rchild==0) 
        return 1; 
    else 
    { 
lleaf=LeafCount(bt->lchild); 
rleaf=LeafCount(bt->rchild); 
        return lleaf+rleaf; 
    } 
    return 0; 
    //------------------------------------- 
} 


int BiTree_Sim(BiTree b1,BiTree b2)/*判断两个树是否相似*/
{
 if(b1==NULL&&b2==NULL)
  return 1;  /*两个为空子树、相似*/
 else if(b1==NULL||b2==NULL)
  return 0;  /*两个中某一个为空子树、不相似*/
 else
 {
  return(BiTree_Sim(b1->lchild,b2->lchild)&&BiTree_Sim(b1->rchild,b2->rchild));
 }
}

void BiTree_Revolute(BiTree T){
   BiTree b;
   b=T->lchild;T->lchild=T->rchild;T->rchild=b;
   if(T->lchild)   BiTree_Revolute(T->lchild); 
   if(T->rchild)   BiTree_Revolute(T->rchild); 
}

int Get_Sub_Depth(BiTree T,int x){
   if(T->data==x){
      printf("%d\n",Deapth(T));
      return ;           
   }    
   else{
      if(T->lchild)   Get_Sub_Depth(T->lchild,x);
      if(T->rchild)   Get_Sub_Depth(T->rchild,x);
   }
}
int main(int argc, char *argv[])
{
  BiTree T=0,T1=0;
  char c,s;
  int t;
  printf("Creat BinTree;\nInput preorder:\n");
  fflush(stdin);
  if( CreateBiTree(&T)==ERROR ) { 
        printf("ERROR: call CreateBiTree\n"); 
        system("pause"); 
        exit(1); 
    } 
     printf("\n二叉树的深度: %d\n", Deapth(T)); 
     printf("\n二叉树中叶子结点的个数: %d\n", LeafCount(T));
     printf("Print BinTree Preorder:\n");
     PreOrderTraverse(T,PrintElement);
     printf("\n");
     printf("Print BinTree Inorder:\n");
     InOrderTraverse(T,PrintElement);
     printf("\n");
     printf("Print BinTree Postorder:\n");
     PostOrderTraverse(T,PrintElement);
     printf("\n*********************\n");
     
     
     printf("Creat Another BinTree;\nInput preorder:\n");
     fflush(stdin);
     if( CreateBiTree(&T1)==ERROR ) { 
        printf("ERROR: call CreateBiTree\n"); 
        system("pause"); 
        exit(1); 
     } 
     printf("\n二叉树的深度: %d\n", Deapth(T1)); 
     printf("\n二叉树中叶子结点的个数: %d\n", LeafCount(T1));
     printf("Print BinTree Preorder:\n");
     PreOrderTraverse(T1,PrintElement);
     printf("\n");
     printf("Print BinTree Inorder:\n");
     InOrderTraverse(T1,PrintElement);
     printf("\n");
     printf("Print BinTree Postorder:\n");
     PostOrderTraverse(T1,PrintElement);
     printf("\n*********************\n\n");
     t=BiTree_Sim(T,T1);
     if(t)
     printf("T和T1相似！\n\n");
     else
     printf("T和T1不相似！\n\n");
     printf("交换第一个二叉树的左右子树得到新的二叉树的先序遍历：\n");
     BiTree_Revolute(T);
     printf("Print BinTree Preorder:\n");
     PreOrderTraverse(T,PrintElement);
     printf("\n");    
     printf("求第一个二叉树中以元素值为s的节点为根的子树的深度：\n请输入s：");
     scanf("%c",&s);
     printf("深度为："); 
     Get_Sub_Depth(T,s); 
     
     
     getchar(); getchar(); getchar(); 
  system("PAUSE");	
  return 0;
}

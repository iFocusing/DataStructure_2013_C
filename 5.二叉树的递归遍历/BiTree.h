#ifndef _BITREE_H
#define _BITREE_H
#include"constant.h"
#include<stdio.h>

typedef struct BiTNode{
   TElemType data;
   struct BiTNode *lchild,*rchild;        
}BiTNode,*BiTree;

Status CreateBiTree(BiTree *T) 
{ 
    char ch; 
    scanf("%c",&ch); 
    if( ch==' ' ) 
(*T )=NULL; 
    else {  
(*T )= (BiTree)malloc(sizeof(BiTNode)); 
        (*T)->data = ch;  
        CreateBiTree((&(*T)->lchild)); 
        CreateBiTree((&(*T)->rchild)); 
    } 
    return OK; 
} 

Status PrintElement(TElemType e){
    printf("%c  ",e);
    return OK;      
}

Status PreOrderTraverse(BiTree T,Status(*Visit)(TElemType e)){
       fflush(stdin);
    if(T){
        if(PrintElement(T->data)){
            if(PreOrderTraverse(T->lchild,Visit)){
                 if(PreOrderTraverse(T->rchild,Visit))
                 return OK;                                             
            }                      
        }else return ERROR;
    }else return OK;        
}

Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType e)){
       fflush(stdin);
    if(T){
        if(InOrderTraverse(T->lchild,Visit)){
            if(PrintElement(T->data)){
                 if(InOrderTraverse(T->rchild,Visit))
                 return OK;                                             
            }                      
        }else return ERROR;
    }else return OK;        
}

Status PostOrderTraverse(BiTree T,Status(*Visit)(TElemType e)){
       fflush(stdin);
    if(T){
        if(PostOrderTraverse(T->lchild,Visit)){
            if(PostOrderTraverse(T->rchild,Visit)){
                 if(PrintElement(T->data))
                 return OK;                                             
            }                      
        }else return ERROR;
    }else return OK;        
}

int Deapth(BiTree bt) 
{ 
    //------------------------------------- 
    // TODO (#1#):计算二叉树的深度 
    int ldeapth,rdeapth; 
    if(bt==0) 
        return 0; 
    else 
    { 
ldeapth=Deapth(bt->lchild); 
rdeapth=Deapth(bt->rchild); 
        return(ldeapth>rdeapth? ldeapth:rdeapth)+1; 
    } 
    return 0; 
    //------------------------------------- 
} 



#endif

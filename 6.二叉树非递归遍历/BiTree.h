#ifndef _BITREE_H
#define _BITREE_H
#include<stdio.h>
#include"constant.h"
#include"Stack.h"
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;    
}BiTNode,*BiTree;

Status CreateBiTree(BiTree *T)
{
   char ch;
   scanf("%c",&ch);
   if(ch==' ')  (*T)=NULL;
   else {
     (*T)=(BiTree)malloc(sizeof(BiTNode));
     (*T)->data=ch;
     CreateBiTree(&((*T)->lchild));
     CreateBiTree(&((*T)->rchild));     
   }       
   return OK;
}

Status PrintElement(TElemType e){
   printf("%c  ",e);
   return OK;       
}

Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType e)){
   printf("*******\n");
   Stack S;
   BiTree p=0;
   InitStack(&S); Push(&S,T);
   while(!StackEmpty(&S)){
       while(GetTop(&S,p)&&p) Push(&S,p->lchild);
       Pop(&S,p);   
       if(!StackEmpty(&S))
       {
        Pop(&S,p);                   
       if(!Visit(p->data)) return ERROR;
       Push(&S,p->rchild);   
       }                  
   }    
   return OK;   
}
#endif

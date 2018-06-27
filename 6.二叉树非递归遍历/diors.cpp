#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100;
#define STACKINCREMENT  10;
typedef struct{
        SElemType  *base;
        SElemType  *top;
        int  stacksize;
        }//SqStack;
typedef char TElemType;
typedef int Status;


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct BiTNode{
        TElemType    data;
        struct BiTNode  *lchild,*rchild;
        }BiTNode,*BiTree;
        
Status CreateBiTree(Bitree &T){
               scanf("%C",&ch);
               if(ch==' ')T=NULL;
              else{
                    if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))exit(OVERFLOW);
                    T->data=ch;
                    CreateBiTree(T->lchild);
                    CreateBiTree(T->rchild);
                    }
                    return OK;
                    }//CreateBiTree
Status PrintElement(TElemType e){
       printf("%d",e);
       return OK;
       }
               
Status PreOrderTraverse(BiTree T,Status(*Visit)(TElemType e)){
       //���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú�����
       //�������������T�ķǵݹ��㷨����ÿ������Ԫ�ص��ú���Visit.
       InitStack(S); p=T;
       while(p||!StackEmpty(S)){
                                if(p){Push(S,p);if(!Visit(p->data)) return ERROR; p=p->lchild;} //��ָ���ջ������������
                                else{     //��ָ����ջ�����ʸ���㣬���������� 
                                Pop(S,p);
                                p=p->rchild;
                                }//else
                                }//while
                                return OK;
                                }//PreOrderTraverse
                                
Status InOrderTraverse(Bitree T,Status(*Visit)(TElemType e)){
       InitStack(S); p=T;
       while(p||!StackEmpty(S)){
                                if(p){Push(S,p);p=p->lchild;}//��ָ���ջ������������
                                else{       //��ָ����ջ�����ʸ��ڵ㣬����������
                                Pop(S,p);if(!Visit(p->data))return ERROR;
                                p=p->rchild;
                                }//else
                                }//While
                                return OK;
                                }//InOrderTraverse
                                
//Status PostOrderTraverse(BiTree T,Status(*Visit(p->data))return ERROR;
//P=P-> 
int main {
    BiTree T;
    PreOrderTraverse(T,PrintElement);
    InOrderTraverse(T,PrintElement);
    

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
typedef struct BiTNode{
	char data;
	BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T)//建树，按先序顺序输入节点
{
	char ch;
	scanf("%c",&ch);
	if(ch==' ')
	{
		T=NULL;
		return;
	}
	else
	{
		T=(BiTree)malloc(sizeof(BiTNode));
		if(!T)
			exit(1);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
void InOrderTraverse(BiTree T)//非递归中序遍历
{
	
	stack<BiTree> Stack;
	if(!T)
	{
		printf("空树！\n");
		return;
	}
	
	while(T || !Stack.empty())
	{
		while(T)
		{
			Stack.push(T);
			T=T->lchild;
		}
		T=Stack.top();
		Stack.pop();
		printf("%c",T->data);
		T=T->rchild;
	}                                                                                                                                   
}



void PreOrderTraverse(BiTree T)//非递归先序遍历
{
	
	stack<BiTree> Stack;
	if(!T)
	{
		printf("空树！\n");
		return;
	}
	while(T || !Stack.empty())
	{
		while(T)
		{
			Stack.push(T);
			printf("%c",T->data);
			T=T->lchild;
		}
		T=Stack.top();
		Stack.pop();		
	         T=T->rchild;		
	}                                                                                                                                   
}
void PostOrderTraverse(BiTree T)//非递归后序遍历,用一个标记标记右子树是否访问过
{
	int flag[20];
	BiTree T1;
	stack<BiTree> Stack;
	while(T)
	{
		Stack.push(T);
		flag[Stack.size()]=0;
		T=T->lchild;
	}
	while(!Stack.empty())
	{
		T=Stack.top();			
		while(T->rchild&&flag[Stack.size()]==0)
		{
 	        T=T->rchild;
			flag[Stack.size()]=1;
		
			while(T)
			{
				Stack.push(T);
				flag[Stack.size()]=0;
				T1=T;
			    T=T->lchild;
			}
			T=T1;
		}
		T=Stack.top();
		printf("%c",T->data);
    	Stack.pop();
	}                                                                                                                                   
}

int main()
{
  
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T);
	printf("\n");
    InOrderTraverse(T);
	printf("\n");
    PostOrderTraverse(T); 
	printf("\n");
	getchar();getchar();getchar();getchar();getchar();getchar();
}

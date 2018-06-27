#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define STACK_INIT_SIZE 10 //初始时给的空间  
#define STACK_INCREMENT_SIZE 10 //内存申请不足时扩展的大小

#define OVERFLOW 0  
#define FALSE 0  
#define TRUE 1  
#define ERROR 0  
#define OK  1  

typedef int SElemType;
typedef int Status;
typedef struct{
        int *base;
        int *top;
        int stacksize;
        }Sqstack;  //顺序栈 
//----The function prototype of basic operation----
Status InitStack(Sqstack &s);
Status DestroyStack(Sqstack &s);
Status ClearStack(Sqstack &s);
Status StackEmpty(Sqstack s);
int StackLength(Sqstack s);
Status GetTop(Sqstack &s,SElemType &e);
Status Push(Sqstack &s,SElemType e);
Status Pop(Sqstack &s,SElemType &e);
Status StackTraverse(Sqstack &s);
void conversion(Sqstack &s,int N);
//----Algorithm Description of basic operation---
Status InitStack(Sqstack &s)
{
   s.base=(SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
   if(!s.base) exit(OVERFLOW); //分配空间失败 
   s.top=s.base;
   s.stacksize=STACK_INIT_SIZE;
   return OK;     
}



Status StackEmpty(Sqstack s)
{
    if(s.top==s.base)
       return TRUE;
    else return FALSE;
}


int StackLength(Sqstack &s)
{
    printf("\n%d\n",s.top-s.base);    
}

Status GetTop(Sqstack &s,SElemType &e)
{
    if (s.top == s.base) //如果空栈，报错  
       return ERROR;  
    else {
         e=*(s.top-1);   //??????????? 为什么要减一； 
         return OK;
         }
}

Status DestroyStack(Sqstack &s)
{
    free(s.base);
    s.base=NULL;
    return OK;    
}

Status ClearStack(Sqstack &s)
{
    s.top=s.base;
    return OK;       
}


Status Push(Sqstack &s,SElemType e)
{
    if(s.top-s.base>=s.stacksize)
    {
       s.base=(SElemType*)realloc(s.base,(s.stacksize+STACK_INCREMENT_SIZE)*sizeof(SElemType));
       if(!s.base) exit(OVERFLOW);
       
       s.top=s.base+s.stacksize;
       s.stacksize+=STACK_INCREMENT_SIZE;                        
    }//栈满，追加空间       
    *s.top++=e;
    return OK;
}

Status Pop(Sqstack &s,SElemType &e)
{
   if(s.top==s.base) return ERROR;
   e=*--s.top;  //???这个地方栈顶减一，是减一后的那个值給e还是减一前的那个值給e 
   return OK;       
}


Status visit(SElemType e)
{
   printf("e=%d\n",e);
   return OK;
}

Status StackTraverse(Sqstack &s, Status (*visit)(SElemType))
{
    SElemType *p;
    if (s.top == s.base)
       return ERROR;
    p=s.top;                        //p指向栈顶
    while( p>s.base )
      visit(* --p);      //通过循环对栈的元素遍历
    return OK;  
}


  
void conversion(Sqstack &s,int N)
{
    while(N)
    {
        Push(s,N%8);
        N=N/8;
    }
    while(!StackEmpty(s))
    {
        SElemType e;
        Pop(s,e);
        printf("%d",e);
    }
}               

int main()
{
    int N;
    printf("请输入一个要转换的数字："); 
    scanf("%d",&N);
   Sqstack s;
   InitStack(s);
   conversion(s,N);
   getchar();getchar();
}

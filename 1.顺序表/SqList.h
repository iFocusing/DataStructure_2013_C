#ifndef _SQLIST_H
#define _SQLIST_H

#include<stdlib.h>
#include "constant.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct{
        ElemType *elem;
        int length;
        int listsize;
        }SqList;
//----Algorithm Description of basic operation---
Status InitList(SqList *L){
   L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!L->elem) exit(OVERFLOW);
   L->length=0;  
   L->listsize=LIST_INIT_SIZE;
   return OK;    
}

Status InputList(SqList*L,int n){
   int i=0;
   for(;i<n;i++)
   {
      scanf("%d",&L->elem+i);
      L->length++;       
   }       
   return OK;
}

Status PrintList(SqList *L)
{
    int i;
    i=0;
    while(i<L->length)
    {
        printf("%d",L->elem+i);
        i++;
    }
    printf("\n");
    return OK;
}

int ListLength(SqList *L,int len){
   len=L->length;
   if(len==0)
   {
      printf("is a emptylist.");
      return ERROR;          
   }
   return len;    
}

Status GetElem(SqList *L,int i,ElemType *e){
   if((i<1)||(i>L->length))
      return ERROR;
   *e=*(L->elem+i-1);
   return OK;      
}

Status PriorElem(SqList *L,ElemType cur_e,ElemType pre_e){
    int *p=L->elem;
    if(cur_e==*p)
    {
       printf("is the first!\n");
       return INFEASIBLE;             
    }
    else if(cur_e<=L->length)
    pre_e=*(L->elem+cur_e-2);
    return OK;       
}

Status NextElem(SqList *L,ElemType cur_e,ElemType next_e){
    int *p = L->elem;  
  int i = 0;  
  while( (i < L->length) &&(cur_e <= L->length))  
  {  
    i++;  
    p = L->elem + i;  
  }  
  if(next_e == *p)  
  {  
    printf("is the last one!");  
    return INFEASIBLE;  
  }  
  next_e = *(L->elem + cur_e);  
  return OK;        
}

Status GetLocation(SqList *L,ElemType e,int *loction)  
{  
  int i = 0;  
  int *p = L->elem;  
  while(e!= *p)  
  {  
    i++;  
    p++;  
  }  
  *loction=i + 1;  
    return OK;         
}

Status ListInsert(SqList *L,int i,ElemType e){
       ElemType *newbase,*p,*q;
    if(i<1||i>L->length+1) return ERROR;
    if(L->length>=L->listsize){
        newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)exit(OVERFLOW);
        L->elem=newbase;
        L->listsize+=LISTINCREMENT;                         
    }       
    q=L->elem+i-1;
    for(p=L->elem+L->length-1;p<=q;--p)   
          *(p+1)=*p;
    *q=e;
    ++L->length;
    return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e){
       ElemType *p,*q;
   if((i<1)||(i>L->length))  return ERROR;
   p=&(L->elem[i-1]);
   *e=*p;
   q=L->elem+L->length-1;
   for(++p;p<=q;++p)
   *(p-1)=*p;   
   --L->length;
   return OK;    
}


Status ListEmpty(SqList *L){
    if(L->length==0) 
        return OK; 
    else 
        return ERROR;        
}

Status ClearList(SqList *L){
     L->length=0;
     return OK;       
}

Status DestroyList(SqList *L){
   free(L->elem);
   L->elem=NULL;
   L->length=0;
   L->listsize=0;       
}


Status mergeList(SqList *La,SqList *Lb,SqList *Lc)  
{  
    ElemType *pa = La->elem;  
    ElemType *pb = Lb->elem;  
    Lc->listsize = Lc->length = La->length+Lb->length;  
    ElemType *pc = Lc->elem = (ElemType *)malloc(Lc->listsize*sizeof(ElemType));  
    if(! Lc->elem) exit(OVERFLOW);  
    ElemType *pa_last = La->elem + La->length - 1;  
    ElemType *pb_last = Lb->elem + Lb->length - 1;  
    while(pa<=pa_last&&pb<=pb_last)  
    {  
        if(*pa <= *pb) *pc++ = *pa++;  
        else *pc++ = *pb++;  
    }  
    while(pa<=pa_last) *pc++ = *pa++;  
    while(pb<=pb_last) *pc++ = *pb++;  
    return OK;
} 

#endif

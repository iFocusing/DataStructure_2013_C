#ifndef _SQQUEUE_H
#define _SQQUEUE_H

#include<stdlib.h>
#include "constant.h"
#define MAXQSIZE 100
typedef struct{
        QElemType *base;
        int front;
        int rear;
        }SqQueue;
//---The function prototype of basic operation  ---
//----Algorithm Description of basic operation---
Status InitQueue(SqQueue *Q){
   Q->base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
   if(!Q->base) exit(OVERFLOW);
   Q->front=Q->rear=0;   
   return OK;    
}

int QueueLength(SqQueue Q){
   return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;    
}

Status EnQueue(SqQueue *Q,QElemType e){
   if((Q->rear+1)%MAXQSIZE==Q->front)  return ERROR;
   Q->base[Q->rear]=e;
   Q->rear=(Q->rear+1)%MAXQSIZE;
   return OK;      
}

Status DeQueue(SqQueue *Q,QElemType *e){
    if(Q->front==Q->rear) return ERROR;
    *e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXQSIZE;
    return OK;       
}

Status DestroyQueue(SqQueue *Q){
    free(Q->base);
    Q->base=NULL;
    return OK;        
}

Status ClearQueue(SqQueue *Q){
    Q->base=0; 
    Q->rear=0; 
    return OK;         
}

Status QueueEmpty(SqQueue *Q){
    if(Q->front==Q->rear) 
        return OK; 
    else 
        return ERROR;        
}

Status GetHead(SqQueue *Q,QElemType *e){
     if(Q->rear==Q->front) 
        return ERROR; 
    *e=Q->base[Q->front]; 
    return OK;       
}


#endif

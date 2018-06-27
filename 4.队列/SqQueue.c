#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h" 
#include "constant.h"


int main(int argc, char *argv[])
{
    SqQueue *Q; //循环队列  
    Q->base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
    int x;  
    InitQueue(Q);
    printf("数据元素进队列,以0结束:"); 
    scanf("%d",&x); 
   while(x!=0){ 
      EnQueue(Q,x); 
      scanf("%d",&x); 
   } 
   printf("\n队列元素的个数:"); 
   printf("%d",QueueLength(*Q)); 
   
   printf("\n头元素是："); 
   if(!QueueEmpty(Q)){ 
     if(GetHead(Q,&x)==OK) 
      printf("%d",x); 
   } 
 
   printf("\n出队列,先进先出"); 
      if( DeQueue(Q,&x)==OK) 
         printf("%d",x); 
   printf("\n此时的队头是："); 
   if(!QueueEmpty(Q)){ 
     if(GetHead(Q,&x)==OK) 
      printf("%d\n",x); 
   } 
system("PAUSE");	
return 0;
}

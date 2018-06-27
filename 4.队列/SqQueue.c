#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h" 
#include "constant.h"


int main(int argc, char *argv[])
{
    SqQueue *Q; //ѭ������  
    Q->base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
    int x;  
    InitQueue(Q);
    printf("����Ԫ�ؽ�����,��0����:"); 
    scanf("%d",&x); 
   while(x!=0){ 
      EnQueue(Q,x); 
      scanf("%d",&x); 
   } 
   printf("\n����Ԫ�صĸ���:"); 
   printf("%d",QueueLength(*Q)); 
   
   printf("\nͷԪ���ǣ�"); 
   if(!QueueEmpty(Q)){ 
     if(GetHead(Q,&x)==OK) 
      printf("%d",x); 
   } 
 
   printf("\n������,�Ƚ��ȳ�"); 
      if( DeQueue(Q,&x)==OK) 
         printf("%d",x); 
   printf("\n��ʱ�Ķ�ͷ�ǣ�"); 
   if(!QueueEmpty(Q)){ 
     if(GetHead(Q,&x)==OK) 
      printf("%d\n",x); 
   } 
system("PAUSE");	
return 0;
}

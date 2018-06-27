#include <stdio.h>
#include <stdlib.h>
#include"SqList.h"

int main(int argc, char *argv[])
{
   SqList la,lb,lc;  
   la.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   lb.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   lc.elem = (ElemType *)malloc(2*LIST_INIT_SIZE*sizeof(ElemType));
    int n;  
    InitList(&la);InitList(&lb);  
    printf("请输入链La的元素个数：");  
    scanf("%d",&n);  
    InputList(&la,n); 
    printf("请输入链Lb的元素个数：");  
    scanf("%d",&n);  
    InputList(&lb,n);  
    PrintList(&lb); 
    mergeList(&la,&lb,&lc);  
    PrintList(&lc);  
    return 0;  
  system("PAUSE");	
  return 0;
}

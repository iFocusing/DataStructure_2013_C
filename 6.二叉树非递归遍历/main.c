#include <stdio.h>
#include <stdlib.h>
#include"constant.h"
#include"BiTree.h"
#include"Stack.h" 

int main(int argc, char *argv[])
{
  BiTree T=0;
  printf("Creat BinTree;\nInput preorder:\n");
  fflush(stdin);
  if( CreateBiTree(&T)==ERROR ) { 
        printf("ERROR: call CreateBiTree\n"); 
        system("pause"); 
        exit(1); 
    } 
   printf("Print BinTree Inorder:\n");
     InOrderTraverse(T,PrintElement);
     printf("\n");
  system("PAUSE");	
  return 0;
}

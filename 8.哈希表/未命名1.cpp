#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//-----开放地址哈希表的存储结构----
typedef int ElemType;
typedef int Status;
int hashsize[]={40,50,60,300,600}
typedef struct{
   ElemType *elem;
   int count;
   intsizeindex;        
}HashTable;

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1



//-----求哈希地址的哈希函数-----
int Hash(KeyType K){
    int p;
    p=K mod 37;
    return p;    
} 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//-----���ŵ�ַ��ϣ��Ĵ洢�ṹ----
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



//-----���ϣ��ַ�Ĺ�ϣ����-----
int Hash(KeyType K){
    int p;
    p=K mod 37;
    return p;    
} 

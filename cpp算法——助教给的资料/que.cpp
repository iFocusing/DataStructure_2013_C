#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct tree_node{
  ElemType data;
  tree_node * l;
  tree_node * r;
}*Tree,*tree_node_ptr;


typedef struct MyQueueNode{
 Tree data;
 struct MyQueueNode * next; 
 MyQueueNode(){data = 0;next = NULL;}
}* myQueueNode_ptr;
struct myQueue{
  myQueueNode_ptr front;
  myQueueNode_ptr rear;
  int length;
  myQueue(){front = NULL;rear= NULL; length =0;}
};

int isEmpty(myQueue q){
  return q.length ==0; 
}
/*没有测试，未使用到    
int getFront(myQueue q , MyQueueNode &x){
  if(q.length<=0)return 0;
  else{
   x = *q.front; 
  }
}

int getRear(myQueue q , MyQueueNode &x){
  if(q.length<=0)return 0;
  else{
   x = *q.rear; 
  }
}
*/
void enQueue(myQueue &q,MyQueueNode &x){
  myQueueNode_ptr temp = NULL;
  temp = new MyQueueNode();
  temp->data = x.data;
  if(q.length==0){
    q.front = q.rear = temp;
  }else{
    q.rear->next = temp;
    q.rear = temp;
    
  }
  q.length+=1;
}

void deQueue(myQueue &q){
  myQueueNode_ptr temp = NULL;
  if(q.length<=0)return;
  else if(q.length==1){
    temp = q.front;
    delete temp;
    q.front = q.rear = NULL;
  }else{
    temp = q.front;
    q.front = temp->next;
    delete temp;
  }
  q.length-=1;
}

int getLength(myQueue &q){
   return q.length;  
}
/*  
void traverse(myQueue q){
  myQueueNode_ptr p = q.front;
  int i=1;
  while(i<=q.length){
    cout<<p->data;
    p=p->next;
    i++;
  }
  
  */

}

/* 测试驱动，当队列中数据为char时，调试 
int main(){
   myQueue q;
   MyQueueNode * temp = NULL;
   for(int i =0;i<26;i++){
      temp = new MyQueueNode();
      temp->data = 'a'+i;
      enQueue(q, *temp);  
   }
   cout<<getLength(q)<<endl;
   traverse(q);
   cout<<endl;
   
   for(int i =0;i<11;i++){
      deQueue(q);
   }
   cout<<getLength(q)<<endl;
   for(int i=0;i<11;i++)
      cout<<' ';
   traverse(q);
   cout<<endl;
  
   system("PAUSE");
}
*/


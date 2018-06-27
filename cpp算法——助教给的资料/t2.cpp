#include <iostream>
using namespace std;
template <typename T>
class Node{
      private:
              Node<T> *next;
      public :
             T data;
             Node(const T &item,Node<T> * ptrnext = NULL);
             void insertAfter(Node<T> *p);
             Node<T> * deleteAfter();
             Node<T> * nextNode() const;
};

template <typename T>
Node<T> * Node<T>::nextNode() const
{
  return next;
}

template <typename T> 
Node<T>::Node(const T &item , Node<T> * ptrnext):data(item),next(ptrnext){}

template <typename T>
void Node<T>::insertAfter(Node<T> *p)
{
 p->next = next;
 next = p;
}

template <typename T>
Node<T> * Node<T>::deleteAfter()
{
  Node<T> * temp = NULL; 
  if(next != NULL){
    temp = nextNode();
    next = temp->next; 
  }
  return temp;
}

template <typename T>
Node<T> * getNode(const T &item,Node<T> * ptrnext = NULL){
   Node<T> * newNode ;
    newNode = new Node<T>(item,ptrnext);
    if(newNode == NULL){
      cerr<<"out of space"<<endl;
      exit(1);
    }     
    return newNode;
}

template <typename T>
void traverse(Node<T> * head)
{
 Node<T> * temp = head;
 while(temp!=NULL){
   cout<<temp->data<<endl;
   temp= temp->nextNode();
 }
}

int main(){
    Node<int> * H = getNode(0);
    H->insertAfter(getNode(1));
    H->insertAfter(getNode(2));
    H->insertAfter(getNode(3));
    H->insertAfter(getNode(4));
    H->insertAfter(getNode(5));
    traverse(H);
    
    cout<<"------------"<<endl;
    delete(H->deleteAfter());
traverse(H);
system("PAUSE");
}

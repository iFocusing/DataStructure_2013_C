#include <iostream>
using namespace std;
const int MaxSize= 50;
typedef int DataType;
class SeqList{
   private :
           int listItem[MaxSize];
           int length;
   public :
          SeqList();
          int getLength() const;
          DataType getData(int pos) const;
          void traverse() const;
          void insert(const DataType &itee);
          void deleteItem( const DataType &item);
          void clearList();        
};
DataType SeqList::getData(int pos) const{
  if(pos<0||pos>=length){
        cerr<<"error pos"<<endl;
        exit(1);
  }
  return listItem[pos];
}
int SeqList::getLength()  const
{
  return length;
}

void SeqList::insert(const DataType &item){
     if(length<MaxSize){
       listItem[length]=item;
       length++;
     }else{
       cerr<<"overflow"<<endl;
       exit(1);
     }
}

void SeqList::deleteItem(const DataType &item)
{
  int i =0;
  while(i<length&&listItem[i]!=item){
    i++;
  }
  if(i<length){
    while(i<length-1){
      listItem[i]=listItem[i+1];
      i++;
    }
    length--;
  }
}

void SeqList::clearList()
{
 length=0;
}

void SeqList::traverse() const
{
     int i=0;
     while(i<length){
       cout<<listItem[i]<<endl;
       i++;
     }
}

SeqList::SeqList():length(0){}

int main()
{
 SeqList s;
 s.insert(1);
 s.insert(2);
 s.insert(3);
 s.insert(4);
 s.insert(5);
 s.traverse();
 cout<<"------------"<<endl;
 s.deleteItem(3);
 s.traverse();
 system("PAUSE");
}


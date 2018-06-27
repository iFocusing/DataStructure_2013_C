#include<iostream>

#include<list>
#include<vector>

using namespace std;

//node是边的信息节点 
typedef struct node{
  int vex;
  int weight;
}node;

typedef list<node>  *head;

//gNode是顶点的信息节点 
typedef struct gNode{
  char info;  //顶点的数据信息 
  head first; //指向该顶点后的第一条边 
}gNode;

vector<gNode> vexs; //向量vexs存储了所有的顶点

void init(){//该方法将初始化一个图到 vexs向量中 
  gNode n ;               //建立一个顶点 
  n.info='A';             //顶点赋值信息 
  head h= new list<node>();//建立一个链表 
  n.first = h;         //链表存入顶点
  vexs.push_back(n);      //顶点存入向量vexs 
  ////////////////////////////
  node o ;
  o.vex=1;                 //给一个顶点的链表赋值 
  o.weight=6;
  h->push_front(o);
  o.vex=2;
  o.weight=1;
  h->push_front(o);
  o.vex=3;
  o.weight=5;
  h->push_front(o);
  /////////////////////////
} 

void init(char * ch){//该方法将初始化一个图到 vexs向量中 
  gNode n ;               //建立一个顶点 
  char * temp = ch;
  n.info=*temp;             //顶点赋值信息 
  temp++;
  head h= new list<node>();//建立一个链表 
  n.first = h;         //链表存入顶点
  vexs.push_back(n);      //顶点存入向量vexs 
  ////////////////////////////
  node o ;
  
  while(*temp ){
    o.vex=*temp-'0';           //先存的是节点值 
    temp++;              
    o.weight=*temp-'0';        //后存的是节点权 
    temp ++;
    h->push_front(o);
  }
  /////////////////////////
}

void initial(){ //初始化 
   char * ch[]={"A162135","B062543","C0115354654","D052552","E132656","F322446"};
   for(int i =0;i<6;i++){
      init(ch[i]);
    } 
}

void printout(){ //打印 
  gNode n;
   for(int i =0;i<vexs.size();i++){
       n = vexs.at(i);
       cout<<n.info<<",";
       list<node>::iterator it = n.first->begin();
       while(it != n.first->end()){
          cout<<it->vex<<","<<it->weight<<"  ";
        it++; 
        }
        cout<<endl;
    }
}

typedef struct tempA{ ///辅助数组 
  int weight;  //权最小的边的权值 
  int vex;     //由哪个顶点连接过来 
  int flag;    //是否已经在树中 
}tempA;

vector<tempA> temp;

void initTempA(){//初始化临时用数组 
  tempA a;
  a.weight =100;
  a.vex = -1;
  a.flag = 1;
  temp.push_back(a);
  for(int i =0;i<5;i++){
    a.weight = 100;
    a.vex =-1;
    a.flag = 0;
    temp.push_back(a); 
  } 
  
}

void printout2(){
  cout<<"vex  weight  flag"<<endl;
  for(int i =0 ;i<temp.size();i++){
    tempA a = temp.at(i);
    cout<<i<<"   "<<a.vex<<","<<a.weight<<"," <<a.flag<<endl;
  } 
}

int getMinix(){//取出当前临时数组中权值
               //最小的边的信息，该边权值>-1 flag = 0
    int index;
   for(int i =0 ;i<temp.size();i++){
      tempA a = temp.at(i);    
      if(a.weight>-1 && a.flag==0){
        index = i;
        break;
      }
    } 
    for(int i = index;i<temp.size();i++){
       if(temp.at(i).weight<temp.at(index).weight && temp.at(i).weight!=100 && temp.at(i).flag==0)
          index = i;
    }
   return index;
}

///////////////////////////主要核心算法在此处向下 

void init3(){
    gNode n = vexs.at(0);//选择入口顶点，0号顶点 
  head h = n.first;                     //取得入口顶点的边信息 
  list<node>::iterator it = h->begin();
  while(it!=h->end()){
     node a = *it;
     tempA &b=temp.at(a.vex);
     b.vex = 0;
     b.weight = a.weight;
     it++;
  }
}

void fun(){//最小树求解 
  init3(); 
  for(int i =0;i<5;i++)
  {
     int min = getMinix();
     temp.at(min).flag = 1;
     gNode n = vexs.at(min);//选择最小权的边 
     head h = n.first;       
     list<node>::iterator it = h->begin();
     while(it!=h->end()){
       node a = *it;
       if(  a.weight < temp.at(a.vex).weight && temp.at(a.vex).flag != 1){
          temp.at(a.vex).weight = a.weight;
          temp.at(a.vex).vex = min;
        }
       it++;
    }
  }
}

//////////////////////////////////////主要核心算法结束 

void result(){
  for(int i = 1;i<6;i++){
     tempA a = temp.at(i); 
     gNode n1 = vexs.at(i);
     gNode n2 = vexs.at(a.vex);
     int weight = a.weight;
     
     cout<<"<"<< n1.info<<","<<n2.info<<">:"<<weight<<endl;
  }
}

int main(){
   initial();
   printout();
   cout<<"-------"<<endl;
   initTempA();
   //printout2();
   fun();
   result();
   system("PAUSE");
} 

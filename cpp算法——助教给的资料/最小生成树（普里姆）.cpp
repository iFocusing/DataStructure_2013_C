#include<iostream>

#include<list>
#include<vector>

using namespace std;

//node�Ǳߵ���Ϣ�ڵ� 
typedef struct node{
  int vex;
  int weight;
}node;

typedef list<node>  *head;

//gNode�Ƕ������Ϣ�ڵ� 
typedef struct gNode{
  char info;  //�����������Ϣ 
  head first; //ָ��ö����ĵ�һ���� 
}gNode;

vector<gNode> vexs; //����vexs�洢�����еĶ���

void init(){//�÷�������ʼ��һ��ͼ�� vexs������ 
  gNode n ;               //����һ������ 
  n.info='A';             //���㸳ֵ��Ϣ 
  head h= new list<node>();//����һ������ 
  n.first = h;         //������붥��
  vexs.push_back(n);      //�����������vexs 
  ////////////////////////////
  node o ;
  o.vex=1;                 //��һ�����������ֵ 
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

void init(char * ch){//�÷�������ʼ��һ��ͼ�� vexs������ 
  gNode n ;               //����һ������ 
  char * temp = ch;
  n.info=*temp;             //���㸳ֵ��Ϣ 
  temp++;
  head h= new list<node>();//����һ������ 
  n.first = h;         //������붥��
  vexs.push_back(n);      //�����������vexs 
  ////////////////////////////
  node o ;
  
  while(*temp ){
    o.vex=*temp-'0';           //�ȴ���ǽڵ�ֵ 
    temp++;              
    o.weight=*temp-'0';        //�����ǽڵ�Ȩ 
    temp ++;
    h->push_front(o);
  }
  /////////////////////////
}

void initial(){ //��ʼ�� 
   char * ch[]={"A162135","B062543","C0115354654","D052552","E132656","F322446"};
   for(int i =0;i<6;i++){
      init(ch[i]);
    } 
}

void printout(){ //��ӡ 
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

typedef struct tempA{ ///�������� 
  int weight;  //Ȩ��С�ıߵ�Ȩֵ 
  int vex;     //���ĸ��������ӹ��� 
  int flag;    //�Ƿ��Ѿ������� 
}tempA;

vector<tempA> temp;

void initTempA(){//��ʼ����ʱ������ 
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

int getMinix(){//ȡ����ǰ��ʱ������Ȩֵ
               //��С�ıߵ���Ϣ���ñ�Ȩֵ>-1 flag = 0
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

///////////////////////////��Ҫ�����㷨�ڴ˴����� 

void init3(){
    gNode n = vexs.at(0);//ѡ����ڶ��㣬0�Ŷ��� 
  head h = n.first;                     //ȡ����ڶ���ı���Ϣ 
  list<node>::iterator it = h->begin();
  while(it!=h->end()){
     node a = *it;
     tempA &b=temp.at(a.vex);
     b.vex = 0;
     b.weight = a.weight;
     it++;
  }
}

void fun(){//��С����� 
  init3(); 
  for(int i =0;i<5;i++)
  {
     int min = getMinix();
     temp.at(min).flag = 1;
     gNode n = vexs.at(min);//ѡ����СȨ�ı� 
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

//////////////////////////////////////��Ҫ�����㷨���� 

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

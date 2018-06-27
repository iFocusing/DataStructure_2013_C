#include<iostream>
using namespace std;

typedef struct {
  int weight;
  int parent;
  int lchild;
  int rchild; 
}HTreeNode,*HTree;

void createHTree(HTree *t ,int * w, int n )
{
  void select(HTree t, int i, int *s1, int *s2);
   *t = new HTreeNode[2*n-1];
   for(int i=0;i<n;i++){
    (*t)[i].weight = w[i];
    (*t)[i].parent = 0;
    (*t)[i].lchild = 0;
    (*t)[i].rchild = 0;  
   }
   for(int i=n;i<2*n-1;i++){
    (*t)[i].weight = 0;
    (*t)[i].parent = 0;
    (*t)[i].lchild = 0;
    (*t)[i].rchild = 0; 
   }
   

   int s1,s2;
   for(int i=n;i<2*n-1;i++){
     select (*t, i,&s1,&s2);
     (*t)[i].weight=(*t)[s1].weight+(*t)[s2].weight;
     (*t)[i].lchild = s1;
     (*t)[i].rchild = s2;   
     (*t)[s1].parent = i;
     (*t)[s2].parent = i;
   }
   
   for(int i=0;i<2*n-1;i++){
      printf("%-3d%4d%4d%4d%4d\n",i,(*t)[i].weight,(*t)[i].parent,(*t)[i].lchild,(*t)[i].rchild);   
   }
    
}



void select(HTree t, int i, int *s1, int *s2){
   for(int j=0;j<i;j++){
     if(t[j].parent==0){*s1=j; break;}   
  }
  for(int j=*s1;j<i;j++){
     if( t[j].parent==0 && t[j].weight<t[*s1].weight ){
        *s1 = j;
      }
  }/////////////////////////////////////////
  for(int j=0;j<i;j++){
     if(t[j].parent==0 && j!=*s1){*s2=j; break;}   
  }
  for(int j=*s2;j<i;j++){
     if(t[j].parent==0 && t[j].weight<t[*s2].weight &&  j!=*s1){
        *s2 = j;
      }
  }
  int temp;
  if(*s1>*s2){
    temp = *s1;
    *s1= *s2;
    *s2=temp;
  }
}


void encode(HTree t, int n){
  int temp,temp2;
  string s = "";
  for(int i = 0 ;i<n;i++){
    printf("weight: %-4d",t[i].weight);
    temp = i;
    s="";
    while(t[temp].parent !=0){
       temp2 = temp;
       temp = t[temp].parent;
       if(t[temp].lchild == temp2) s.append("0");
       if(t[temp].rchild == temp2) s.append("1");
    }
    string::reverse_iterator it = s.rbegin();
    while(it != s.rend()){
      cout<<*it;
      it++; 
    }
    cout<<endl;
  } 
}


int main(){
  int w[10] ={5,29,7,8,14,23,3,11};
  int n = 8;
  HTree t = NULL;
  createHTree( &t,w,n);
  cout<<endl;
  encode(t,n);
  system("PAUSE"); 
}

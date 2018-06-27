#include<iostream>
using namespace std;
struct node
{
    char data;
    node*lch;
    node*rch;
    int ltag;
    int rtag;
};
class bitree
{
    node*root;
    node*thr_root;
    int leaf;//树叶子的个数 
   // int d_left,d_right;
    int d;//代表树的深度 
    
    public:
        bitree(){root=NULL;leaf=0;d=0;}  //构造函数
        ~bitree(){destory(root);}
      
        void creat()//创建一颗二叉树调用重载函数creat(node*) 先序遍历DLR 
        {
            cout<<"按照先序遍历输入数据，输入空数据时请输入#："<<endl;
            creat(root);
            cout<<"创建成功!"<<endl;
        }
        void destory(node*&);//销毁开辟的对空间释放内存，使用后续遍历LRD （此处也必须使用指针的引用） 
        void preorder(){cout<<"先序遍历二叉树!"<<endl;preorder(root);cout<<endl;}//先序遍历输出结点数值 
        void count_leaf(){count_leaf(root,leaf);cout<<"这棵树有"<<leaf<<"片叶子！"<<endl;}//用先序遍历统计叶子结点的个数
        void depth(){d=depth(root);cout<<"树的深度为"<<d<<endl;} //后续遍历求树的深度 
        
        void inorderthreading(){inorderthreading(thr_root,root);}
        void inorderthreading(node*&,node*);
        void threading(node*,node*);
        void travethr(){travethr(thr_root);}
        void travethr(node*);
    private:
        void creat(node*&);  //重载创建二叉树函数creat()为了递归调用 (注意此处必须使用结构体指针的引用，否则root是不会改变的)
        void preorder(node*);
        void count_leaf(node*,int &);//先序遍历求叶子 
        int depth(node*); 
        
};

void bitree::creat(node*&t)
{
    char d;
    cin>>d;
    if(d=='#')t=NULL;
    else
    {
        t=new node;
        t->data=d;
        creat(t->lch);
        creat(t->rch);
    }
}


void bitree::preorder(node*t)
{
    if(t)
    {
        cout<<t->data;
        preorder(t->lch);
        preorder(t->rch);
    }
}


void bitree::count_leaf(node*t,int &leaf)
{
    if(t)
    {
        if(!(t->lch)&&!(t->rch))leaf++;
        count_leaf(t->lch,leaf);
        count_leaf(t->rch,leaf);
    }
}


int bitree::depth(node*t)
{   
    if(t==NULL)return 0;
    else
    return   (depth(t->lch)>depth(t->rch)?depth(t->lch):depth(t->rch))+1;
}     

void bitree::threading(node*t,node*pre)
{
    threading(t->lch,pre);
    if(t->lch==NULL){t->lch=pre;t->ltag=1;}
    if(pre->rch=NULL){pre->rch=t;pre->rtag=1;}
    pre=t;
    threading(t->rch,pre);
}


void bitree::inorderthreading(node*&thr,node*t)
{
    thr=new node;
    thr->ltag=0;
    thr->rtag=1;
    thr->rch=thr;
    if(t==NULL)thr->lch=thr;
    else
    {
        thr->lch=t;
        node*pre=thr;
        threading(t,pre);
        pre->rch=thr;
        pre->rtag=1;
        thr->rch=pre;
        
    }
    
}


void bitree::travethr(node*t)
{
    node*p=t->lch;
    while(p!=t)
    {
     while(p->ltag==0)p=p->lch;
     cout<<p->data;
     while(p->rtag==1&&p->rch!=t)
     {
            p=p->rch;
     cout<<p->data;
     
     } 
   p=p->rch;
  }
}

void bitree::destory(node*&t)
{
    if(t)
    {
        destory(t->lch);
        destory(t->rch);
        delete t;
    }
}
int main()
{   bitree tree;
    tree.creat();
    
    tree.preorder();
    
    tree.count_leaf();
    
    tree.depth();
    
    tree.inorderthreading();
    tree.travethr();
    
    system("PAUSE");
    return 0;
}

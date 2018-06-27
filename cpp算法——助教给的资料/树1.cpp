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
    int leaf;//��Ҷ�ӵĸ��� 
   // int d_left,d_right;
    int d;//����������� 
    
    public:
        bitree(){root=NULL;leaf=0;d=0;}  //���캯��
        ~bitree(){destory(root);}
      
        void creat()//����һ�Ŷ������������غ���creat(node*) �������DLR 
        {
            cout<<"������������������ݣ����������ʱ������#��"<<endl;
            creat(root);
            cout<<"�����ɹ�!"<<endl;
        }
        void destory(node*&);//���ٿ��ٵĶԿռ��ͷ��ڴ棬ʹ�ú�������LRD ���˴�Ҳ����ʹ��ָ������ã� 
        void preorder(){cout<<"�������������!"<<endl;preorder(root);cout<<endl;}//���������������ֵ 
        void count_leaf(){count_leaf(root,leaf);cout<<"�������"<<leaf<<"ƬҶ�ӣ�"<<endl;}//���������ͳ��Ҷ�ӽ��ĸ���
        void depth(){d=depth(root);cout<<"�������Ϊ"<<d<<endl;} //����������������� 
        
        void inorderthreading(){inorderthreading(thr_root,root);}
        void inorderthreading(node*&,node*);
        void threading(node*,node*);
        void travethr(){travethr(thr_root);}
        void travethr(node*);
    private:
        void creat(node*&);  //���ش�������������creat()Ϊ�˵ݹ���� (ע��˴�����ʹ�ýṹ��ָ������ã�����root�ǲ���ı��)
        void preorder(node*);
        void count_leaf(node*,int &);//���������Ҷ�� 
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

#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <limits.h>  
#define MAX_VERTEX_NUM 20  
typedef int VRType;  
typedef char VertexType;  
typedef enum {DG,UDG} GKind;  //{����ͼ,����ͼ}  
typedef struct   
{  
    VertexType vexs[MAX_VERTEX_NUM];            //��������  
     VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���  
     int vexnum,arcnum;                          //�������ͻ���  
     GKind kind;                                 //ͼ�������ʶ     
}MGraph;  

int *visited;   //��¼�����Ƿ񱻷���  
//�����ַ��ڶ��������е��±�ֵ  
int LocateVex(const MGraph &G,VertexType ch)  
{  
    int i;  
    for ( i = 0; G.vexnum; i++ )  
        if ( ch == G.vexs[i] )  
        return i;  
    return -1;  
}    
//�õ���һ��δ�����ʵ����ڽڵ��±꣬���ޣ��򷵻�-1  
int firstAjdVex(const MGraph &G,int v)  
{  
    int i;  
    for ( i = 0; i < G.vexnum; i++ )  
    {  
        if ( !visited[i] && G.arcs[v][i] > 0 && G.arcs[v][i] < INT_MAX)  
            return i;  
    }  
    return -1;    
}  
//�õ���һ��δ�����ʵ����ڽڵ��±꣬���ޣ��򷵻�-1  
int nextAjdVex(const MGraph &G,int v,int w)  
{  
    int i;  
    for ( i = w; i < G.vexnum; i++ )  
    {  
        if ( !visited[i] && G.arcs[v][i] > 0 && G.arcs[v][i] < INT_MAX)  //������ 
            return i;  
    }  
    return -1;  
}    
//��������ͼ  
void CreatUDG(MGraph &G)  
{  
    int i,j,k,w;  
    char v1,v2;  
  
    printf("���붥�����ͱ�����");  
    scanf("%d%d",&G.vexnum,&G.arcnum);   
  
    visited = (int *)malloc(G.vexnum*sizeof(int));  
    for ( i = 0; i < G.vexnum; i++ )  
    visited[i] = 0;  
    printf("�밴��������%d��������ĸ���(��ABC��)��",G.vexnum);  
  
    getchar();//�������������ϴ�������Ļ��з���������µĻس���  
     for ( i = 0; i < G.vexnum; i++ )  
        scanf("%c",&G.vexs[i]);  
          
     getchar();//�������������ϴ�������Ļ��з���������µĻس���  
      for ( i = 0; i < G.vexnum; ++i )  
    for ( j = 0; j < G.vexnum; ++j )  
        {//��ʼ���ڽӾ���  
        if ( i == j )  
        G.arcs[i][j] = 0;  
        else  
        G.arcs[i][j] = INT_MAX;  
        }  
      
    printf("����ߵĶ����Ȩֵ(��A B 1):\n");  
      
    for ( k = 0; k < G.arcnum; k++ )  
    {  
    scanf("%c %c %d",&v1,&v2,&w);  
    i = LocateVex(G,v1);  
         j = LocateVex(G,v2);  
    G.arcs[i][j] = w;  
    G.arcs[j][i] = w;  
    getchar();//�������������ϴ�������Ļ��з���������µĻس���  
    }  
}  
//ѡ�񴴽�ͼ������  
void CreatGraph(MGraph &G)  
{  
    int k;  
    printf("��������ͼ:\n");   
    G.kind = UDG;  
    CreatUDG(G);  
}   
void DFS(const MGraph &G,int v)  
{  
    int w;  
    visited[v] = 1;  
         printf("%-4c",G.vexs[v]);  
         for ( w = firstAjdVex(G,v); w >= 0; w = nextAjdVex(G,v,w) )  
        if ( !visited[w] )  
        DFS(G,w);  
}  
//������ȱ�������  
void DFSTraverse(const MGraph &G)  
{  
    int i;  
  
    for ( i = 0; i < G.vexnum; i++ )  
        visited[i] = 0;   //��ʼ�����ʱ������  
    for ( i = 0; i < G.vexnum; i++ )  
        if ( !visited[i] )  
        {//����δ���ʵĶ������DFS  
            DFS(G,i);  
        }  
        printf("\n");  
}  
//������  
int main()  
{  
    MGraph G;  
    CreatGraph(G);  
    //������ȱ������  
    printf("\n������ȱ���:");  
    DFSTraverse(G);  
    getchar();getchar();getchar();getchar();
    return 0;  
}  

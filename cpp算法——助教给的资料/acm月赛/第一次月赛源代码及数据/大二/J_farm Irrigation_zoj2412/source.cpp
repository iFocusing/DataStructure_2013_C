#include<stdio.h> 
  
unsigned char farm[50][50]; 
unsigned char type[11]={9,12,3,6,10,5,13,11,7,14,15};//A-K 11�ֱ���  
unsigned char con[4]={7,11,13,14};  //�������� �ñ�  
int der[4][2]={{-1,0},{0,1},{1,0},{0,-1}};// �������� ˳ʱ��  
int wid,len; 
  
void dfs(int x,int y) 
{ 
   int i,a,b,tag1,tag2 ; 
   /* �Ȱ���Ч�߲ü��� */ 
    if(x == 0) 
           farm[x][y] &=  con[0]; 
    if(y == len - 1) 
           farm[x][y] &= con[1]; 
    if(x == wid - 1) 
           farm[x][y] &= con[2]; 
    if(y == 0) 
           farm[x][y] &= con[3]; 
             
   if(farm[x][y])//���Ϊ0����û��Ҫ������         
   for(i = 0 ; i < 4 ; ++i) 
   { 
     a = x + der[i][0]; 
     b = y + der[i][1]; 
     if(a < 0 || a >= wid || b < 0 || b >= len)//Խ���ж�  
       continue ; 
     tag1 = 0 ; 
     tag2 = 0 ; 
     if(farm[a][b]) 
     { 
       switch(i)// �ж��Ƿ���������  
       { 
         case  0: tag1 = farm[a][b] & 2; tag2 = farm[x][y] & 8 ;break;          
         case  1: tag1 = farm[a][b] & 1; tag2 = farm[x][y] & 4 ;break; 
         case  2: tag1 = farm[a][b] & 8; tag2 = farm[x][y] & 2 ;break; 
         case  3: tag1 = farm[a][b] & 4; tag2 = farm[x][y] & 1 ;break; 
       }   
       if(tag1 && tag2) //��������  
       { 
          switch(i)//��������  
         { 
            case  0: farm[x][y] &= con[0];farm[a][b] &= con[2];break;          
            case  1: farm[x][y] &= con[1];farm[a][b] &= con[3];break; 
            case  2: farm[x][y] &= con[2];farm[a][b] &= con[0];break; 
            case  3: farm[x][y] &= con[3];farm[a][b] &= con[1];break; 
         } 
        dfs(a,b); 
       }  
    }  
  }  
   farm[x][y] = 0 ; //�����ˣ�Ҫ��0  
   return ;      
} 
  
int main() 
{ 
    freopen("in.txt","r",stdin); 
    freopen("out.txt","w",stdout);
    int i,j,cnt;  
    char c; 
    
    while(scanf("%d%d",&wid,&len)) 
    { 
         if(wid < 0 || len < 0) break; 
         for(i = 0 ; i < wid ; ++i)  
         { 
               getchar(); 
               for(j = 0 ; j < len ; ++j) 
               { 
                 scanf("%c",&c); 
                 farm[i][j] = type[c-'A'];       
               }   
         }   
         cnt = 0; 
         for(i = 0 ; i < wid ; ++i) 
         for(j = 0 ; j < len ; ++j) 
             if(farm[i][j]) 
             { 
               dfs(i,j); 
               ++cnt;               
             }   
         printf("%d\n",cnt);                      
    } 
  
  return 0;     
}

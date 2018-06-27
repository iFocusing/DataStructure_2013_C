#include<stdio.h> 
#include<stdlib.h> 
  
int d[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};//从左上开始，顺时针 
char oil[101][101]; 
int len,wid; 
  
void dfs(int x,int y);  
int main() 
{ freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
 int i,j,cnt; 
   
   while(scanf("%d%d",&wid,&len)) 
   { 
     getchar(); 
     if( !len && !wid) break ; 
                                    
     for(i = 0 ; i < wid ; ++i) 
     { 
           scanf("%s",oil[i]);   
           getchar(); 
     }  
       
     cnt = 0 ;  
     for(i = 0 ; i < wid ; ++i) 
     { 
        for(j = 0 ; j < len ; ++j)     
        if(oil[i][j] == '@') 
        {            
           dfs(i,j); 
           ++cnt;             
        }    
     }                
             
     printf("%d\n",cnt); 
                    
   } 
         
 return 0;     
} 
  
void dfs(int x,int y) 
{ 
   int i,a,b; 
    
   oil[x][y] = '*'; 
   for(i = 0 ; i < 8 ; ++i) 
   { 
      a = x + d[i][0]; 
      b = y + d[i][1]; 
      if(a < 0 || a >= wid || b < 0 || b >= len) 
        continue ; 
      if(oil[a][b] == '@') 
      { 
        dfs(a,b);  
      } 
   }   
  return ;   
}

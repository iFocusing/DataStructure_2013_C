#include<iostream>
 #include<cstdio>
 #include<cstring>
 using namespace std;
 const int inf=1<<30;
 const int nMax=105;
 int map[nMax][nMax];
 bool vis[nMax][nMax];
 int main(){
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
     int t,n,num,i,j,k,flag,cas=0;
     while(scanf("%d",&t)&&t)
     {
       while(t--){
         cas++;
         flag=num=0;
         scanf("%d",&n);
         memset(vis,0,sizeof(vis));
         for(i=1;i<=n;i++){
             for(j=1;j<=n;j++){
                 scanf("%d",&map[i][j]);
                 if(!map[i][j])map[i][j]=inf;
                 else{
                     num++;
                 }
             }
         }
         for(k=1;k<=n;k++){
             for(i=1;i<=n;i++){
                 for(j=1;j<=n;j++){
                     if(flag||map[i][j]==inf||map[i][k]==inf||map[k][j]==inf)continue;
                     if(map[i][j]>map[i][k]+map[k][j]){
                         flag=1;
                     }
                     if(map[i][j]==map[i][k]+map[k][j]){
                         if(!vis[i][j])num--;
                         vis[i][j]=1;
                     }
                 }
             }
         }
         printf("Case %d: ",cas);
         if(flag)printf("impossible\n");//cout<<"impossible\n";
         else{
             printf("%d\n",num);
         }
     }
     }
     return 0;
 }

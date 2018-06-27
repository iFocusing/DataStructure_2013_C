typedef struct T{
 int col;
 int row;
 int val; 
} tirple;
int m[10][10]={{0,0,0,0,0,0,0,0,0,0}, 
							 {0,1,0,0,0,0,0,0,0,0}, 
							 {0,0,0,0,2,0,0,0,0,0}, 
							 {0,0,0,0,0,0,0,0,0,0}, 
							 {0,0,0,0,0,0,0,0,0,6}, 
							 {0,0,0,0,0,0,0,0,0,0}, 
							 {0,0,0,3,0,0,0,4,0,0}, 
							 {0,0,0,0,0,0,0,0,0,0}, 
							 {0,0,0,0,0,0,0,0,0,0}, 
							 {0,0,0,0,0,0,5,0,0,0}};
int a[2][10] ={0};
int count = 6;
int row = 10;
int col = 10;
struct T t1[100];
struct T t2[100];

void fill(){
  int i,j,k=0;
  struct T temp;
   for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      if(m[i][j]!=0){
        temp.row=i;
        temp.col = j;
        temp.val = m[i][j];
        t1[k++]= temp;
      }
    }
  }
  for( i=0;i<count;i++)
    printf("%3d,%3d,%3d\n",t1[i].row,t1[i].col,t1[i].val);
    printf("\n");
  
}
void fill2(){
  int i,j,k;
 for( i=0;i<count;i++){
   a[0][t1[i].col]++;
  }
  for( i=1 ;i<10;i++){
   a[1][i]= a[0][i-1]+a[1][i-1]; 
  }
  for( j =0;j<10;j++){
    printf("%3d",j );
  }
  printf("\n");
  for( j =0;j<10;j++){
    printf("%3d",a[0][j] );
  }
  printf("\n");
  for( k =0;k<10;k++){
    printf("%3d",a[1][k] );
  }
  printf("\n"); 
}
void fill3(){
    int i;
    struct T temp;
  for(i=0;i<count;i++){
    temp.row = t1[i].col;
    temp.col = t1[i].row;
    temp.val = t1[i].val;
    t2[a[1][t1[i].col]]= temp;
    a[1][t1[i].col]++;
  } 
  for( i=0;i<count;i++)
    printf("%3d,%3d,%3d\n",t2[i].row,t2[i].col,t2[i].val);
    printf("\n");
}

int main(){
 fill();
 fill2(); 
 fill3();
 system("PAUSE");
}

 
#include<stdio.h>
int main() {
     freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  int D, I,i;
  while(scanf("%d%d", &D, &I)&&(D!=0||I!=0)) {
    int k = 1;
    for( i = 0; i<D-1; i++)
      if(I%2) { k = k*2; I = (I+1)/2; }
      else { k = k*2+1; I /= 2; }
    printf("%d\n", k);
  }
  return 0;
}
        

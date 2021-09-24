#include <cstdio>
int N,ans=2;
int main(){
   scanf("%d",&N);
   while(N--) ans = 2*(ans-1)+1;
   printf("%d",ans*ans);
}
#include <cstdio>
#include <cstring>
int N,C,M,dest[2001][2001],cnt[2001],ans;
int main(){
    scanf("%d%d%d",&N,&C,&M);
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dest[a][b]=c;
    }
    int t = 0;
    for(int i=1;i<=N;i++){
        ans+=cnt[i];
        t-=cnt[i];
        for(int j=i+1;j<=N;j++){
            if(!dest[i][j]) continue;
            if(t+dest[i][j]<=C){
               cnt[j]+=dest[i][j];
               t+=dest[i][j];
            }else{
               cnt[j]+=C-t; 
               dest[i][j]-=C-t;
               t = C;               
               for(int k=N;k>j;k--){
                   if(!dest[i][j]) break;
                   if(cnt[k] > 0){
                       if(dest[i][j]<=cnt[k]){
                           cnt[j]+=dest[i][j];
                           cnt[k]-=dest[i][j];
                           dest[i][j]=0;
                       }else{
                           cnt[j]+=cnt[k];
                           dest[i][j]-=cnt[k];
                           cnt[k]=0;
                       }
                   }
               }
            }
        }
    }
    printf("%d",ans);
}
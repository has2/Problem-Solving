#include <cstdio>
int t,N;
long long a[65][10];
int main(){
    scanf("%d",&t);
    for(int i=0;i<10;i++) a[1][i]=1;
    for(int i=2;i<65;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<=j;k++) 
                a[i][j]+=a[i-1][k];
    while(t--){
        scanf("%d",&N);
        long long ans=0;
        for(int i=0;i<10;i++) ans+=a[N][i];
        printf("%lld\n",ans);
    }
}
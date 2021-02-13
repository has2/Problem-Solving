#include <cstdio>
int tc,N,M,K,a[100000];
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        int ans=0,sum=0;
        for(int i=0;i<M;i++) sum+=a[i];
        if(sum<K) ans++;
        if(N!=M){
            for(int i=1;i<N;i++){
                sum-=a[i-1];
                sum+=a[(i+M-1)%N];
                if(sum<K) {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
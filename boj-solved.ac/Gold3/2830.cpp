#include <cstdio>
int N;
long long onecnt[20];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        int v;
        scanf("%d",&v);
        int j=0;
        while(1){
            if(v/2==0) {
                onecnt[j]++;
                break;
            }
            onecnt[j++]+=v%2;
            v/=2;
        }
    }
    long long ans=0;
    for(int i=0;i<20;i++) ans+=(1<<i)*(N-onecnt[i])*onecnt[i];
    printf("%lld",ans);
}
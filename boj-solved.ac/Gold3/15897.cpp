#include <cstdio>
long long N,ans,d;
int main(){
    scanf("%lld",&N);
    for(long long i=1,cur=N-1;i<N;i+=d,cur=(N-1)/i){
        d = ((N-1)%i)/((N-1)/i)+1;
        ans+=cur*d;
    }
    printf("%lld",ans+N);
}

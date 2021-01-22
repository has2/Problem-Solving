#include <cstdio>
using ll = long long;
int tc,H,W;
ll N;
int main(){
    scanf("%d",&tc);
    while(tc--){ 
        scanf("%d%d%lld",&W,&H,&N);
        int wc=1,hc=1;
        while(W%2==0){
            wc*=2;
            W/=2;
        }
        while(H%2==0){
            hc*=2;
            H/=2;
        }
        if(wc*hc >= N) puts("YES");
        else puts("NO");
    }
}

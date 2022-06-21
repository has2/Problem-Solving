#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
int T;
ll N,M,k,D;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&N,&M,&k,&D);
        ll B=0;
        while(N*M*B*(k*(M-1)+M*(N-1))<=2*D) B++;
        if(B<=1) {
            puts("-1");
            continue;
        }
        ll a=N*M*(B-1)*(k*(M-1)+M*(N-1));
        printf("%lld\n",a/2);
    }
}
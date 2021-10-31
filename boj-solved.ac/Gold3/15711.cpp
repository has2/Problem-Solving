#include <cstdio>
#include <map>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;
int T;
ll A,B,np[2000001];
vector<ll> primes;
int main(){
    scanf("%d",&T);

    np[1]=1;
    for(int i=2;i<=2000000;i++){
        if(np[i]) continue;
        for(int j=i*2;j<=2000000;j+=i){
            np[j]=1;
        }
    }
    for(ll i=2;i<=2000000;i++) if(!np[i]) primes.push_back(i);

    while(T--){
        scanf("%lld%lld",&A,&B);
        ll sum = A+B;
        if(sum==2) {
            puts("NO");
            continue;
        }
        if(sum%2){
            sum-=2;
            bool ok=0;
            if(sum<=2000000) {
                puts(np[sum] ? "NO" : "YES");
                continue;
            }
            for(auto p : primes){
                if(sum<p) break;
                if(sum%p==0) {
                    ok=1;
                    break;
                }
            }
            puts(ok?"NO":"YES");
        }else{
            puts("YES");
        }
    }
}
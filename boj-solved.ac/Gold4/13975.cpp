#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
using ll = long long;
int T,K;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&K);
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=0;i<K;i++) {
            int v;
            scanf("%d",&v);
            pq.push(v);
        }
        ll ans=0;
        while(pq.size()>1){
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            pq.push(a+b);
            ans+=a+b;
        }
        printf("%lld\n",ans);
    }
}
#include <cstdio>
#include <queue>
using namespace std;
int n,m;
using ll = long long;
int main(){
    scanf("%d%d",&n,&m);
    priority_queue<long long> pq;
    while(n--) {
        int v;
        scanf("%d",&v);
        pq.push(-v);
    }
    while(m--){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }
    ll ans=0;
    while(!pq.empty()) ans+=pq.top(), pq.pop();
    printf("%lld",-ans);
}

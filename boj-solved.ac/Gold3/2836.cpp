#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int N;
ll M;
vector<pair<ll,ll>> v;
int main(){
    scanf("%d%lld",&N,&M);
    for(int i=0;i<N;i++) {
        ll u,r;
        scanf("%lld%lld",&u,&r);
        if(u>r) v.push_back({r,u});
    }
    sort(v.begin(),v.end());

    ll s=v[0].first, e=v[0].second;
    for(auto p : v){
        if(e<p.first){
            M+=2*(e-s);
            s=p.first,e=p.second;
        }else if(e<p.second){
            e=p.second;
        }
    }
    M+=2*(e-s);
    printf("%lld",M);
}
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
struct P{ int u,v,d; };
int N,M,t,uf[10001];
vector<P> a;
bool cmp(P& l,P& r){ return l.d < r.d; }
int find(int n){
    if(n==uf[n]) return n;
    return find(uf[n]);
}
bool merge(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v) return 0;
    uf[u]=v;
    return 1;
} 
int main(){
    scanf("%d%d%d",&N,&M,&t);
    while(M--){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        a.push_back({u,v,d});
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=1;i<=N;i++) uf[i]=i;
    int ans=0,ct=0,j=0;
    for(int i=0;i<a.size();i++){
        auto [u,v,d] = a[i];
        if(merge(u,v)){
            ans+=d+ct;
            ct+=t;
            if(++j==N-1) break;
        }
    }
    printf("%d",ans);
}
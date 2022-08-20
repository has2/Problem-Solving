#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,uf[1001],adj[1001][1001];
struct P{
    int u,v,d;
};
int find(int n){
    if(n==uf[n]) return n;
    return find(uf[n]);
}
bool merge(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v) return 0;
    uf[u] = v;
    return 1; 
}
bool cmp(P& a,P& b){
    return a.d < b.d;
}
bool check(){
    int r = find(2);
    for(int i=2;i<=N;i++){
        if(find(i)!=r) return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) uf[i]=i;
    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[b][a]=adj[a][b]=1;
        merge(b,a);
    }
    vector<P> edges;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int v;
            scanf("%d",&v);
            if(i==1||j==1||i>=j||adj[i][j]) {
                continue;
            }
            if(find(i)!=find(j)) {
                edges.push_back({i,j,v});
            }
        }
    }
    sort(edges.begin(),edges.end(),cmp);
    vector<pair<int,int>> ret;
    int sum=0;
    for(auto [u,v,d] : edges){
        if(merge(u,v)){
            ret.push_back({u,v});
            sum+=d;
            if(check()) break;
        }
    }
    printf("%d %d\n",sum,ret.size());
    for(auto [u,v] : ret){
        printf("%d %d\n",u,v);
    }
}
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,s,e,ans;
vector<pair<int,int>> adj[100001];
void sol(int n,int prev,int val,int total){
    if(n==e){
        ans=total-val;
        return;
    }
    for(auto [nxt,d] : adj[n]){
        if(nxt!=prev) {
            sol(nxt,n,max(val,d),total+d);
        }
    }
}
int main(){
    scanf("%d%d%d",&N,&s,&e);
    for(int i=0;i<N-1;i++){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    sol(s,0,0,0);
    printf("%d",ans);
}
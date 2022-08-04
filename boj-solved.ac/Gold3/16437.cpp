#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
vector<int> adj[123457];
int N,cnt[123457];
ll dfs(int p,int n){
    ll sum=cnt[n];
    for(auto nxt : adj[n]){
        if(nxt!=p) sum+=dfs(n,nxt);
    }
    return sum < 0 ? 0 : sum;   
}
int main(){
    scanf("%d",&N);
    for(int i=2;i<=N;i++){
        char c;
        int a,p;
        scanf(" %c%d%d",&c,&a,&p);
        if(c=='W') a=-a; 
        adj[i].push_back(p);
        adj[p].push_back(i);
        cnt[i]=a;
    }
    printf("%lld",dfs(-1,1));
}
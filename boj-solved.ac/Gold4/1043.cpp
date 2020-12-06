#include <cstdio>
#include <vector>
using namespace std;
int N,M;
vector<int> pp[51],pty[51],tp;
bool visit[51];
void dfs(int n){
    visit[n] = 1;
    for(auto ptn : pp[n]){
        for(auto p : pty[ptn]){
            if(!visit[p]) dfs(p);
        }
    }
}
int main(){
    scanf("%d%d",&N,&M);
    int t,v;
    scanf("%d",&t);
    for(int i=0;i<t;i++) {
        scanf("%d",&v);
        tp.push_back(v);
    }
    for(int i=1;i<=M;i++){
        scanf("%d",&t);
        for(int j=0;j<t;j++){
            scanf("%d",&v);
            pty[i].push_back(v);
            pp[v].push_back(i);
        }
    }

    for(auto a : tp) dfs(a);
    int ans = 0;
    for(int i=1;i<=M;i++){
        bool ok = 1;
        for(auto p : pty[i]) {
            if(visit[p]){
                ok = 0;
                break;
            }
        }
        if(ok) ans++;
    }
    printf("%d",ans);
}
    

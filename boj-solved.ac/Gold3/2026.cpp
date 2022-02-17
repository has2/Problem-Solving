#include <cstdio>
#include <vector>
using namespace std;
int K,N,F,adj[901][901];
vector<int> frd;
bool sol(int cur){
    if(frd.size()==K) return 1;
    for(int i=cur+1;i<=N;i++){
        bool ok=1;
        for(auto a : frd){
            if(!adj[i][a]){
                ok=0;
                break;
            }
        }
        if(ok) {
            frd.push_back(i);
            if(sol(i)) return 1;
            frd.pop_back();
        }
    }
    return 0;
}
int main(){
    scanf("%d%d%d",&K,&N,&F);
    while(F--){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u][v]=adj[v][u]=1;
    }
    for(int i=1;i<=N;i++){
        frd.push_back(i);
        if(sol(i)){
            for(auto f : frd) printf("%d\n",f);
            return 0;
        }
        frd.clear();
    }
    puts("-1");
}
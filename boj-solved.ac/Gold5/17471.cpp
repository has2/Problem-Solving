#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int N,a[10];
bool flag[10],visit[10];
vector<int> adj[10];
vector<int> vst[2];
void dfs(int n,int k){
    visit[n]=1;
    vst[k].push_back(n);
    for(auto nxt : adj[n]){
        if(flag[nxt]==k&&!visit[nxt]) dfs(nxt,k);
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    for(int i=0;i<N;i++){
        int c;
        scanf("%d",&c);
        for(int j=0;j<c;j++){
            int k;
            scanf("%d",&k);
            k--;
            adj[i].push_back(k);
            adj[k].push_back(i);
        }
    }
    int ans = 9e8;
    for(int i=1;i<(1<<N);i++){
        int u=-1,v=-1;
        for(int j=0;j<N;j++){   
            if(i&(1<<j)) {
                flag[j]=1;
                if(u==-1) u=j;
            }
            else {
                flag[j]=0;
                if(v==-1) v=j;
            }
        }
        if(u==-1 || v==-1) continue;
        
        vst[0].clear();
        vst[1].clear();
        memset(visit,0,sizeof(visit));
        
        dfs(v,0);
        dfs(u,1);
        if(vst[0].size()+vst[1].size() != N) continue;

        int usum=0,vsum=0;
        bool ok=1;
        for(auto k : vst[0]){
            if(flag[k]) {
                ok=0;
                break;
            }
            usum+=a[k];
        }
        if(!ok) continue;

        ok=1;
        for(auto k : vst[1]){
            if(!flag[k]) {
                ok=0;
                break;
            }
            vsum+=a[k];
        }
        if(!ok) continue;
        ans=min(ans,abs(usum-vsum));
    }
    printf("%d",ans == 9e8 ? -1 : ans);
}
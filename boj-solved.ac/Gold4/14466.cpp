#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
using namespace std;
int N,K,R;
bool visit[101][101];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};
set<int> adj[20001];
vector<pair<int,int>> v;
int sol(int s,int e){
    memset(visit,0,sizeof(visit));
    queue<pair<int,int>> q;
    q.push({v[s].first,v[s].second});
    visit[v[s].first][v[s].second]=1;
    while(!q.empty()){
        auto [y,x] = q.front(); q.pop();
        if(y==v[e].first && x==v[e].second) return 0;
        for(int i=0;i<4;i++){
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<1||nx<1||ny>N||nx>N||visit[ny][nx]||adj[y*N+x].find(ny*N+nx) != adj[y*N+x].end()) continue;
            q.push({ny,nx});
            visit[ny][nx]=1;
        }
    }
    return 1;
}
int main(){
    scanf("%d%d%d",&N,&K,&R);
    while(R--){
        int r1,c1,r2,c2;
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        adj[r1*N+c1].insert(r2*N+c2);
        adj[r2*N+c2].insert(r1*N+c1);
    }
    while(K--){
        int y,x;
        scanf("%d%d",&y,&x);
        v.push_back({y,x});
    }
    int ans=0;
    for(int i=0;i<v.size()-1;i++)
        for(int j=i+1;j<v.size();j++) ans+=sol(i,j);
    printf("%d",ans);
}
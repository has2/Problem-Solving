#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M,map[52][52],total,Inf=9e8;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
bool visit[52][52];
vector<pair<int,int>> a;
vector<int> use;
int bfs(){
    memset(visit,0,sizeof(visit));
    queue<pair<int,int>> q;
    int ret=0,sum=0;    
    for(int i=0;i<use.size();i++){
        if(use[i]){
            q.push({a[i].first,a[i].second});
            visit[a[i].first][a[i].second]=1;
            sum++;
        }
    }
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto qf = q.front(); q.pop();
            int y = qf.first;
            int x = qf.second;
            for(int i=0;i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny<0||nx<0||ny>=N||nx>=N||map[ny][nx]==1||visit[ny][nx]) continue;
                q.push({ny,nx});
                visit[ny][nx]=1;
                sum++;
            }
        }
        ret++;
    }
    return total==sum ? ret-1 : Inf;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {
            scanf("%d",&map[i][j]);
            if(map[i][j]==2) a.push_back({i,j});
            if(map[i][j]!=1) total++;
        }
    use.resize((int)a.size());
    for(int i=0;i<M;i++) use[i]=1;
    reverse(use.begin(),use.end());
    int ans = Inf;
    do{
        ans = min(ans,bfs());
    }while(next_permutation(use.begin(),use.end()));
    if(ans==Inf) ans=-1;
    printf("%d",ans);
}

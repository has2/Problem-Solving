#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
struct P{
    int y,x,ey,ex,d;
};
vector<P> s;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
int N,M,K,map[21][21],py,px,INF=9e8;
bool visit[21][21];
int bfs(int y,int x){
    memset(visit,0,sizeof(visit));
    queue<P> q;
    q.push({y,x});
    visit[y][x] = 1;
    int ret = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            P qf = q.front(); q.pop();
            if(qf.y==py&&qf.x==px) return ret;
            for(int i=0;i<4;i++){
                int ny = qf.y+dy[i];
                int nx = qf.x+dx[i];
                if(ny < 1 || nx < 1 || ny > N || nx > N || map[ny][nx]) continue;
                if(!visit[ny][nx]){
                    q.push({ny,nx});
                    visit[ny][nx] = 1;
                }
            }
        }
        ret++;
    }
    return INF;
}
bool cmp(P& a,P& b){
    if(a.d < b.d) return 1;
    else if(a.d==b.d){
        if(a.y<b.y) return 1;
        else if(a.y==b.y) return a.x < b.x;
        return 0;
    }
    return 0;
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    s.resize(M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) scanf("%d",&map[i][j]);
    
    scanf("%d%d",&py,&px);
    for(int i=0;i<M;i++) scanf("%d%d%d%d",&s[i].y,&s[i].x,&s[i].ey,&s[i].ex);

    for(int i=0;i<M;i++){
        for(int j=0;j<s.size();j++) s[j].d = bfs(s[j].y,s[j].x);    
        sort(s.begin(),s.end(),cmp);
        P t = s[0];
        s.erase(s.begin());
        if(K-t.d < 0) {
            K=-1;
            break;
        }
        K-=t.d, py=t.y, px=t.x;

        int nDist = bfs(t.ey,t.ex);
        if(K-nDist < 0){
            K=-1;
            break;
        }
        py=t.ey, px=t.ex;
        K+=nDist;
    }
    printf("%d",K);
}
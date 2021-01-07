#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,cnt,visit[102][102],dy[4]={-1,1,0,0},dx[4]={0,0,1,-1}; 
vector<pair<int,int>> adj[101][101];
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int y,x,b,a;
        scanf("%d%d%d%d",&x,&y,&a,&b);
        adj[y][x].push_back({b,a});
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    visit[1][1]=2;
    int cnt=1;
    while(!q.empty()){
        int qsz=q.size();
        auto f = q.front(); q.pop();
        int y = f.first, x=f.second;
        for(auto p : adj[y][x]){
            int ny = p.first, nx = p.second;
            if(!visit[ny][nx]){
                for(int i=0;i<4;i++){
                    int ty=ny+dy[i],tx=nx+dx[i];
                    if(visit[ty][tx]==2) {
                        q.push({ty,tx});
                        break;
                    }
                }
                visit[ny][nx]=1;
                cnt++;
            }
        }
        for(int i=0;i<4;i++){
            int ny = y+dy[i], nx= x+dx[i];
            if(visit[ny][nx]==1){
                visit[ny][nx]=2;
                q.push({ny,nx});
            }
        }
    }
    printf("%d",cnt);
}

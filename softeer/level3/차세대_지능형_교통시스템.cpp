#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int dy[4] = {0,-1,0,1}, dx[4] = {1,0,-1,0};
struct P{int y,x,d;};
vector<int> signals[13] = { {},
    {0,1,3},{1,0,2},{2,1,3},{3,0,2},
    {0,1},{1,2},{2,3},{3,0},
    {0,3},{1,0},{2,1},{3,2}
};
int N,T,seq[100][100][4];
bool visit[100][100][4][4];
set<pair<int,int>> ans;
int main(){
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<4;k++)
                scanf("%d",&seq[i][j][k]);
    queue<P> q;
    q.push({0,0,1});
    visit[0][0][0][1]=1;
    ans.insert({0,0});
    int t=0;
    while(!q.empty()){
        int sz =q.size();
        if(t==T) break;
        while(sz--){
            auto [y,x,d] = q.front(); q.pop();
            if(signals[seq[y][x][t%4]][0]!=d) continue;

            for(auto k : signals[seq[y][x][t%4]]){
                int ny = y+dy[k], nx = x+dx[k];
                if(ny<0||nx<0||ny>=N||nx>=N||visit[ny][nx][t%4][k]) continue;
                visit[ny][nx][t%4][k]=1;
                q.push({ny,nx,k});
                ans.insert({ny,nx});
            }
        }
        t++;
    }
    printf("%d",ans.size());
}
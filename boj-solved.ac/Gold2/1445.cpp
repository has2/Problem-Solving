#include <cstdio>
#include <iostream>
#include <functional>
#include <queue>
#include <algorithm>
using namespace std;
struct P{
    pair<int,int> g,pos;
};
int N,M,dy[4]={-1,1,0,0},dx[4]={0,0,1,-1},sy,sx,ey,ex;
char board[50][50];
pair<int,int> dist[50][50];
struct cmp{
    bool operator()(P& a,P b){
        if(a.g.first>b.g.first) return true;
        else if(a.g.first==b.g.first) return a.g.second>b.g.second;
        return false;
    }
};
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) {
            scanf(" %c",&board[i][j]);
            if(board[i][j]=='S') sy=i,sx=j;
            if(board[i][j]=='F') ey=i,ex=j;
            dist[i][j]={9e8,9e8};
        }
    priority_queue<P,vector<P>,cmp> pq;
    dist[sy][sx]={0,0};
    pq.push({{0,0},{sy,sx}});
    while(!pq.empty()){
        auto [g,pos] = pq.top(); pq.pop();
        auto [y,x] = pos;
        if(g!=dist[y][x]) continue;
        for(int i=0;i<4;i++){
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=N||nx>=M) continue;
            pair<int,int> p = g;
            if(board[ny][nx]=='g') p = {g.first+1,g.second};
            else if(board[ny][nx]=='.') {
                bool ok=0;
                for(int j=0;j<4;j++){
                    int ty=ny+dy[j],tx=nx+dx[j];
                    if(ty<0||tx<0||ty>=N||nx>=M) continue;
                    if(board[ty][tx]=='g'){
                        ok=1;
                        break;
                    }
                }
                if(ok) p = {g.first,g.second+1};
            }
            if(p<dist[ny][nx]){
                dist[ny][nx]=p;
                pq.push({p,{ny,nx}});
            }
        }
    }
    printf("%d %d",dist[ey][ex].first,dist[ey][ex].second);
}
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,K,ans;
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};
struct P{
    int m,s,d;
};
vector<P> map[51][51],tmp[51][51];
void clear(vector<P> a[][51]){
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) a[i][j].clear();
}
void move(int i,int j){
    for(auto p : map[i][j]){
        int ny=i,nx=j;
        for(int k=0;k<p.s;k++){
            ny+=dy[p.d];
            nx+=dx[p.d];
            if(ny>N) ny=1;
            else if(ny<1) ny=N;
            if(nx>N) nx=1;
            else if(nx<1) nx=N;            
        }
        tmp[ny][nx].push_back(p);
    }   
}
void merge(int y,int x){
    if(tmp[y][x].size()<2) {
        map[y][x]=tmp[y][x];
        return;
    }
    int sm=0,ss=0,sd=0;

    for(auto p : tmp[y][x]){
        sm+=p.m;
        ss+=p.s;
        sd+=p.d%2;
    }
    int sz = tmp[y][x].size();
    int tm = sm/5;
    if(tm==0) return;
    int ts = ss/sz;
    int td;
    if(sd == sz || sd == 0) td = 0;
    else td = 1;
    for(;td<8;td+=2) map[y][x].push_back({tm,ts,td});
}
void cmd(){
    clear(tmp);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            move(i,j);
        }
    }
    clear(map);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            merge(i,j);
        }
    }    
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    while(M--){
        int r,c,m,s,d;
        scanf("%d%d%d%d%d",&r,&c,&m,&s,&d);
        map[r][c].push_back({m,s,d});
    }
    while(K--) cmd();
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            for(auto p : map[i][j]) ans+=p.m;
        }
    printf("%d",ans);
}

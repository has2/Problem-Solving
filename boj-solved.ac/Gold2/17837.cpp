#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,K,board[14][14];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
struct P{
    int num,d;
};
pair<int,int> pos[11];
vector<P> horse[14][14];
int cd(int d){
    return d%2==0 ? d+1 : d-1;
} 
bool move(int c,int y,int x,vector<P> v,int d){
    v[0].d=d;
    if(c==1) reverse(v.begin(),v.end());
    for(auto p : v) {
        horse[y][x].push_back(p);
        pos[p.num]={y,x};
    }
    return (int)horse[y][x].size()>=4;
}
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=N+1;j++) {
            if(i==N+1||j==N+1||i==0||j==0) board[i][j]=2;
            else scanf("%d",&board[i][j]);
        }
    }
    for(int i=1;i<=K;i++){
        int y,x,d;
        scanf("%d%d%d",&y,&x,&d);
        horse[y][x].push_back({i,d-1});
        pos[i]={y,x};
    }
    for(int ans=1;ans<=1000;ans++){
        for(int k=1;k<=K;k++){
            auto [y,x] = pos[k];
            int d,idx;
            vector<P> tmp;
            for(int i=0;i<horse[y][x].size();i++){
                if(horse[y][x][i].num==k){
                    idx=i;
                    d=horse[y][x][i].d;
                    break;
                }
            }
            for(int i=idx;i<horse[y][x].size();i++) tmp.push_back(horse[y][x][i]);
            horse[y][x].erase(horse[y][x].begin()+idx,horse[y][x].end());

            int ny=y+dy[d],nx=x+dx[d];
            bool ret=0;
            if(board[ny][nx]==2) {
                d=cd(d);
                int nny=y+dy[d],nnx=x+dx[d];   
                if(board[nny][nnx]==2) ret=move(0,y,x,tmp,d);
                else ret=move(board[nny][nnx],nny,nnx,tmp,d);

            }else{
                ret=move(board[ny][nx],ny,nx,tmp,d);
            }
            if(ret) {
                printf("%d",ans);
                return 0;
            }
        }
    }
    puts("-1");
}
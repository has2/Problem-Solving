#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,pair<int,int>>> v;
int R,C,board[501][501],cnt[501][501];
int dy[8] = {-1,1,0,0,1,-1,1,-1};
int dx[8] = {0,0,1,-1,1,-1,-1,1};
pair<int,int> dest[501][501];
pair<int,int> sol(int y,int x){
    int minV=4e5,my,mx;
    for(int i=0;i<8;i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<1||nx<1||ny>R||nx>C) continue;
        if(board[ny][nx] < minV){
            minV=board[ny][nx];
            my=ny;
            mx=nx;
        }
    }
    if(board[y][x] > minV){
        if(dest[my][mx].first!=0) return dest[y][x] = dest[my][mx];
        return dest[y][x] = sol(my,mx);
    }
    return dest[y][x]={y,x};
}
int main(){
    scanf("%d%d",&R,&C);
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++){
            scanf("%d",&board[i][j]);
            v.push_back({board[i][j],{i,j}});
        }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(auto p : v){
        auto [y,x] = p.second;
        if(dest[y][x].first==0) sol(y,x);
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            auto [y,x] = dest[i][j];
            cnt[y][x]++;
        }
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            printf("%d ",cnt[i][j]);
        }
        puts("");
    }   
}
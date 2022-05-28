#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int dy[4]={-1,1,0,0},N,M;
int dx[4]={0,0,1,-1};
pair<int,int> sol(int y,int x,int ty,int tx,vector<vector<int>> board){
    if(!board[y][x]) return {0,0};
    int minv=1e9,maxv=-1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=N||nx>=M||!board[ny][nx]) continue;
        auto b = board;
        b[y][x]=0; 
        auto [w,c] = sol(ty,tx,ny,nx,b);
        if(w) maxv = max(maxv,c);
        else minv = min(minv,c);
    }
    if(minv!=1e9) return {1,minv+1};
    if(maxv!=-1) return {0,maxv+1};
    return {0,0};
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N=board.size();
    M=board[0].size();
    return sol(aloc[0],aloc[1],bloc[0],bloc[1],board).second;
}
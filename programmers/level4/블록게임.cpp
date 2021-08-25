#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;
int dy1[6]={0,0,0,1,1,1};
int dx1[6]={0,1,2,0,1,2};
int dy2[6]={0,1,2,0,1,2};
int dx2[6]={0,0,0,1,1,1};
int N;
map<int,vector<pair<int,int>>> block,empt;
vector<vector<int>> board;
bool check(int c,vector<pair<int,int>> v){
    for(auto [y,x] : v){
        while(y>=0){
            if(board[y--][x]!=0) return 0;
        }
    }
    for(auto [y,x] : block[c]) board[y][x]=0;
    return 1;
}
int solution(vector<vector<int>> _board) {
    int answer = 0;
    board=_board;
    N=board.size();
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) 
            if(board[i][j]>0) block[board[i][j]].push_back({i,j});

    for(auto [v,mp] : block){
        for(int i=0;i<N-1;i++){
            for(int j=0;j<N-2;j++){
                vector<pair<int,int>> tmp;
                int cnt=0;
                for(int d=0;d<6;d++){
                    int ny=i+dy1[d];
                    int nx=j+dx1[d];
                    if(board[ny][nx]==v) cnt++;
                    else tmp.push_back({ny,nx});
                }
                if(cnt==4) empt[v]=tmp;
            }
        }
    }
    for(auto [v,mp] : block){
        for(int i=0;i<N-2;i++){
            for(int j=0;j<N-1;j++){
                vector<pair<int,int>> tmp;
                int cnt=0;
                for(int d=0;d<6;d++){
                    int ny=i+dy2[d];
                    int nx=j+dx2[d];
                    if(board[ny][nx]!=v) tmp.push_back({ny,nx});
                    else cnt++;
                }
                if(cnt==4) empt[v]=tmp;
            }
        }
    }
    bool ok=1;
    vector<bool> erased(201,0);
    while(ok){
        ok=0;
        for(auto [c,v] : empt){
            if(erased[c]) continue;
            if(check(c,v)){
                erased[c]=1;
                ok=1;    
                answer++;
            }
        }
    }
    return answer;
}
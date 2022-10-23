#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
char board[6][6];
vector<pair<int,int>> p,s;
bool check(){
    for(auto [y,x] : s){
        for(int i=0;i<4;i++){
            int cy=y,cx=x;
            while(cy>=0&&cx>=0&&cy<N&&cx<N&&board[cy][cx]!='O'){
                if(board[cy][cx]=='T') return false;
                cy+=dy[i],cx+=dx[i];
            }
        }   
    }
    return true;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf(" %c",&board[i][j]);
            if(board[i][j]=='X') p.push_back({i,j});
            if(board[i][j]=='S') s.push_back({i,j});
        }
    }
    int M = p.size();
    for(int i=0;i<M-2;i++){
        for(int j=i+1;j<M-1;j++){
            for(int k=j+1;k<M;k++){
                auto [y1,x1] = p[i];
                auto [y2,x2] = p[j];
                auto [y3,x3] = p[k];
                board[y1][x1] = board[y2][x2] = board[y3][x3] = 'O';
                if(check()) {
                    puts("YES");
                    return 0;
                }
                board[y1][x1] = board[y2][x2] = board[y3][x3] = 'X';
            }
        }
    }
    puts("NO");
}
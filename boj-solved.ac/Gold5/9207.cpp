#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int tc,dy[4]={-1,1,0,0},dx[4]={0,0,1,-1},ans,ansc;
void sol(vector<string> b,set<pair<int,int>> p,int cnt){
    if(ans>p.size()){
        ans=p.size();
        ansc=cnt;
    }else if(ans==p.size() && ansc>cnt) ansc=cnt;
    for(auto [y,x] : p){
        for(int i=0;i<4;i++){
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=5||nx>=9||b[ny][nx]!='o') continue;
            int nny=ny+dy[i],nnx=nx+dx[i];
            if(nny<0||nnx<0||nny>=5||nnx>=9||b[nny][nnx]!='.') continue;
            auto tb=b;
            auto tp=p; 
            tb[y][x]='.';
            tb[ny][nx]='.';
            tb[nny][nnx]='o';
            tp.insert({nny,nnx});
            tp.erase({ny,nx});
            tp.erase({y,x});
            sol(tb,tp,cnt+1);
        }
    }
}
int main(){
    cin >> tc;
    while(tc--){
        ans=9e8,ansc=9e8;
        vector<string> board;
        set<pair<int,int>> p;
        for(int i=0;i<5;i++){
            string s;
            cin >> s;
            board.push_back(s);
            for(int j=0;j<s.size();j++){
                if(s[j]=='o') p.insert({i,j});
            }
        }
        sol(board,p,0);
        cout << ans << " " << ansc << "\n";
    }
}

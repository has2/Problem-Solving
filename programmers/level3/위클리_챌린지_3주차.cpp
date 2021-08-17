#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using vvi=vector<vector<int>>;
const int dy[4]={-1,1,0,0}, dx[4]={0,0,1,-1}, inf = 9e8;
vector<vvi> shapes[4],shapes_tb;
bool visit[50][50];
int N,l,r,u,d,scnt,ans;
vector<pair<int,int>> p;
void init(){
    u=l=inf;
    d=r=-inf;
    p.clear();    
}
vvi rotate(vvi& org){
    int r = org[0].size();
    int c = org.size();
    vvi ret = vvi(r,vector<int>(c));

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            ret[i][j]=org[c-j-1][i];

    return ret;
}
void dfs(int y,int x,int k,vvi& b){
    visit[y][x]=1;
    p.push_back({y,x});
    l=min(l,x),r=max(r,x);
    u=min(u,y),d=max(d,y);

    for(int i=0;i<4;i++){
        int ny=y+dy[i],  nx=x+dx[i];
        if(ny<0||nx<0||ny>=N||nx>=N||b[ny][nx]!=k||visit[ny][nx]) continue;
        dfs(ny,nx,k,b);
    }
}
int match(vvi& a,vvi& b){
    if(a.size()!=b.size() || a[0].size() != b[0].size()) return -1;
    int ret=0;
    for(int i=0;i<a.size();i++)
        for(int j=0;j<a[0].size();j++){
            if(a[i][j]+b[i][j]!=1) return -1; 
            ret+=a[i][j];
        }
    return ret;
}
int solution(vvi board,vvi table) {

    N=board.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!board[i][j] && !visit[i][j]){
                init();
                dfs(i,j,0,board);
                int row = d-u+1, col = r-l+1;
                vvi shape = vvi(row,vector<int>(col,1));
                for(auto& v : p) shape[v.first-u][v.second-l]=0;

                for(int k=0;k<4;k++){
                    shapes[k].push_back(shape);
                    shape=rotate(shape);
                }
            }
        }
    }
    memset(visit,0,sizeof(visit));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(table[i][j] && !visit[i][j]){
                init();
                dfs(i,j,1,table);
                int row = d-u+1, col = r-l+1;
                vvi shape = vvi(row,vector<int>(col,0));
                for(auto& v : p) shape[v.first-u][v.second-l]=1;
                shapes_tb.push_back(shape);
            }
        }
    }
    vector<bool> filled(shapes[0].size());
    for(auto stb : shapes_tb){
        for(int i=0;i<shapes[0].size();i++){
            if(filled[i]) continue;
            bool ok=false;
            for(int j=0;j<4;j++){
                int ret = match(stb,shapes[j][i]);
                if(ret!=-1){
                    ok=true;
                    ans+=ret;
                    filled[i]=true;
                    break;
                }
            }
            if(ok) break;
        }
    }
    return ans;
}
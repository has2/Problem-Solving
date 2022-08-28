#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N,board[21][21],ans;
set<int> fav[401];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};
struct P{
    int f,e;
    pair<int,int> pos;
};
bool cmp1(P& u,P& v){
    return u.f > v.f; 
}
bool cmp2(P& u,P& v){
    return u.e > v.e; 
}
bool cmp3(P& u,P& v){
    return u.pos < v.pos; 
}
void sol(int n){
    vector<P> v;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]) continue;
            int f=0,e=0;
            for(int k=0;k<4;k++){
                int ny=i+dy[k],nx=j+dx[k];
                if(ny<0||nx<0||ny>=N||nx>=N) continue;
                if(board[ny][nx]==0) e++;
                else if(fav[n].find(board[ny][nx])!=fav[n].end())f++;
            }
            v.push_back({f,e,{i,j}});
        }
    }
    sort(v.begin(),v.end(),cmp1);
    vector<P> v2;
    for(auto p : v){
        if(v[0].f!=p.f) break;
        v2.push_back(p);
    }
    if(v2.size()==1) {
        board[v2[0].pos.first][v2[0].pos.second] = n;
        return;
    }
    sort(v2.begin(),v2.end(),cmp2);
    vector<P> v3;
    for(auto p : v2){
        if(v2[0].e!=p.e) break;
        v3.push_back(p);
    }    
    if(v3.size()==1) {
        board[v3[0].pos.first][v3[0].pos.second] = n;
        return;
    }
    sort(v3.begin(),v3.end(),cmp3);
    board[v3[0].pos.first][v3[0].pos.second] = n;
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N*N;i++){
        int n,v;
        scanf("%d",&n);
        for(int j=0;j<4;j++) {
            scanf("%d",&v);
            fav[n].insert(v);
        }
        sol(n);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int cnt=0;
            for(int k=0;k<4;k++){
                int ny=i+dy[k],nx=j+dx[k];
                if(ny<0||nx<0||ny>=N||nx>=N) continue;
                if(fav[board[i][j]].find(board[ny][nx])!=fav[board[i][j]].end()) cnt++;
            }
            if(cnt==1) ans+=1;
            if(cnt==2) ans+=10;
            if(cnt==3) ans+=100;
            if(cnt==4) ans+=1000;
        }        
    }
    printf("%d",ans);
}
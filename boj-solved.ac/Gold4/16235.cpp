#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,K;
long long ans;
int dy[8] = {1,-1,0,0,1,1,-1,-1};
int dx[8] = {0,0,1,-1,1,-1,-1,1};
vector<long long> tree[101][101];;
int A[101][101],yb[101][101],seed[101][101];
void feed(int y,int x){
    auto& tr = tree[y][x];
    vector<long long> tt;
    int tyb=0;
    for(int i=0;i<tr.size();i++){
        int age = tr[i];
        if(yb[y][x] >= age){
            yb[y][x]-=age;
            tt.push_back(age+1);
        }else{
            tyb += age/2;
        }        
    }
    tr = tt;
    yb[y][x] += tyb;
}

void expd(int y,int x){
    auto& tr = tree[y][x];
    for(int i=0;i<tr.size();i++){
        int age = tr[i];
        if(age%5==0){
            for(int i=0;i<8;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny < 1 || nx < 1 || ny > N || nx > N) continue;
                seed[ny][nx]++;
            }   
        }        
    }
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) {
            scanf("%d",&A[i][j]);
            yb[i][j] = 5;
        }
    for(int i=0;i<M;i++){
        int y,x,z;
        scanf("%d%d%d",&x,&y,&z);
        tree[x][y].push_back(z);
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) sort(tree[i][j].begin(),tree[i][j].end());
        
    while(K--){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                feed(i,j);
                seed[i][j]=0;
            }
        }
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++) expd(i,j);

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                for(int k=0;k<seed[i][j];k++) tree[i][j].push_back(1);
                sort(tree[i][j].begin(),tree[i][j].end());
                yb[i][j] += A[i][j];
                if(K==0) ans += tree[i][j].size();
            }
        }
    }
    printf("%d",ans);
}
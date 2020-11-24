#include <cstdio>
using namespace std;
int N,M,d[1001];
bool adj[201][201],visit[201];
void dfs(int n){
    visit[n] = 1;
    for(int i=1;i<=N;i++)
        if(adj[n][i] && !visit[i]) dfs(i);
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) scanf("%d",&adj[i][j]);
    for(int i=0;i<M;i++) scanf("%d",&d[i]);
    dfs(d[0]);
    for(int i=0;i<M;i++) {
        if(!visit[d[i]]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}
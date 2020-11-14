#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int N,K,a[30];
bool dp[31][15001];
void sol(int cur,int w){
    if(dp[cur][w]) return; 
    dp[cur][w] = 1;
    if(cur==N) return;
    sol(cur+1,w+a[cur]);
    sol(cur+1,abs(w-a[cur]));
    sol(cur+1,w);
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    
    sol(0,0);
    scanf("%d",&K);
    while(K--){
        int v;
        scanf("%d",&v);
        bool ok =0;
        if(v<=15000){
            for(int i=1;i<=N;i++){
                if(dp[i][v]) {
                    printf("Y ");
                    ok=1;
                    break;
                }
            }
        }
        if(!ok) printf("N ");
    }
}

#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
int N,S,k,z;
const int mxN = 4e6;
vector<int> a[2];
ll dp[2][mxN+1],ans;
int main(){
    scanf("%d%d",&N,&S);
    for(int i=0;i<N;i++) {
        int v;
        scanf("%d",&v);
        if(v>0) a[0].push_back(v);
        else if(v<0) a[1].push_back(-v);
        else z++;
    }
    dp[0][0] = dp[1][0] = 1;
    k=2;
    while(k--){
        for(int i=0;i<a[k].size();i++){
            for(int j=mxN;j>=1;j--){
                if(j-a[k][i]>=0) dp[k][j] += dp[k][j-a[k][i]];
            }
        }
    }
    k=0;
    if(S<0){
        k=1;
        S=-S;
    }
    for(int i=1;i<=mxN;i++){
        if(!dp[k][i]) continue;
        if(S==i) ans+=dp[k][i];
        else if(S<i && i-S <= mxN && dp[1-k][i-S]) ans+=dp[k][i]*dp[1-k][i-S]; 
    }    
    if(z>0){
        ll h = (ll)1<<z;
        ans*=h;
        if(S==0) ans+=h-1; 
    }
    printf("%lld",ans);
}

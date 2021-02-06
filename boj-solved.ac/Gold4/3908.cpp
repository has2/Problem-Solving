#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> prime;
int T,n,k,dp[1121][15];
int main(){
    scanf("%d",&T);
    prime.push_back(2);
    for(int i=3;i<=1120;i++){
        bool ok=1;
        for(int j=2;j<i;j++){
            if(i%j==0) {
                ok=0;
                break;
            }
        }
        if(ok) prime.push_back(i);
    }
    printf("size:%d\n",prime.size());
    for(auto k : prime) printf("%d ",k);
    puts("");

    while(T--){
        scanf("%d%d",&n,&k);
        memset(dp,0,sizeof(dp));
        for(int j=0;j<prime.size();j++){
            if(prime[j]>n) break;
            for(int i=n;i>1;i--){
                if(i-prime[j] < 0) continue;
                if(i==prime[j]) {
                    dp[i][1]=1;
                    continue;
                }
                for(int l=2;l<=k;l++){
                    dp[i][l]+=dp[i-prime[j]][l-1];
                }
            }
        }
        printf("%d\n",dp[n][k]);
    }
    
}
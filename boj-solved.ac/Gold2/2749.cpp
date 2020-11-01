//gold2 1766
#include <cstdio>
#include <queue>
using namespace std;
const int a = 15e5;
int dp[a];
int main(){
    long long n;
    scanf("%lld",&n);
    int t = n%a;
    dp[1] = 1;
    for(int i=2;i<=t;i++){
        dp[i] = (dp[i-1]+dp[i-2])%1000000;
    }
    printf("%d",dp[t]);
}
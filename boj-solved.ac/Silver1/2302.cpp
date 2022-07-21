#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int N,M,dp[41],ans=1;
int sol(int n){
    if(n<=1) return 1;
    int& ret = dp[n];
    if(ret!=-1) return ret;
    ret=sol(n-1)+sol(n-2);
    return ret;
}
int main(){
    vector<int> v;
    scanf("%d%d",&N,&M);
    v.push_back(0);
    for(int i=0;i<M;i++) {
        int t;
        scanf("%d",&t);
        v.push_back(t);
    }
    v.push_back(N+1);
    memset(dp,-1,sizeof(dp));
    sol(N);
    for(int i=1;i<v.size();i++){
        int a = sol(v[i]-v[i-1]-1);
        if(a>0) ans*=a;
    }
    printf("%d",ans);
}
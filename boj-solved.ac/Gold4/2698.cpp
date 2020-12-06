#include <cstdio>
#include <cstring>
using namespace std;
int tc,N,K,dp[102][101][2];
int sol(int n,int k,int f){
    if(k<0) return 0;
    if(n==2){
        if(f==1) {
            if(k<2) return 1;
        }else{
            if(k==0) return 2;
        }
        return 0;
    }
    int& ret = dp[n][k][f];
    if(ret!=-1) return ret;
    ret = 0;
    if(f==0) ret += sol(n-1,k,1)+sol(n-1,k,0); 
    else ret += sol(n-1,k-1,1)+sol(n-1,k,0);
    return ret;
}

int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&N,&K);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",sol(N+1,K,0));
    }
}
    

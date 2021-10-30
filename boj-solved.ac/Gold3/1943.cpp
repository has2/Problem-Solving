#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int N,total,dp[50001];
pair<int,int> a[100];
int sol(){
    memset(dp,0,sizeof(dp));
    total=0;
    for(int i=0;i<N;i++) {
        scanf("%d%d",&a[i].first,&a[i].second);
        total+=a[i].first * a[i].second;
    }
    if(total%2) return 0;
    dp[0]=1;
    for(int i=0;i<N;i++){
        for(int j=total/2;j>=0;j--){
            if(dp[j]) continue;
            int cur=0;
            for(int k=0;k<a[i].second;k++){
                cur+=a[i].first;
                if(j-cur>=0)  dp[j]=dp[j-cur];     
                if(dp[total/2]) return 1;
            }
        }
    }
    return dp[total/2];
}
int main(){
    int tc=3;
    while(tc--) {
        scanf("%d",&N);
        printf("%d\n",sol());
    }
}
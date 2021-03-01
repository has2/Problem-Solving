#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int N,dp[400][400][400],v,inf=-8e7,as,bs;
vector<int> arr[2];
int sol(int n,int a,int b){
    if(a==as||b==bs) return 0;
    int& ret = dp[n][a][b];
    if(ret!=inf) return ret;
    ret=sol(n+1,a+1,b+1)+arr[0][a]*arr[1][b];
    if(N>n+as-a) ret=max(ret,sol(n+1,a,b+1));
    if(N>n+bs-b) ret=max(ret,sol(n+1,a+1,b));
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int j=0;j<2;j++){
        for(int i=0;i<N;i++){
            scanf("%d",&v);
            if(v!=0) arr[j].push_back(v);
        }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++) dp[i][j][k]=inf;
    as=arr[0].size(),bs=arr[1].size();
    printf("%d",sol(0,0,0));
}
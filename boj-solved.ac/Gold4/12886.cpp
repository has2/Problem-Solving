#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[3],dp[501][501],T,visit[501][501];
int sol(int a,int b){
    if(a<=0 || b<=0 || T-a-b<=0) return 0;
    if(a==b && a==T-a-b) return 1;
    if(visit[a][b]) return 0;
    visit[a][b]=1;
    int& ret = dp[a][b];
    if(ret!=-1) return ret;

    int tmp[3];
    int A=a,B=b,C=T-A-B;
    
    tmp[0]=2*A,tmp[1]=B-A,tmp[2]=C;
    sort(tmp,tmp+3);
    if(sol(tmp[0],tmp[1])) return ret=1;

    tmp[0]=A,tmp[1]=2*B,tmp[2]=C-B;
    sort(tmp,tmp+3);
    if(sol(tmp[0],tmp[1])) return ret=1;

    tmp[0]=2*A,tmp[1]=B,tmp[2]=C-A;
    sort(tmp,tmp+3);
    if(sol(tmp[0],tmp[1])) return ret=1;

    return ret=0;
}

int main(){
    for(int i=0;i<3;i++) {
        scanf("%d",&arr[i]);
        T+=arr[i];
    }
    sort(arr,arr+3);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(arr[0],arr[1]));
}
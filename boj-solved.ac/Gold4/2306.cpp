#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int dp[501][501];
char s[501];
int sol(int l,int r){
    if(l>=r) return 0;
    int& ret = dp[l][r];
    if(ret!=-1) return ret;
    ret = 0;
    if((s[l]=='g'&&s[r]=='c')||(s[l]=='a'&&s[r]=='t')) ret = 2+sol(l+1,r-1);
    for(int i=l;i<r;i++) ret = max(ret,sol(l,i)+sol(i+1,r));
    return ret;
}
int main(){
    scanf("%s",s);
    memset(dp,-1,sizeof(dp));
    printf("%d",sol(0,strlen(s)-1));
}
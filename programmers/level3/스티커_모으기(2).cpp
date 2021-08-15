#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N,dp[100002][2];
vector<int> sticker;
int sol(int n,int f){
    if(n>=N) return 0;
    if(n==N-1) return f ? 0 : sticker[N-1];
    int& ret = dp[n][f];
    if(ret!=-1) return ret;
    ret=max(sticker[n]+sol(n+2,f),sol(n+1,f));
    return ret;
}
int solution(vector<int> _sticker)
{
    sticker=_sticker;
    N=sticker.size();
    memset(dp,-1,sizeof(dp));
    return max(sol(1,0),sol(2,1)+sticker[0]);
}
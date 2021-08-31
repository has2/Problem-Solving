#include <vector>
#include <string>
#include <cstring>
using namespace std;
int dp[101][101][2],inf=9e8;
vector<string> arr;
int sol(int l,int r,int k){
    int& ret = dp[l][r][k];
    if(ret!=-1) return ret;
    if(k){
        ret=-inf;
        for(int i=l;i<=r;i++){
            int lv,rv;
            lv = l>i-1 ? stoi(arr[2*l]) : sol(l,i-1,1);
            if(i+1>r) rv = stoi(arr[2*r+2]);
            else if(arr[2*i+1]=="+") rv = sol(i+1,r,1);
            else rv = sol(i+1,r,0);

            if(arr[2*i+1]=="+") ret=max(lv+rv,ret);
            else ret=max(lv-rv,ret);
        }
    }else{
        ret=inf;
        for(int i=l;i<=r;i++){
            int lv,rv;
            lv = l>i-1 ? stoi(arr[2*l]) : sol(l,i-1,0);
            if(i+1>r) rv = stoi(arr[2*r+2]);
            else if(arr[2*i+1]=="+") rv = sol(i+1,r,0);
            else rv = sol(i+1,r,1);

            if(arr[2*i+1]=="+") ret=min(lv+rv,ret);
            else ret=min(lv-rv,ret);
        }        
    }
    return ret;
}

int solution(vector<string> _arr)
{
    memset(dp,-1,sizeof(dp));
    arr=_arr;
    return sol(0,arr.size()/2-1,1);
}
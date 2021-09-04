#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
vector<int> sales,tree[300001];
int dp[300001],inf=1<<31-1;
int sol(int n){
    if(tree[n].empty()) return 0;
    int& ret = dp[n];
    if(ret!=-1) return ret;

    ret=inf;
    int v=0;
    for(int nxt : tree[n]) v+=sol(nxt);
    ret=min(ret,v+sales[n-1]);
    for(int nxt : tree[n]){
        int t = v-sol(nxt);
        t+=sales[nxt-1];
        for(auto nnxt : tree[nxt]) {
            if(!tree[nnxt].empty()) t+=sol(nnxt);
        }
        ret=min(ret,t);
    }
    return ret;
}
int solution(vector<int> _s, vector<vector<int>> links) {
    sales = _s;
    memset(dp,-1,sizeof(dp));
    for(auto l : links) tree[l[0]].push_back(l[1]);
    return sol(1);
}
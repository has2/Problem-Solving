#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> matrix;
int dp[201][201];
int sol(int l,int r){
    if(l==r) return 0;
    int& ret = dp[l][r];
    if(ret!=-1) return ret;
    ret = 2e9;
    for(int i=l;i<r;i++) ret=min(ret,sol(l,i)+sol(i+1,r)+matrix[l][0]*matrix[i][1]*matrix[r][1]);
    return ret;
}
int solution(vector<vector<int>> matrix_sizes) {
    matrix=matrix_sizes;
    memset(dp,-1,sizeof(dp));
    return sol(0,matrix.size()-1);
}
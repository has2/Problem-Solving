#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
string a,b,c;
int dp[1001][1001];
int main(){
    cin >> a >> b;
    a='A'+a;
    b='B'+b;
    int n=a.size(), m=b.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0) continue;
            if(i==0){
                dp[i][j]=j;
                continue;
            }
            if(j==0){
                dp[i][j]=i;
                continue;
            }
            if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
        }
    }
    cout << dp[n-1][m-1] << endl;;
}
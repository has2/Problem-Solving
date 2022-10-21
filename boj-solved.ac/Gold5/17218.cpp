#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
string A,B;
int dp[41][41];
pair<int,int> par[41][41];
int main(){
    cin >> A >> B;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B.size();j++){
            if(A[i]==B[j]) {
                dp[i+1][j+1] = dp[i][j]+1;
                par[i+1][j+1] = {i,j};
            }else{
                if(dp[i+1][j] > dp[i][j+1]){
                    dp[i+1][j+1] = dp[i+1][j];
                    par[i+1][j+1] = {i+1,j};
                }else{
                    dp[i+1][j+1] = dp[i][j+1];
                    par[i+1][j+1] = {i,j+1};                    
                }
            }
        }
    }
    string ans;
    int i=A.size(),j=B.size();
    while(i!=0&&j!=0){
        if(A[i-1] == B[j-1]) ans+=A[i-1];
        auto v = par[i][j];
        i=v.first;
        j=v.second;
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
}
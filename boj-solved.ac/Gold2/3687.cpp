#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int tc,N;
long long dp[101]={0,0,1,7,4,2,6,8,10,};
int main(){
    cin >> tc;
    for(int i=9;i<101;i++){
        dp[i]=9e20;
        for(int j=2;j<=7;j++){
            long long v = dp[i-j]*10;
            if(j!=6) v+=dp[j];
            dp[i]=min(dp[i],v);
        }
    }
    while(tc--){
        cin >> N; 
        string maxv;
        cout << dp[N];
        if(N%2==0) {
            for(int i=0;i<N/2;i++) maxv+='1';
        }
        else{
            maxv+='7';
            for(int i=0;i<N/2-1;i++) maxv+='1';
        }
        cout << ' ' << maxv << '\n';
    }
}
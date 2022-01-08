#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N,M,K,ans;
string lamp[50];
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> lamp[i];
    cin >> K;
    for(int i=0;i<N;i++){
        auto s = lamp[i];
        int cnt=0;
        for(int j=0;j<M;j++) if(s[j]=='0') cnt++;
        if(cnt > K || cnt%2 != K%2) continue;
        int sameCnt=0;
        for(int j=0;j<N;j++) if(s==lamp[j]) sameCnt++; 
        ans=max(ans,sameCnt);
    }
    printf("%d",ans);
}
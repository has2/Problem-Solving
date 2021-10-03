#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int ans,N,a[300001],asc[300001],ascmax[300001];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);

    vector<int> dp = {a[0]};
    
    for(int i=1;i<N;i++){
        int idx = lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
        if(idx == dp.size()) dp.push_back(a[i]);
        else dp[idx]=a[i];
        asc[i]=dp.size();
        ascmax[i]=dp.back();
    }

    dp.clear();
    dp.push_back(a[N-1]);
    
    for(int i=N-2;i>=0;i--){
        int idx = lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
        if(idx == dp.size()) dp.push_back(a[i]);
        else dp[idx]=a[i];
        int v = dp.size()+asc[i];
        if(ascmax[i]==a[i] && dp.back()==a[i]) v--;
        ans=max(ans,v);        
    }
    printf("%d",ans==0?1:ans);
}
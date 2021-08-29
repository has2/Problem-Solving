#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
ll arr[90001],sum[90001],ans=-1;
int N;
ll solution(vector<vector<int> > land, int P, int Q) {
    N=land.size();
    int idx=1;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            arr[idx++]=land[i][j];
    N*=N;
    sort(arr,arr+N+1);
    for(int i=1;i<=N;i++) sum[i]=sum[i-1]+arr[i]; 
    int cur=-1;
    for(int i=1;i<=N;i++){
        if(arr[i]==cur) continue;
        cur=arr[i];
        ll v=0;
        v+=(sum[N]-sum[i-1]-arr[i]*(N-(i-1)))*Q;
        v+=(arr[i]*(i-1)-sum[i-1])*P;
        if(ans==-1 || ans > v) ans=v;
    }
    return ans;
}
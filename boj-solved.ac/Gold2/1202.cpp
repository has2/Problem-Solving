#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int mx = 300001;
int N,K,bag[mx];
pair<int,int> mv[mx];
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) scanf("%d%d",&mv[i].first,&mv[i].second);
    for(int i=0;i<K;i++) scanf("%d",&bag[i]);
    
    sort(mv,mv+N);
    sort(bag,bag+K);
    priority_queue<int> q;

    long long ans = 0;
    int cur = 0;
    for(int i=0;i<K;i++){
        for(;cur<N;cur++){
            if(mv[cur].first <= bag[i]) q.push(mv[cur].second);
            else break;
        }
        if(!q.empty()){
            ans += q.top();
            q.pop();
        }
    }
    printf("%lld",ans);
}
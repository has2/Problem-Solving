#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N,k;
pair<int,int> a[1000000];
struct P{
    int id,t,pos;
}; 
struct cmp{
    bool operator()(P& a,P& b){
        if(a.t > b.t) return true;
        else if(a.t == b.t){
            if(a.pos<b.pos) return true;
        }
        return false;
    }
};
int main(){
    scanf("%d%d",&N,&k);
    for(int i=0;i<N;i++) scanf("%d%d",&a[i].first,&a[i].second);
    priority_queue<P,vector<P>,cmp> pq;
    int i=0;
    for(;i<N&&i<k;i++) pq.push({a[i].first,a[i].second,i});
    vector<int> ans;
    for(;i<N;i++){
        auto [id,t,pos] = pq.top();
        vector<int> rp;
        while(!pq.empty() && pq.top().t==t){
            rp.push_back(pq.top().pos);
            ans.push_back(pq.top().id);
            pq.pop();
        }
        reverse(rp.begin(),rp.end());
        for(auto r : rp){
            pq.push({a[i].first,t+a[i].second,r});
            i++;
            if(i>=N) break;
        }
        i--;
    }
    while(!pq.empty()){
        auto [id,t,pos] = pq.top(); pq.pop();
        ans.push_back(id);
    }
    long long total=0;
    for(int i=1;i<=N;i++) total+=i*(long long)ans[i-1];
    printf("%lld",total); 
}
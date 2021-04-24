#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int N,a[500000],K;

struct cmp{
    bool operator()(pair<int,int> a,pair<int,int> b){
        if(a.first<b.first) return 1;
        else if(a.first==b.first) return a.second > b.second;
        return 0;
    }
};
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) scanf("%1d",&a[i]);
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    K=N-K;
    for(int i=0;i<N-K;i++) pq.push({a[i],i});
    int s=-1,e;
    for(int i=0;i<K;i++){
        e=N-K+i;
        pq.push({a[e],e});
        while(!pq.empty()){
            auto qt = pq.top(); pq.pop();
            if(qt.second>s) {
                s=qt.second;
                break;
            }
        }
        printf("%d",a[s]);
    }
}
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N,ans;
vector<int> a[10001];
int main(){ 
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int p,d;
        scanf("%d%d",&p,&d);
        a[d].push_back(p);
    }
    priority_queue<int> pq;
    for(int i=10000;i>0;i--){
        for(auto k : a[i]) pq.push(k);
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    }
    printf("%d",ans);
}
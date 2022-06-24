#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int N,K;
ll v[4];
priority_queue<int> pq[4];
struct P{
    int idx,l;
};
bool cmp(P& a,P& b){
    return (a.l+v[a.idx])*v[b.idx] > (b.l+v[b.idx])*v[a.idx];
}
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<4;i++) scanf("%d",&v[i]);
    while(N--){
        char c;
        int l;
        scanf(" %c %d",&c,&l);
        pq[c-'A'].push(l);
    }
    while(K--){
        vector<P> t;
        for(int i=0;i<4;i++){
            if(pq[i].empty()) continue;
            t.push_back({i,pq[i].top()});
        }
        sort(t.begin(),t.end(),cmp);
        auto [idx,l] = t[0];
        pq[idx].pop();
        v[idx]+=l;
        printf("%c %d\n",idx+'A',l);
    }
}
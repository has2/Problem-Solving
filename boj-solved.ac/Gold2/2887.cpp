#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct P{
    int idx,x,y,z;
};
struct D{
    int u,v,d;
};
vector<P> p;
struct cmp{
    bool operator()(D& a,D& b){
        return a.d > b.d;
    }
};
priority_queue<D,vector<D>,cmp> q;
int N,uf[100000];
int find(int x){
    if(x==uf[x]) return x;
    return uf[x] = find(uf[x]);
}

bool merge(int x,int y){
    int px = find(x);
    int py = find(y);
    if(px==py) return 0;
    uf[px] = find(py);
    return 1;
}

int main(){
    
    scanf("%d",&N);
    p.resize(N);
    for(int i=0;i<N;i++) {
        p[i].idx = i;
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
    }
    sort(p.begin(),p.end(),[](P& a,P& b){return a.x < b.x;});
    for(int i=0;i<N-1;i++) q.push({p[i+1].idx,p[i].idx,p[i+1].x-p[i].x});
    sort(p.begin(),p.end(),[](P& a,P& b){return a.y < b.y;});
    for(int i=0;i<N-1;i++) q.push({p[i+1].idx,p[i].idx,p[i+1].y-p[i].y});
    sort(p.begin(),p.end(),[](P& a,P& b){return a.z < b.z;});
    for(int i=0;i<N-1;i++) q.push({p[i+1].idx,p[i].idx,p[i+1].z-p[i].z});

    for(int i=0;i<N;i++) uf[i] = i;
    long long ans = 0; 
    int cnt = 0;
    for(int i=0;;i++){
        D qt = q.top(); q.pop();
        if(merge(qt.u,qt.v)){
            ans+=qt.d;
            if(++cnt==N-1) break;
        }
    }
    printf("%lld",ans);
}
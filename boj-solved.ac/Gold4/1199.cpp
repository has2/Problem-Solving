#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct edge{
    int a,b,cost;
};
int V,E,uf[10001];
vector<edge> eg;
bool cmp(edge& a,edge& b){
    return a.cost < b.cost;
}

int find(int a){
    if(uf[a]==a) return a;
    return uf[a] = find(uf[a]);
}

bool merge(int a,int b){
    int pa = find(a);
    int pb = find(b);
    if(pa==pb) return 0;
    uf[pa] = pb;
    return 1;
}
int main(){
    scanf("%d%d",&V,&E);
    for(int i=0;i<E;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        eg.push_back({a,b,c});
    }
    sort(eg.begin(),eg.end(),cmp);
    for(int i=1;i<=V;i++) uf[i] = i;
    int cnt = 0, ans = 0;
    for(int i=0;;i++){
        edge e = eg[i];
        if(merge(e.a,e.b)){
            ans+=e.cost;
            if(++cnt==V-1) break;
        }
    }
    printf("%d",ans);
}
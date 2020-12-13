#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int N,M,uf[1001],cnt;
double ans;
ll x[1001],y[1001];
double dist(int a,int b){
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

int find(int a){
    if(uf[a]==a) return a;
    return uf[a] = find(uf[a]);
}
bool merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return 0;
    uf[a] = b;
    return 1;
}
struct edge{
    int u,v;
    double d;
};
vector<edge> egs;
bool cmp(edge& a,edge& b){
    return a.d < b.d;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d%d",&x[i],&y[i]);
        uf[i]=i;
    }
    for(int i=0;i<M;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(merge(u,v)){
            cnt++;
        }
    }    
    for(int i=1;i<N;i++)
        for(int j=i+1;j<=N;j++)
            egs.push_back({i,j,dist(i,j)});
    sort(egs.begin(),egs.end(),cmp);
    for(int i=0;i<egs.size();i++){
        if(merge(egs[i].u,egs[i].v)){
            ++cnt;
            ans+=egs[i].d;
        }
        if(cnt==N-1) break;
    }
    printf("%.2f",ans);
}
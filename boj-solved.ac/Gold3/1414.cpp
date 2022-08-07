#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;
struct P{
    int u,v,d;
};
int N,uf[51],total;
vector<P> a;
bool cmp(P& l ,P& r){
    return l.d < r.d;
}
int find(int n){
    if(uf[n]==n) return n;
    return uf[n] = find(uf[n]);
}
bool merge(int u,int v){
    u = find(u);
    v = find(v);
    if(u==v) return 0;
    uf[u] = v;
    return 1; 
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int d=1;
            char c;
            scanf(" %c",&c);
            if(c=='0') continue;
            if(islower(c)) {
                d+=c-'a';
            }else{
                d+=26;
                d+=c-'A';
            }
            total+=d;
            if(i==j) continue;
            a.push_back({i,j,d});
        }
    }
    memset(uf,-1,sizeof(uf));
    for(int i=0;i<N;i++) uf[i]=i;
    sort(a.begin(),a.end(),cmp);
    int cnt=0,sum=0;
    for(int i=0;i<a.size();i++){
        auto [u,v,d] = a[i];
        if(merge(u,v)){
            sum+=d;
            if(++cnt==N-1) break;
        }
    }
    if(cnt<N-1) {
        puts("-1");
        return 0;
    }
    printf("%d",total-sum);
}
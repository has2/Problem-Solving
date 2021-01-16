#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,uf[1001];
struct P{int a,b,c;};
vector<P> v;
int find(int a){
    if(uf[a]==a) return a;
    return uf[a]=find(uf[a]);
}
bool merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return 0;
    uf[a]=b;
    return 1;
}

int ksk(){
    for(int i=0;i<=N;i++) uf[i]=i;

    int cnt=0,ret=0;
    for(int i=0;i<v.size();i++){
        if(merge(v[i].a,v[i].b)){
            if(v[i].c==0) ret++;
            if(++cnt==N) break;
        }
    }
    return ret*ret;
}

int main(){
    scanf("%d%d",&N,&M);
    M++;
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end(),[](P& u,P& v)->bool{
        return u.c<v.c;
    });
    int ans = ksk();

    sort(v.begin(),v.end(),[](P& u,P& v)->bool{
        return u.c>v.c;
    });
    ans -= ksk();
    printf("%d",ans);
}

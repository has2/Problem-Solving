#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct P{
    int a,b,c;
};
int N,uf[1001];
vector<P> vec;
int find(int a){
    if(a==uf[a]) return a;
    return uf[a] = find(uf[a]);
}
bool merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return 0;
    uf[a]=b;
    return 1;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int v;
            scanf("%d",&v);
            if(i<j) vec.push_back({i,j,v});
        }
    }
    sort(vec.begin(),vec.end(),[](P& u,P& v)->bool{
        return u.c<v.c;
    });
    for(int i=0;i<N;i++) uf[i]=i;
    int cnt=0;
    long long ans=0;
    for(int i=0;i<vec.size();i++){
        auto k = vec[i];
        if(merge(k.a,k.b)){
            ans+=k.c;
            if(++cnt==N-1) break;
        }
    }
    printf("%lld",ans);
}

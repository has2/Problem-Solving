#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,T;
vector<pair<int,int>> v;
int main(){
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++) {
        int w,p;
        scanf("%d%d",&w,&p);
        v.push_back({p,w});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    long long ans=0;
    for(int i=0;i<N;i++){
        auto [p,w] = v[i];
            ans+=w+(long long)p*(T-i-1);
    }
    printf("%lld",ans);
}
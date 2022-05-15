#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct P{
    int s,e;
};
int N,ans;
vector<pair<int,int>> a;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int t,s,e;
        scanf("%d%d%d",&t,&s,&e);
        a.push_back({s,1});
        a.push_back({e,-1});
    }
    sort(a.begin(),a.end());
    int cur=0;
    for(auto [v,m] : a){
        cur+=m;
        ans=max(cur,ans);
    }
    printf("%d",ans);
}
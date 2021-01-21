#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int N,v[20001],cycle[20001];
ll gcd(ll a,ll b){
    ll c;
    if(a<b) swap(a,b);
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&v[i]);
    for(int i=1;i<=N;i++){
        if(cycle[i]!=0) continue;
        int k=i,cnt=1;
        vector<int> l;
        l.push_back(k);
        if(v[k]==i) cnt=0;
        while(v[k]!=i){
            k=v[k];
            l.push_back(k);
            cnt++;
        }
        for(int w : l) cycle[w]=cnt;
    }
    sort(v+1,v+1+N);
    ll ans=1;
    for(int i=1;i<=N;i++) {
        if(cycle[i]!=0) ans = lcm(ans,cycle[i]); 
    }
    printf("%lld",ans);
}
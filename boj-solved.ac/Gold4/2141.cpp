#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
int N;
pair<ll,ll> xa[100001];

int main(){
    scanf("%d",&N);
    ll sum=0;
    for(int i=1;i<=N;i++) {
        scanf("%lld%lld",&xa[i].first,&xa[i].second);
        sum+=xa[i].second;
    }
    sort(xa+1,xa+N+1);

    ll cur=0;
    for(int i=1;i<=N;i++){
        cur+=xa[i].second;
        if(cur>=(sum+1)/2) {
            printf("%d",xa[i].first);
            break;
        }
    }
}
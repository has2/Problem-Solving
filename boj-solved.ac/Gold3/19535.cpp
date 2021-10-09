#include <cstdio>
#include <vector>
using namespace std;
int N;
int acnt[300001];
vector<pair<int,int>> p;
int main(){
    scanf("%d",&N);
    for(int i=1;i<N;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        acnt[u]++, acnt[v]++;
        p.push_back({u,v});
    }
    long long a=0,b=0;
    for(auto [u,v] : p) a+=(acnt[u]-1)*(acnt[v]-1);
    for(int i=1;i<=N;i++) if(acnt[i]>=3) b+=(acnt[i]*(acnt[i]-1)*(acnt[i]-2))/6;
    b*=3;
    if(a>b) puts("D");
    else if(a<b) puts("G");
    else puts("DUDUDUNGA");
}
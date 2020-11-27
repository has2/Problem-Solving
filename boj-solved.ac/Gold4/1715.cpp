#include <cstdio>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    int N,a,ret=0;
    scanf("%d",&N);
    while(N--) scanf("%d",&a), pq.push(-a);
    while(pq.size()>1){
        int u,v;
        u=pq.top(); pq.pop();
        v=pq.top(); pq.pop();
        ret+=-u-v;
        pq.push(u+v);
    }
    printf("%d",ret);
}
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
pair<int,int> a[200000];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d%d",&a[i].first,&a[i].second);
        M=max(M,a[i].first);
    }
    int ans=0;
    sort(a,a+N);
    priority_queue<int> pq;
    int j=N-1;
    for(int i=M;i>=1;i--){
        for(;j>=0&&a[j].first>=i;j--) pq.push(a[j].second);
        if(!pq.empty()) {
            ans+=pq.top();
            pq.pop();
        }
    }
    printf("%d",ans);
}
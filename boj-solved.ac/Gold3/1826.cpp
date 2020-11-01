#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int N,e,s,ans;
pair<int,int> info[10001];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d%d",&info[i].first,&info[i].second);
    scanf("%d%d",&e,&s);
    sort(info,info+N);
    priority_queue<int> pq;
    int idx = 0;
    while(s < e){
        while(idx < N && info[idx].first <= s){
            pq.push(info[idx].second);
            idx++;
        }
        if(pq.empty()){
            puts("-1");
            return 0;
        }
        s+=pq.top(); pq.pop();
        ans++;
    }
    printf("%d",ans);
}
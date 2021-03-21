#include <cstdio>
#include <queue>
using namespace std;
int N,K,visit[100001];
int main(){
    scanf("%d%d",&N,&K);

    queue<int> q;
    q.push(N);
    int t=0,ans=0;
    while(!q.empty()){
       
        int sz=q.size();   
        while(sz--){
            int cur=q.front(); q.pop();
            if(cur==K) ans++;
            
            for(auto nxt : {cur-1,cur+1,cur*2}){
                if(nxt<0 || nxt>1e5) continue;
                if(!visit[nxt] || visit[nxt]==visit[cur]+1){
                    visit[nxt]=visit[cur]+1;
                    q.push(nxt);
                }
            }
        }
        if(ans>0) break;
        t++;
    }
    printf("%d\n%d",t,ans);
}
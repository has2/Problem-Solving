#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int s,e,visit[100001];
void prt(int n){
    if(n==-2) return;
    prt(visit[n]);
    printf("%d ",n);
}
int main(){
    scanf("%d%d",&s,&e);
    memset(visit,-1,sizeof(visit));
    queue<int> q;
    visit[s] = -2;
    q.push(s);
    int cnt = 0;
    while(!q.empty()){
        
        int qsz = q.size();
        while(qsz--){
            int cur = q.front(); q.pop();
            if(cur==e){
                printf("%d\n",cnt);
                prt(cur);
                return 0;
            }

            int nxt;
            if(cur+1<=100000) {
                nxt = cur+1;
                if(visit[nxt]==-1){
                    visit[nxt]=cur;
                    q.push(nxt);
                }
            }
            if(cur-1>=0) {
                nxt = cur-1;
                if(visit[nxt]==-1){
                    visit[nxt]=cur;
                    q.push(nxt);
                }
            }
            if(cur*2<=100000) {
                nxt = cur*2;
                if(visit[nxt]==-1){
                    visit[nxt]=cur;
                    q.push(nxt);
                }
            }            
        }
        cnt++;
    }
}


#include <cstdio>
#include <queue>
using namespace std;
int n,par[1000001];
bool visit[1000001];
void prt(int k){
    if(k==0) return;
    prt(par[k]);
    printf("%d ",k);
}
int main(){
    scanf("%d",&n);
    queue<int> q;
    q.push(n);
    visit[n]=1;
    int cnt=0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int cur = q.front(); q.pop();
            int nxt;
            if(cur==1){
                printf("%d\n",cnt);
                prt(1);
                return 0;
            }
            if(cur%3==0) {
                nxt=cur/3;
                if(!visit[nxt]){
                    visit[nxt]=1;
                    par[nxt]=cur;
                    q.push(nxt);
                }
            }
            if(cur%2==0) {
                nxt=cur/2;
                if(!visit[nxt]){
                    visit[nxt]=1;
                    par[nxt]=cur;
                    q.push(nxt);    
                }        
            }
            if(cur-1>0){
                nxt=cur-1;
                if(!visit[nxt]){
                    visit[nxt]=1;
                    par[nxt]=cur;
                    q.push(nxt);                       
                }
            }
        }
        cnt++;
    }
}
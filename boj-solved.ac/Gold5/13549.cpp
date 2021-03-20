#include <cstdio>
#include <queue>
using namespace std;
int N,K;
bool visit[100001];
queue<int> q;
void push(int k){
    while(k<=1e5){
        if(!visit[k]){
            visit[k]=1;
            q.push(k);
        }
        if(k==0) return;
        k*=2;
    }
}
int main(){
    scanf("%d%d",&N,&K);
    push(N);
    int cnt=0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int cur = q.front(); q.pop();
            if(cur==K){
                printf("%d",cnt);
                return 0;
            }
            int k;
            if(cur+1<=1e5) {
                k=cur+1;
                push(k);
            }
            if(cur-1>=0){
                k=cur-1;
                push(k);
            }
        }
        cnt++;
    }
}
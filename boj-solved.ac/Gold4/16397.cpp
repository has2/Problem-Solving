#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
const int mxN=1e5;
int N,T,G;
bool visit[mxN];
int main(){
    scanf("%d%d%d",&N,&T,&G);
    queue<int> q;
    q.push(N);
    visit[N]=1;

    int cnt = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int qf = q.front(); q.pop();
            if(qf==G) {
                printf("%d",cnt);
                return 0;
            }
            if(qf+1<mxN){
                if(!visit[qf+1]) {
                    visit[qf+1]=1;
                    q.push(qf+1);
                }
            }
            if(qf*2<mxN){
                int t=0;
                if(qf*2!=0){
                    string a = to_string(qf*2);
                    a[0]--;
                    t = stoi(a);
                }
                if(!visit[t]){
                    visit[t]=1;
                    q.push(t);
                }
            }
        }
        cnt++;
        if(cnt>T) break;
    }
    puts("ANG");
}
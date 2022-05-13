#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int tc,N,a[]={10,-10,1,-1},visit[80];
vector<int> bfs(int k,int m){
    memset(visit,0,sizeof(visit));
    queue<vector<int>> q;
    visit[0]=1;
    q.push({0,0,0,0,0});
    while(1){
        int sz = q.size(); 
        while(sz--){
            auto cur = q.front(); q.pop();
            if(cur[4]==m) {
                vector<int> r = {k};
                for(int i=0;i<4;i++) r.push_back(cur[i]);
                return r;
            }
            for(int i=0;i<4;i++){
                int nxt = cur[4]+a[i];
                if(nxt<0 || nxt>70 || visit[nxt]) continue;
                visit[nxt]=1;
                auto nv = cur;
                nv[i]++;
                nv[4]=nxt;
                q.push(nv);
            }
        }
    }
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);

        int k = N/60;
        int mod = N%60;

        auto ret1 = bfs(k,mod);
        int cnt1=0;
        for(int i=0;i<5;i++) cnt1+=ret1[i];

        auto ret2 = bfs(k+1,60-mod);
        int cnt2=0;
        for(int i=0;i<5;i++) cnt2+=ret2[i];
        swap(ret2[1],ret2[2]);
        swap(ret2[3],ret2[4]);

        if(cnt1>cnt2){
            for(int i=0;i<5;i++) printf("%d ",ret2[i]);
        }else{
            for(int i=0;i<5;i++) printf("%d ",ret1[i]);
        }
        puts("");
    }
}
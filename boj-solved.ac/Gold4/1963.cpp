#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int T,a,b;
bool visit[10000],prime[10000];
int main(){
    
    prime[1]=1;
    for(int i=2;i<10000;i++){
        if(prime[i]) continue;
        for(int j=i*2;j<10000;j+=i) prime[j]=1;
    }
    scanf("%d",&T);
    while(T--){
        
        scanf("%d%d",&a,&b);
        memset(visit,0,sizeof(visit));

        queue<int> q;
        q.push(a);
        visit[a]=1;
        int cnt=0;
        bool ok=0;
        while(!q.empty()){

            int sz=q.size();
            while(sz--){

                int qf = q.front(); q.pop();
                if(qf==b){
                    printf("%d\n",cnt);
                    ok=1;
                    break;
                }
                string cur = to_string(qf);
                for(int i=0;i<cur.size();i++){
                    for(int j=0;j<10;j++){
                        if((i==0&&j==0) || (cur[i]-'0')==j) continue;
                        string nxt = cur;
                        nxt[i]=j+'0';
                        int ni= stoi(nxt);
                        if(prime[ni] || visit[ni]) continue;
                        visit[ni]=1;
                        q.push(ni);
                    }
                }
            }
            if(ok) break;
            cnt++;
        }
        if(!ok) puts("Impossible");
    }
}
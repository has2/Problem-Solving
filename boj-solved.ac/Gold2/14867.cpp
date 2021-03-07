#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int cap[2],tar[2];
set<int> memo[100001];
queue<pair<int,int>> q;
int main(){
    scanf("%d%d%d%d",&cap[0],&cap[1],&tar[0],&tar[1]);

    q.push({0,0});
    memo[0].insert(0);
    int ret=0;
    while(!q.empty()){

        int sz=q.size();
        while(sz--){
            auto qf = q.front(); q.pop();
            int v[2];
            v[0]=qf.first, v[1]=qf.second;
            if(v[0]==tar[0] && v[1]==tar[1]){
                printf("%d",ret);
                return 0;
            }
            for(int i=0;i<6;i++){
                int a,b;
                if(i==0) a=cap[0],b=v[1];
                else if(i==1) a=v[0],b=cap[1];
                else if(i==2) a=0,b=v[1];
                else if(i==3) a=v[0],b=0;
                else if(i==4) a=min(cap[0],v[0]+v[1]), b=v[1]-min(cap[0]-v[0],v[1]);
                else a=v[0]-min(cap[1]-v[1],v[0]),b=min(cap[1],v[1]+v[0]);

                if(memo[a].find(b) == memo[a].end()){
                    memo[a].insert(b);
                    q.push({a,b});
                }
            }
        }
        ret++;
    }
    puts("-1");
}
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int S,visit[1500][1500];
int main(){
    scanf("%d",&S);

    queue<pair<int,int>> q;
    visit[1][0]=1;
    q.push({1,0});
    int ans =0;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int a = q.front().first;
            int b = q.front().second; q.pop();
            if(a==S) {
                printf("%d",ans);
                return 0;
            }
            if(a-1>=0 && !visit[a-1][b]){
                visit[a-1][b]=1;
                q.push({a-1,b});
            }
            if(b>0 && a+b < 1500 && !visit[a+b][b]){
                visit[a+b][b]=1;
                q.push({a+b,b});
            }
            if(!visit[a][a]){
                visit[a][a]=1;
                q.push({a,a});
            }
        }
        ans++;
    }
}
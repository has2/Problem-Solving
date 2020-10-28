#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int n,k,s,e;
string a[1001];
vector<int> adj[1001];
int path[1001];
bool visit[1001];

void print(int v){
    if(v==0) return;
    print(path[v]);
    cout << v << " ";
}

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    cin >> s >> e;

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int cnt = 0;
            for(int l=0;l<k;l++){
                cnt += (a[i][l]-'0')^(a[j][l]-'0');
            }
            if(cnt==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    queue<int> q;
    q.push(s);
    visit[s] = 1;
    int ans = 0;
    while(!q.empty()){

        int qsz = q.size();
        while(qsz--){
            int qf = q.front(); q.pop();

            if(qf == e){
                print(e);
                return 0;
            }

            for(auto next : adj[qf]){
                if(!visit[next]){
                    q.push(next);
                    path[next] = qf;
                    visit[next] = 1;
                }
            }
        }
        ans++;
    }
    puts("-1");
}
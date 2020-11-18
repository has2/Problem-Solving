#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int N;
bool map[102][102];
int main(){
    scanf("%d",&N);
    for(int dc=0;dc<N;dc++){
        int x,y,d,g;
        scanf("%d%d%d%d",&x,&y,&d,&g);
        vector<int> seq(1);

        for(int i=0;i<g;i++){
            int sz = seq.size();
            for(int j=sz-1;j>=0;j--) seq.push_back((seq[j]+1)%4);
        }
        map[y][x] = 1;
        for(int v : seq) {
            v=(v+d)%4;
            y+=dy[v];
            x+=dx[v];
            map[y][x] = 1;
        }
    }

    int ans = 0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(map[i][j]&&map[i+1][j]&&map[i+1][j+1]&&map[i][j+1]) ans++;  
        }
    }
    printf("%d",ans);
}
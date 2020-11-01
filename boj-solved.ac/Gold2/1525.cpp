#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int visit[362881];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1},ans,a;
int perm[10];
int enc(string seq){
    int ret = 0;
    vector<bool> used(10);
    for(int i=0;i<9;i++) {
        int j = seq[i]-'0';
        used[j] = 1;
        int cnt = 0;
        for(int k=1;k<j;k++) if(!used[k]) cnt++;
        ret += perm[9-i-1]*cnt;
    }
    return ret+1;
}
int main(){
    
    perm[0]=1;
    for(int i=1;i<10;i++) perm[i] = perm[i-1]*i;
    string s;
    for(int i=0;i<9;i++) {
        scanf("%d",&a);
        if(a==0) a=9;
        s+=a+'0';
    }

    queue<int> q;
    visit[enc(s)] = stoi(s);
    q.push(enc(s));
    int ansenc = enc("123456789");
    while(!q.empty()){
        int qsz = q.size();
        while (qsz--){
            int qf = q.front(); q.pop();
            if(qf == ansenc){
                printf("%d",ans);
                return 0;
            }
            s = to_string(visit[qf]);

            int y, x;
            for (int i = 0; i < 9; i++){
                if (s[i] == '9'){
                    y = i / 3;
                    x = i % 3;
                    break;
                }
            }
            for(int i=0;i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny<0 || nx<0 || ny>=3 || nx>=3) continue;
                string tmp = s;
                swap(tmp[3*y+x],tmp[3*ny+nx]);
                int si = enc(tmp);

                if(!visit[si]){
                    visit[si] = stoi(tmp);
                    q.push(si);
                }
            }
        }
        ans++;
    }
    puts("-1");
}
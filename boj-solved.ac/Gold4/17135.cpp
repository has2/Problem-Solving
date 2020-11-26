#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
int N,M,D,ans,tt,total;
int dist(int sx,int ey,int ex){
    return ey+abs(ex-sx);
}
void fwd(vector<stack<int>>& s){
    for(int i=0;i<s.size();i++){
        stack<int> tmp;
        while(!s[i].empty()){
            tmp.push(s[i].top()-1); 
            s[i].pop();
        }
        while(!tmp.empty()){
            int t = tmp.top(); tmp.pop();
            if(t>0) s[i].push(t);
            else tt--;
        }
    }
}
int main(){
    scanf("%d%d%d",&N,&M,&D);
    vector<stack<int>> st(M);
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            int v;
            scanf("%d",&v);
            if(v) {
                st[j].push(N-i+1); 
                total++;
            }
        }
    }
    vector<bool> seq(M);
    for(int i=M-3;i<M;i++) seq[i]=1;
    do{
        vector<int> a;
        for(int i=0;i<seq.size();i++) if(seq[i]) a.push_back(i);

        auto cpst = st;
        int cnt = 0;
        tt = total;
        while(1){
            set<int> rmv;
            for(auto sx : a){
                int mxidx = -1, minv = 1<<9;
                for(int x=0;x<M;x++){
                    if(cpst[x].empty()) continue;
                    int ey = cpst[x].top();
                    int d = dist(sx,ey,x);
                    if(d>D) continue;
                    if(minv > d){
                        mxidx = x;
                        minv = d;
                    }
                }
                if(mxidx!=-1) rmv.insert(mxidx);
            }
            for(auto r : rmv){
                cpst[r].pop();
                cnt++;
                tt--;
            }
            fwd(cpst);
            if(tt==0) break;
        }
        ans = max(ans,cnt);
    }while(next_permutation(seq.begin(),seq.end()));
    printf("%d",ans);
}


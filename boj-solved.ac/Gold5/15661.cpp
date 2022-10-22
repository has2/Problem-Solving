#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N,d[20][20],ans=9e8;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) scanf("%d",&d[i][j]);
    for(int i=0;i<(1<<N);i++){
        vector<int> a(N);
        vector<int> p,q;
        for(int j=0;j<N;j++){
            if(i&(1<<j)) {
                p.push_back(j);
                a[j]=1;
            }
            else q.push_back(j);
        }
        if(p.empty() || q.empty()) continue;
        int t1=0,t2=0;
        for(int j=0;j<p.size();j++){
            for(int k=0;k<p.size();k++){
                t1+=d[p[j]][p[k]];
            }
        }
        for(int j=0;j<q.size();j++){
            for(int k=0;k<q.size();k++){
                t2+=d[q[j]][q[k]];
            }
        }   
        ans=min(ans,abs(t1-t2));
    }
    printf("%d",ans);
}
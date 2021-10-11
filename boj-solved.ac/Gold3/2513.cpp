#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N,K,S,ans;
vector<pair<int,int>> apart[2];
int main(){
    scanf("%d%d%d",&N,&K,&S);
    for(int i=0;i<N;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(S>u) apart[0].push_back({u,v});
        else apart[1].push_back({u,v});
    }
    sort(apart[0].begin(),apart[0].end());
    sort(apart[1].begin(),apart[1].end());
    reverse(apart[1].begin(),apart[1].end());
    for(int k=0;k<2;k++){
        for(int i=0;i<apart[k].size();i++){
            int cur=0;
            for(int j=i;j<apart[k].size();j++){
                int t = cur + apart[k][j].second;
                if(t>=K){
                    apart[k][j].second = t - K;
                    cur=0;
                    ans+=2*abs(S-apart[k][i].first);
                    i=j;
                    if(t>K) i--;
                    break;
                }else{
                    cur+=apart[k][j].second;
                }
                if(j==apart[k].size()-1 && cur!=0){
                    ans+=2*abs(S-apart[k][i].first);
                    i=j;
                } 
            }
        }
    }
    printf("%d",ans);
}
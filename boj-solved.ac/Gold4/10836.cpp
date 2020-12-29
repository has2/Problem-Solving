//gold4 10836 여왕벌
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,map[700][700],t[1400],a[1000000][3],mi;
pair<int,int> cnt[3];
int main(){
    scanf("%d%d",&N,&M);
    
    for(int i=0;i<M;i++){
        for(int j=0;j<3;j++){
            int v;
            scanf("%d",&v);
            cnt[j].second=j;
            cnt[j].first+=v;
            a[i][j]=v;
        }
    }
    sort(cnt,cnt+3);
    mi = cnt[2].second;
    for(int i=0;i<2*N;i++) t[i]=mi*M;

    for(int i=0;i<M;i++){
        int k=0;
        for(int j=0;j<3;j++){
            int s=k,e=k+a[i][j];
            if(j!=mi){
               for(int l=s;l<e;l++){
                   t[l]+=(j-mi);
               } 
            }
            k=e;
        }
    }
    int j=0;
    for(int i=N-1;i>=0;i--) map[i][0] = t[j++];
    for(int i=1;i<N;i++) map[0][i] = t[j++];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i&&j) map[i][j] = max(map[i-1][j-1],max(map[i-1][j],map[i][j-1]));
            printf("%d ",map[i][j]+1);
        }
        puts("");
    }
}
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int N,a[1001][5],mi,mv;
set<int> same[1001];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            int p;
            scanf("%d",&p);
            a[i][j]=p;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(j!=k&&a[j][i]==a[k][i]) same[j].insert(k);
            }
        }
    }
    for(int i=0;i<N;i++){
        if(same[i].size()>mv){
            mv=same[i].size();
            mi=i;
        }
    }
    printf("%d",mi+1);
}
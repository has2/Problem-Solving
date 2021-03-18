#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
vector<int> a,b;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    scanf("%d",&N);
    a.resize(N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    scanf("%d",&M);
    b.resize(M);
    for(int i=0;i<M;i++) scanf("%d",&b[i]);

    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp);
    if(a[0]<b[0]) {
        puts("-1");
        return 0;
    }
    int ans =0;
    while(b.size()!=0){
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                if(a[i]>=b[j]){
                    b.erase(b.begin()+j);
                    break;
                }
            }
        }
        ans++;
    }
    printf("%d",ans);
}
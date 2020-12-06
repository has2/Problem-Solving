#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;
int N,a[5000],r[3];
ll mxN = 9e10;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    sort(a,a+N);

    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            ll s = a[i]+a[j];
            int idx = lower_bound(a,a+N,-s)-a;
            for(int k=idx-5;k<idx+5;k++){
                if(k<0||k>=N||k==i||k==j) continue;
                ll ss = abs(s+a[k]);
                if(ss < mxN){
                    mxN = ss;
                    r[0]=i,r[1]=j,r[2]=k;
                }
            }
        }
    }
    sort(r,r+3);
    for(int i=0;i<3;i++) printf("%d ",a[r[i]]);
}
    

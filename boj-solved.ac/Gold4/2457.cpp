#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[] = {0,31,28,31,30,31,30,31,31,30,31,30,31},base[13];
int N,ans;
vector<pair<int,int>> v;
int main(){
    for(int i=1;i<=12;i++) base[i]=a[i-1]+base[i-1];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int b[4];
        for(int j=0;j<4;j++) scanf("%d",&b[j]);
        v.push_back({base[b[0]]+b[1],base[b[2]]+b[3]});
    }
    sort(v.begin(),v.end());

    int s=base[3]+1,e=base[11]+30,mxr=-1,ok=0;
    for(int i=0;i<N;i++){
        auto p = v[i];
        int l=p.first,r=p.second;
        if(l<=s) {
            mxr=max(r,mxr);
            if(mxr > e){
                ok=1;
                ans++;
                break;
            }
        }
        else {
            if(mxr==-1) break;
            ans++;
            s=mxr;
            mxr=-1;
            i--;
        }
    }
    printf("%d",ok?ans:0);
}
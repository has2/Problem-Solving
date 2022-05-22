#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<int> info,ans;
int ansv=-1,n;
void cmp(vector<int> v){
    int a=0,b=0;
    for(int i=0;i<=10;i++){
        if(info[i]==0&&v[i]==0) continue;
        if(info[i]>=v[i]){
            a+=10-i;
        }else{
            b+=10-i;
        }
    }
    if(b>a){
        if(ansv<b-a){
            ansv=b-a;
            ans=v;
        }else if(ansv==b-a){
            vector<int> rans=ans,rv=v;
            reverse(rans.begin(),rans.end());
            reverse(rv.begin(),rv.end());
            if(rv>=rans){
                ans=v;
            }
        }
    }
}
void sol(int m,int cur,vector<int> v){
    if(m==11){
        if(cur!=0) return;
        cmp(v);
        return;
    }
    for(int i=0;i<=cur;i++){
        v.push_back(i);
        sol(m+1,cur-i,v);
        v.pop_back();
    }
}
vector<int> solution(int _n, vector<int> _info) {
    info=_info;
    n=_n;
    sol(0,n,{});
    if(ansv==-1) ans={-1};
    return ans;
}
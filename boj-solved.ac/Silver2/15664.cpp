#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int N,M,a[8];
set<vector<int>> st;
vector<int> ans;
void sol(int n){
    if(n==N){
        if(ans.size()==M) {
            if(st.find(ans) == st.end()){
                st.insert(ans);
                for(auto k : ans) printf("%d ",k);
                puts("");
            }
        }
        return;
    }
    ans.push_back(a[n]);
    sol(n+1);
    ans.pop_back();
    sol(n+1);
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    sort(a,a+N);
    sol(0);
}
#include <cstdio>
#include <set>
using namespace std;
using ll = long long;
int N,a[100001];
ll ans;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    int j=1;
    set<int> st={a[1]};
    for(int i=1;i<=N;i++){
        ans+=st.size();
        for(int k=j+1;k<=N+1;k++){
            if(k==N+1) {
                j=N+1;
                break;
            }
            if(st.find(a[k])!=st.end()) {
                j=k-1;
                break;
            }
            st.insert(a[k]);
            ans++;
        }
        st.erase(a[i]);
    }
    printf("%lld",ans);
}
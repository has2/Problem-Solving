#include <cstdio>
#include <stack>
using namespace std;
int N,h[80001];
long long ans;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&h[i]);
    h[N]=2e9;
    stack<int> st;
    for(int i=0;i<=N;i++){
        while(!st.empty() && h[st.top()] <= h[i]){
                ans+=i-st.top()-1;   
                st.pop();
        }
        st.push(i);
    }
    printf("%lld",ans);
}


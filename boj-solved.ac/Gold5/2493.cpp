#include <cstdio>
#include <stack>
using namespace std;
int N,a[500000],ans[500000];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    stack<int> st;
    for(int i=0;i<N;i++){   
        while(!st.empty() && a[st.top()]<=a[i]) st.pop();     
        if(st.empty()) ans[i]=-1;
        else ans[i] = st.top();
        st.push(i);
    }
    for(int i=0;i<N;i++) printf("%d ",ans[i]+1);
}
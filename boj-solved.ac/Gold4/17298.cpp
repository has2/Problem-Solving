#include <cstdio>
#include <stack>
using namespace std;
int N,a[1000000],nge[1000000];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d",&a[i]);
        nge[i]=-1;
    }
    stack<int> st;
    for(int i=0;i<N;i++){
        while(!st.empty() && a[i] > a[st.top()]) {
            nge[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i=0;i<N;i++) printf("%d ",nge[i]);
}
#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <cctype>
using namespace std;
string s;
int main(){
    cin >> s;
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') st.push(-1);
        else if(isalnum(s[i])){
            if(i<s.size()-1 && s[i+1]=='(') st.push(s[i]-'0');
            else st.push(1);
        }else{
            int len=0;
            while(st.top()!=-1) {
                len+=st.top();
                st.pop();
            }
            st.pop();
            len*=st.top(); st.pop();
            st.push(len);
        }
    }
    int ans=0;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    printf("%d",ans);
}
#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
using namespace std;
string s;
int sol(){
    stack<char> st;
    int total=0,cur=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            cur*=2;
            st.push(s[i]);
        }else if(s[i]=='['){
            cur*=3;
            st.push(s[i]);
        }else{
            if(st.empty()) return 0;
            if(s[i]==')') {
                if(st.top()!='(') return 0;
            }else{
                if(st.top()!='[') return 0;
            }
            st.pop();
            if(s[i-1]=='('||s[i-1]=='[') total+=cur;
            if(s[i]==')') {
                cur/=2;
            }else{
                cur/=3;
            }
        }
    }
    if(!st.empty()) return 0;
    return total;
}
int main(){
    cin >> s;
    cout << sol();
}
#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
string s;
vector<pair<int,int>> v;
int main(){
    cin >> s;
    stack<int> st;
    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(c=='(') st.push(i);
        else if(c==')'){
            v.push_back({st.top(),i});
            st.pop();
        }
    }
    set<string> ans;
    int n = v.size();
    for(int i=1;i<(1<<n);i++){
        vector<bool> erased(s.size());
        for(int j=0;j<n;j++){
            if(((1<<j)&i)>0) erased[v[j].first]=erased[v[j].second]=1;
        }
        string tmp;
        for(int j=0;j<s.size();j++){
            if(!erased[j]) tmp+=s[j];
        }
        ans.insert(tmp);
    }
    for(auto a : ans) cout << a << '\n';
}
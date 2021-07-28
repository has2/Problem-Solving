#include <string>
#include <vector>
#include <list>
#include <stack>
using namespace std;
list<char> li;

bool check(){
    stack<char> st;
    for(auto c : li){
        if(c=='['||c=='{'||c=='(') st.push(c);
        else {
            if(st.empty()) return 0;
            if(c==']'){
                if(st.top()!='[') return 0;
            }
            if(c=='}'){
                if(st.top()!='{') return 0;
            }            
            if(c==')'){
                if(st.top()!='(') return 0;
            }        
            st.pop();
        }
    }
    return st.empty();
}

int solution(string s) {
    int ans=0; 
    for(char c : s) li.push_back(c);
    
    for(int i=0;i<s.size();i++){
        ans+=check();
        
        li.push_back(li.front());
        li.pop_front();
    }
    
    return ans;
}
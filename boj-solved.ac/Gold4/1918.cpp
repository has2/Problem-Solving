#include <stack>
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
string a,ret;
int p(char c){
    if(c=='(') return 0;
    if(c=='+'||c=='-') return 1;
    return 2;
}
int main(){
    cin >> a;
    stack<char> s; 
    for(char c : a){
        if(isalpha(c)) ret+=c;
        else if(c=='(') s.push(c);
        else if(c==')'){
            while(1){
                char op = s.top(); s.pop();
                if(op=='(') break;
                ret+=op;
            }
        }
        else{
            while(!s.empty() && p(s.top()) >= p(c)) {
                ret+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()) {
        ret+=s.top();
        s.pop();
    }
    cout << ret;
}
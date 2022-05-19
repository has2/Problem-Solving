#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string S,T;
bool ok;
void sol(string s){
    if(s==S){
        ok=1;
        return;
    }
    if(s.size()<=S.size()) return;
    if(s.front()=='B'){
        string tmp = s;
        reverse(tmp.begin(),tmp.end());
        tmp.pop_back();
        sol(tmp);
    }
    if(s.back()=='A'){
        s.pop_back();
        sol(s);
    }
}
int main(){
    cin >> S >> T;
    sol(T);
    cout << ok;
}
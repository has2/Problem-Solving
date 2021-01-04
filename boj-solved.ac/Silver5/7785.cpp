#include <iostream>
#include <string>
#include <set>
using namespace std;
int N;
int main(){
    cin >> N;
    set<string> st;
    while(N--){
        string a,b;
        cin >> a >> b;
        if(b=="enter") st.insert(a);
        else st.erase(a);
    }
    for(auto it = st.rbegin();it!=st.rend();it++) cout << *it << '\n';
}

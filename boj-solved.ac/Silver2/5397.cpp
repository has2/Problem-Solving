#include <iostream>
#include <list>
#include <string>
using namespace std;
int N;
string s;
int main(){
    cin >> N;
    while(N--){
        cin >> s;
        list<char> li;
        auto it = li.begin();
        for(auto c : s){
            if(c=='-'){
                if(it==li.begin()) continue;
                it--;
                it = li.erase(it);
            }else if(c=='<'){
                if(it==li.begin()) continue;
                it--;
            }else if(c=='>'){
                if(it!=li.end()) it++;
            }else{
                li.insert(it,c);
            }
        }
        for(auto v : li) cout << v;
        cout << "\n";
    }
}
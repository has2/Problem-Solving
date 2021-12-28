#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string A,B;
int main(){
    cin >> A >> B;

    while(!B.empty()){
        if(A==B) {
            cout << "1";
            return 0;
        }
        if(B.back()=='A') B.pop_back();
        else {
            B.pop_back();
            reverse(B.begin(),B.end());
        }
    }
    cout << "0";
}
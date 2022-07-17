#include <iostream>
#include <string>
using namespace std;
int N;
string s,sen[] = {"000000","001111","010011","011100","100110","101001","110101","111010"};
int cmp(string v,int i){
    int ret=0;
    for(int j=0;j<6;j++){
        if(sen[i][j]!=v[j]) ret++;
    }
    return ret;
}
int main(){
    cin >> N >> s;
    string ans;
    for(int i=0;i<N;i++){
        string t = s.substr(i*6,6);
        bool ok=0;
        for(int j=0;j<8;j++){
            if(cmp(t,j)<=1) {
                ok=1;
                ans+=('A'+j);
                break;
            }
        }
        if(!ok) {
            cout << i+1;
            return 0;
        }
    }
    cout << ans;
}
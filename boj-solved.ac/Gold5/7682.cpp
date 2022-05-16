#include <iostream>
#include <string>
#include <cstring>
#include <set>
using namespace std;
int a[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
int board[3][3];
string s;
set<string> ans;
bool check(string t,int i){
    if(t[a[i][0]]=='.') return 0;
    for(int j=1;j<3;j++){
        if(t[a[i][0]]!=t[a[i][j]]) return 0;
    }
    return 1;
}
void sol(int n){
    string tmp;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==1) tmp+='X';
            else if(board[i][j]==2) tmp+='O';
            else tmp+='.';
        }
    }
    for(int i=0;i<8;i++){
        if(check(tmp,i)){
            ans.insert(tmp);
            return;
        }
    }
    if(n==9) {
        ans.insert(tmp);
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=0) continue;
            board[i][j] = n%2+1;
            sol(n+1);
            board[i][j]=0;
        }
    }
}
int main(){
    sol(0);
    while(1){
        cin >> s;
        if(s=="end") return 0;
        if(ans.find(s) !=ans.end()) puts("valid");
        else puts("invalid");
    }
}
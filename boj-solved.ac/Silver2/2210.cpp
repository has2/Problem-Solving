#include <cstdio>
#include <set>
#include <string>
#include <cstring>
using namespace std;
int dy[4]={-1,1,0,0},dx[4]={0,0,1,-1},board[5][5],ans;
set<string> st;
void sol(int y,int x,string s){
    if(s.size()==6){
        st.insert(s);
        return;
    }
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=5||nx>=5) continue;
        char c = board[ny][nx]+'0';
        string t;
        t=s+c;
        sol(ny,nx,t);
    }
}
int main(){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++) scanf("%d",&board[i][j]);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            string t;
            t+=(board[i][j]+'0');
            sol(i,j,t);
        }
    }
    printf("%d",st.size());
}
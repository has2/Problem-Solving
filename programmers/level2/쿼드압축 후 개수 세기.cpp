#include <string>
#include <vector>
using namespace std;
vector<int> answer(2);
vector<vector<int>> arr;
int same(int y,int x,int n){
    int t = arr[y][x];
    for(int i=y;i<y+n;i++)
        for(int j=x;j<x+n;j++)
            if(t!=arr[i][j]) return -1;
    return t;
}
void sol(int y,int x,int n){
    int ret = same(y,x,n);
    if(ret!=-1){
        answer[ret]++;
        return;
    }    
    int b = n/2;
    sol(y,x,b);
    sol(y+b,x,b);
    sol(y,x+b,b);
    sol(y+b,x+b,b);
}

vector<int> solution(vector<vector<int>> _arr) {
    arr=_arr;
    sol(0,0,arr.size());
    return answer;
}
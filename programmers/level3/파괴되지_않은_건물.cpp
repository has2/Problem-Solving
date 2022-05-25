#include <string>
#include <vector>
using namespace std;
int sum[1002][1002],N,M;
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    N=board.size();
    M=board[0].size();
    for(auto s : skill){
        int d=s[5];
        if(s[0]==1) d*=-1;
        sum[s[1]][s[2]]+=d;
        sum[s[3]+1][s[2]]+=-d;
        sum[s[1]][s[4]+1]+=-d;
        sum[s[3]+1][s[4]+1]+=d;
    }
    for(int i=0;i<N;i++)
        for(int j=1;j<M;j++) sum[i][j]+=sum[i][j-1];

    for(int i=0;i<M;i++)
        for(int j=1;j<N;j++) sum[j][i]+=sum[j-1][i];
   
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) if(board[i][j]+sum[i][j]>0) answer++;
 
    return answer;
}
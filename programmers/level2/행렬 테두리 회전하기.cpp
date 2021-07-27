#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
using vvi=vector<vector<int>>;
int N,M;
int rotate(int y1,int x1,int y2,int x2,vector<vector<int>>& map){
    int ret = 9e8;
    vvi tmp = map;
    
    for(int i=x1+1;i<=x2;i++) ret=min(ret,tmp[y1][i]=map[y1][i-1]);
    for(int i=y1+1;i<=y2;i++) ret=min(ret,tmp[i][x2]=map[i-1][x2]); 
    for(int i=x2-1;i>=x1;i--) ret=min(ret,tmp[y2][i]=map[y2][i+1]); 
    for(int i=y2-1;i>=y1;i--) ret=min(ret,tmp[i][x1]=map[i+1][x1]);
    map=tmp;
    return ret;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    N=rows;
    M=columns;
    vvi map(N+1,vector<int>(M+1));
    int k=0;
    for(int y=1;y<=N;y++)
        for(int x=1;x<=M;x++)
            map[y][x] = ++k;
    for(auto v : queries) answer.push_back(rotate(v[0],v[1],v[2],v[3],map));
    return answer;
}
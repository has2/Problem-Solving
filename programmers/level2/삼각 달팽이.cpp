#include <string>
#include <vector>
using namespace std;
int map[1001][1001];
vector<int> solution(int n) {
    vector<int> answer;
    int y=1,x=1,k=0;
    for(int i=n;i>=1;i-=3){
        map[y][x]=++k;       
        for(int j=0;j<i-1;j++) map[++y][x]=++k;
        for(int j=0;j<i-1;j++) map[y][++x]=++k;
        for(int j=0;j<i-2;j++) map[--y][--x]=++k;
        y++;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            answer.push_back(map[i][j]);   
    return answer;
}
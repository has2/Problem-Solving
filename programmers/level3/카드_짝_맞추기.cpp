
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <queue>
using namespace std;
int total,ans=987654321;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int R,C;
bool visit[4][4];
vector<pair<int,int>> table[7];
vector<int> seq;
vector<pair<int,int>> mseq;
vector<vector<int>> org_board,board;
bool inRagne(int y,int x){
    return y>=0&&x>=0&&y<4&&x<4;
}
pair<int,int> end(int y,int x,int k){
    while(1){
        y+=dy[k]; x+=dx[k];
        if(!inRagne(y,x)){
            y-=dy[k], x-=dx[k];
            break;
        }
        if(board[y][x]>0) break;
    }
    return {y,x};
}
int bfs(int fy,int fx,int ty,int tx){
    memset(visit,0,sizeof(visit));
    queue<pair<int,int>> q;
    visit[fy][fx]=1;
    q.push({fy,fx});
    int ret=0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto [y,x] = q.front(); q.pop();
            if(y==ty&&x==tx) return ret;
            for(int i=0;i<4;i++){
                int ny=y+dy[i],nx=x+dx[i];
                if(!inRagne(ny,nx)) continue;
                if(!visit[ny][nx]){
                    q.push({ny,nx});
                    visit[ny][nx]=1;
                }
                auto [ky,kx] = end(y,x,i);
                if(!visit[ky][kx]){
                    q.push({ky,kx});
                    visit[ky][kx]=1;
                }
            }
        }
        ret++;
    }
    return -1;
}
void sol(int n){
    if(n==total){
        board = org_board;
        int cy=R,cx=C,res=0;
        for(int i=0;i<mseq.size();i++){
            auto [ny,nx] = mseq[i];
            res+=bfs(cy,cx,ny,nx);
            if(i&1) board[ny][nx]=board[cy][cx]=0;
            cy=ny,cx=nx;
        }
        ans=min(ans,res);
        return;
    }
    int cur = seq[n];
    mseq.push_back(table[cur][0]); mseq.push_back(table[cur][1]);
    sol(n+1);
    mseq.pop_back(); mseq.pop_back();

    mseq.push_back(table[cur][1]); mseq.push_back(table[cur][0]);
    sol(n+1);
    mseq.pop_back(); mseq.pop_back();
}
int solution(vector<vector<int>> board, int r, int c) {
    R=r, C=c;
    org_board = board;
    set<int> st;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++) {
            if(board[i][j]>0) {
                st.insert(board[i][j]);
                table[board[i][j]].push_back({i,j});
            }
        }
    total = st.size();
    for(auto v : st) seq.push_back(v);
    do{
        sol(0);
    }while(next_permutation(seq.begin(),seq.end()));
    return ans+st.size()*2;
}
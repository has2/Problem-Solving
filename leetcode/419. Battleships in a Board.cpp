#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

struct P {
	int y;
	int x;
	P(int y, int x) :y(y), x(x) {}
};

void bfs(int a, int b, vector<vector<char>>& board,vector<vector<bool>>& visit) {

	queue<P> q;
	q.push(P(a, b));
	visit[a][b] = 1;

	while (!q.empty()) {

		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ty = cy + dy[i];
			int tx = cx + dx[i];
			if (ty < 0 || tx < 0 || ty >= N || tx >= M || visit[ty][tx] || board[ty][tx] =='.') continue;
			q.push(P(ty, tx));
			visit[ty][tx] = 1;
		}
	}

}

class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int ans = 0;
		N = board.size();
		M = board[0].size();
		vector<vector<bool>> visit(N);
		for (int i = 0; i < N;i++) visit[i].resize(M);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 'X' && !visit[i][j]) {
					bfs(i, j, board, visit);
					ans++;
				}
			}
		}

		return ans;
	}
};
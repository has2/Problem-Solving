#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int M, N;
bool visit[101][101];

int dfs(vector<vector<int>>& picture, int y, int x) {
	
	visit[y][x] = 1;

	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		
		if (ty < 0 || tx < 0 || ty >= M || tx >= N || visit[ty][tx]
			|| picture[ty][tx] != picture[y][x]) continue;

		ret += dfs(picture, ty, tx);
	}
	return ret;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	M = picture.size();
	N = picture[0].size();

	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (picture[i][j] == 0 || visit[i][j]) continue;
			number_of_area++;
			max_size_of_one_area = max(max_size_of_one_area, dfs(picture, i, j));
		}
	}


	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
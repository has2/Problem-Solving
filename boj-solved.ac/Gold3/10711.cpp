#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
vector<string> map;
int dy[8] = { 1,-1,0,0,1,1,-1,-1 };
int dx[8] = { 0,0,1,-1,-1,1,-1,1 };
int h, w, ans;
int check(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (map[ny][nx] == '.') cnt++;
	}
	return cnt;
}
bool canadd(int y, int x) {
	return map[y][x] != '.' && check(y, x) >= map[y][x] - '0';
}
int main() {
	scanf("%d%d", &h, &w);
	
	for (int i = 0; i < h; i++) {
		string ip;
		cin >> ip;
		map.push_back(ip);
	}
	set<P> rmv;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (canadd(i, j)) rmv.insert({ i,j });
		}
	}

	while (1) {
		if (rmv.empty()) {
			printf("%d", ans);
			return 0;
		}
		set<P> next;
		for (auto p : rmv) map[p.first][p.second] = '.';
		for (auto p : rmv) {
			for (int d = 0; d < 8; d++) {
				int y = p.first + dy[d];
				int x = p.second + dx[d];
				if (next.find({ y,x }) != next.end()) continue;
				if (canadd(y, x)) next.insert({ y,x });
			}
		}
		rmv = next;
		ans++;
	}
}
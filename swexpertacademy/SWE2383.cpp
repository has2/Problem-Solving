//SW Expert
//ID : 2383 // brute force, bitmask
//2017/10/08

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n,m,t;
vector<pair<int, int>> st,people;
vector<int> stlen;

struct STAIR {
	int wait=0;
	int cur_people=0;
	int remain[3] = {0};
};

int getTime(int possible) {

	int total = people.size();
	vector<pair<int, int>> reach;
	STAIR stair[2];
	for (int i = 0; i < people.size(); i++) {
		int stnum = ((1 << i) & possible) ? 1 : 0;
		int sy = st[stnum].first, sx = st[stnum].second;
		int py = people[i].first, px = people[i].second;
		reach.push_back(make_pair(stnum, abs(sy - py) + abs(sx - px)));
	}

	for (int time = 0; ; time++) {
		for (int k=0; k < 2; k++) {

			if (stair[k].cur_people > 0) {
				for (int i = 0; i < 3; i++) {
					if (stair[k].remain[i] > 0) {
						if (--stair[k].remain[i] == 0) {
							stair[k].cur_people--;
							total--;
						}
					}
				}
			}

			if (stair[k].cur_people < 3 && stair[k].wait > 0) {
				for (int i = 0; i < 3; i++) {
					if (stair[k].wait == 0) break;
					if (stair[k].remain[i] == 0) {
						stair[k].remain[i] = stlen[k];
						stair[k].cur_people++;
						stair[k].wait--;
					}
				}
			}

			for (int i = 0; i < people.size(); i++) {

				if (reach[i].first != k || reach[i].second != time) continue;
				
				if (stair[k].cur_people < 3) {
					for (int j = 0; j < 3; j++) {
						if (stair[k].remain[j] == 0) {
							stair[k].remain[j] = stlen[k];
							stair[k].cur_people++;
							break;
						}
					}
				}
				else stair[k].wait++;
			}
		}
		if (total == 0) return time+1;
	}
}


int main() {
	
	int tcase;
	scanf("%d", &tcase);
	for (int tc = 1; tc <= tcase; tc++) {
		st.clear();
		people.clear();
		stlen.clear();
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &t);
				if (t == 1) {
					people.push_back(make_pair(i, j));
				}
				else if (t > 1) {
					st.push_back(make_pair(i, j));
					stlen.push_back(t);
				}
			}

		int possible = (1 << people.size()) - 1;
		int ret = 987654321;
		for (int i = 0; i <= possible; i++) ret = min(getTime(i), ret);
		printf("#%d %d\n",tc,ret);
	}
}
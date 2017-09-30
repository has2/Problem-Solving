//BOJ
//ID : 1713 
//2017/09/25

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, c, curtime;

int main() {

	scanf("%d%d", &n, &c);
	vector<int> tl;
	vector<pair<int, int>> stu(101);

	while (c--) {

		curtime++;

		int target;
		scanf("%d", &target);

		if (tl.size() < n) {

			bool ok = false;

			int idx = -1;
			for (int i = 0; i < tl.size(); i++)
				if (tl[i] == target) {
					ok = true;
					idx = i;
					break;
				}

			if (ok) {
				stu[tl[idx]].first++;
				continue;
			}

			stu[target].first = 1;
			stu[target].second = curtime;
			tl.push_back(target);

		}
		else {

			bool ok = false;

			int idx = -1;
			for (int i = 0; i < n; i++)
				if (tl[i] == target) {
					ok = true;
					idx = i;
					break;
				}

			if (ok) {
				stu[tl[idx]].first++;
				continue;
			}

			int mincnt = 20000;
			int minidx = -1;
			int time = 20000;

			for (int i = 0; i < n; i++) {

				int sidx = tl[i];

				if (stu[sidx].first < mincnt || (stu[sidx].first == mincnt && stu[sidx].second < time)) {
					minidx = i;
					mincnt = stu[sidx].first;
					time = stu[sidx].second;
				}

			}
			stu[tl[minidx]].first = 0;
			stu[tl[minidx]].second = 0;

			tl[minidx] = target;
			stu[target].first = 1;
			stu[target].second = curtime;
		}
	}

	sort(tl.begin(), tl.end());

	for (auto p : tl)
		printf("%d ", p);
}
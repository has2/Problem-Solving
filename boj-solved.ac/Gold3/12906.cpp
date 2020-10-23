#include <vector>
#include <queue>
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

int main() {

	vector<string> a(3);
	vector<int> cnt(3);

	for (int i = 0; i < 3; i++) {
		int num;
		cin >> num;
		if (num > 0) {
			cin >> a[i];
			for (int j = 0; j < a[i].size(); j++) {
				cnt[a[i][j] - 'A']++;
			}
		}
	}

	queue<vector<string>> q;
	map<vector<string>, int> dist;
	dist[a] = 0;
	q.push(a);

	while (!q.empty()) {

		auto qf = q.front(); q.pop();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				if (qf[i].size() == 0) continue;

				vector<string> next = qf;
				char t = next[i].back();
				next[i].pop_back();
				next[j].push_back(t);

				if (dist.find(next) == dist.end()) {
					dist[next] = dist[qf] + 1;
					q.push(next);
				}
			}
		}

	}
	vector<string> ans(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			ans[i] += 'A' + i;
		}
	}
	cout << dist[ans] << endl;
}
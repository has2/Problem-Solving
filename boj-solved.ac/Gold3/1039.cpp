#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int mxN = 1e6 + 1;
bool visit[mxN][11];
int N,K,ans=-1;
int main() {
	string s;
	cin >> s >> K;
	N = s.size();
	queue<pair<int, int>> q;
	q.push({ stoi(s),0 });
	visit[stoi(s)][0] = 1;

	while (!q.empty()) {

		auto qf = q.front(); q.pop();
		int num = qf.first;
		int k = qf.second;
		string ns = to_string(num);
		if (k == K) {
			ans = max(ans, num);
			continue;
		}
		
		for (int i = 0; i < ns.size() - 1; i++) {
			for (int j = i + 1; j < ns.size(); j++) {
				string ts = ns;
				swap(ts[i], ts[j]);
				if (ts[0] == '0') continue;
				int ti = stoi(ts);
				if (!visit[ti][k+1]) {
					q.push({ ti,k + 1 });
					visit[ti][k + 1] = 1;
				}
			}
		}
	}
	printf("%d", ans);
}
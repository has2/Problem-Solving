#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

bool decision(double dist[][101],double d)  {

	vector<bool> visited(N + 1, false);
	queue<int> q;

	visited[1] = true;
	q.push(1);
	int cnt = 1;

	while (!q.empty()) {
		int here = q.front(); q.pop();

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && dist[here][i] <= d) {
				q.push(i);
				visited[i] = true;
				cnt++;
			}
		}
	}

	return N == cnt;
}

int main() {
	
	int c;
	scanf("%d", &c);
	while (c--) {
		double dist[101][101];
		pair<double, double> pos[101];
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			pos[i].first = x;
			pos[i].second = y;
		}

		for (int i = 1; i <= N; i++) {
			pair<double, double> A = pos[i];
			for (int j = 1; j <= N; j++) {
				pair<double, double> B = pos[j];
				double xdiff = A.first - B.first;
				double ydiff = A.second - B.second;
				dist[i][j] = sqrt(xdiff*xdiff + ydiff*ydiff);
			}
		}
		
		double lo = 0, hi = 1500.0;

		for (int it = 0; it < 100; it++) {

			double mid = (lo + hi) / 2.0;

			if (decision(dist,mid)) hi = mid;
			else lo = mid;
		}

		printf("%.2f\n", hi);
	}

}
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int N;
vector<pair<int, int>> lunch;
int w[10001], e[10001];

int main(void) {
	int c;
	scanf("%d", &c);
	while (c--) {

		lunch.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &w[i]);
		for (int i = 0; i < N; i++)
			scanf("%d", &e[i]);

		for (int i = 0; i < N; i++)
			lunch.push_back(make_pair(e[i], w[i]));

		sort(lunch.begin(), lunch.end(), greater<pair<int, int>>());

		int ret = 0, waiting = 0;
		for (pair<int, int> p : lunch) {
			waiting += p.second;
			ret = max(ret, waiting + p.first);
		}
		printf("%d\n", ret);
	}
	return 0;
}
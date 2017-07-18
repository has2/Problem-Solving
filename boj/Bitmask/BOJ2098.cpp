// boj 2098 : Bitmask / 여행하는 외판원
// 2017/07/19
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 987654321;
int n;
int dist[16][16];
int cache[16][1 << 16];

int shortPass(int cur, int visited) {

	if ((1 << n) - 1 == visited) return dist[cur][0];

	int& ret = cache[cur][visited];

	if (ret != -1) return ret;

	ret = INF;
	for (int next = 0; next < n; next++) {
		if (cur != next && (visited & (1 << next)) == 0) {
			int taken = visited | (1 << next);
			ret = min(ret, dist[cur][next] + shortPass(next,taken));
		}
	}

	return ret;

}

int main() {

	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &dist[i][j]);
			if (dist[i][j] == 0) dist[i][j] = INF;
		}
	}

	printf("%d\n", shortPass(0, 1));
}
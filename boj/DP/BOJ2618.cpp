//BOJ
//ID : 2618 // dp
//2017/10/10

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 987654321;
int n, w, py[1001], px[1001], cache[1001][1001],tmp;
pair<int,int> track[1001][1001];

int sol(int a, int b) {

	int m = max(a, b);
	if (m == w) return 0;

	int& ret = cache[a][b];
	if (ret != -1) return ret;
	
	int ay, ax, by, bx;
	if (a == 0) ay = ax = 1;
	else {
		ay = py[a];
		ax = px[a];
	}
	if (b == 0) by = bx = n;
	else {
		by = py[b];
		bx = px[b];
	}

	int na, nb;
	ret = INF;
	tmp = abs(ay - py[m + 1]) + abs(ax - px[m + 1]) + sol(m + 1, b);
	if (ret > tmp) {
		ret = tmp;
		na = m + 1, nb = b;
	}
	tmp = abs(by - py[m + 1]) + abs(bx - px[m + 1]) + sol(a, m + 1);
	if (ret > tmp) {
		ret = tmp;
		na = a, nb = m+1;
	}

	track[a][b] = make_pair(na, nb);

	return ret;
}

int main() {

	scanf("%d%d", &n,&w);
	for (int i = 1; i <= w; i++)
		scanf("%d%d", &py[i], &px[i]);

	memset(cache, -1, sizeof(cache));

	printf("%d\n", sol(0, 0));

	int a = track[0][0].first;
	int b = track[0][0].second;

	for (int i = 0; i < w; i++) {

		if (a > b) puts("1");
		else puts("2");

		int ta = a;
		int tb = b;
		a = track[ta][tb].first;
		b = track[ta][tb].second;
	}
}
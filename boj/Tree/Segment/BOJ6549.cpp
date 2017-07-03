#include <cstdio>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = numeric_limits<ll>::max();

vector<ll> rec;
vector<int> segtree;

int maketree(int l, int r, int cur_node) {
	int m = (l+r)/2;
	
	if (l == r) return segtree[cur_node] = l;
	else {
		int lchild = maketree(l, m, 2 * cur_node);
		int rchild = maketree(m + 1, r, 2 * cur_node + 1);
		return segtree[cur_node] = (rec[lchild] < rec[rchild]) ? lchild : rchild;
	}
}

int query(int l, int r, int cur_node, int cur_l, int cur_r) {

	if (l > cur_r || r < cur_l) return -1;
	if (l <= cur_l && cur_r <= r) return segtree[cur_node];

	int m = (cur_l + cur_r) / 2;

	int lchild = query(l, r, 2 * cur_node, cur_l, m);
	int rchild = query(l, r, 2 * cur_node + 1, m + 1, cur_r);

	if (lchild == -1)
		return rchild;
	else if (rchild == -1)
		return lchild;
	else {
		return (rec[lchild] <= rec[rchild]) ? lchild : rchild;
	}
}

long long get(int l, int r, int size) {

	int m = query(l, r, 1, 1, size);
	ll area = rec[m] * (r - l + 1);

	if (l <= m - 1)
		area = max(area, get(l, m - 1, size));
	if (r >= m + 1)
		area = max(area, get(m + 1, r, size));

	return area;
}

int main(void) {

	int N;
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;

		int size;
		for (size = 1; size<N; size *= 2) {}
		rec.clear();
		rec.resize(size + 1);
		segtree.clear();
		segtree.resize(2*size);
		for (int i = 1; i <= N; i++)
			scanf("%lld", &rec[i]);

		for (int i = N + 1; i <= size; i++) rec[i] = inf;
		maketree(1, size, 1);
		printf("%lld\n", get(1, N, size));
	}
}
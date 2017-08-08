//BOJ
//ID : 7578 / SegmentTree
//2017/07/26
#include <cstdio>
#include <algorithm>

typedef long long ll;
const ll MAX = 1000000;
int n;
ll segtree[4000001];
ll A[500001],B[1000001];

ll init(int l, int r, int node) {

	if (l == r) return 0;

	int mid = (l + r) / 2;

	return init(l, mid, 2 * node) + init(mid + 1, r, 2 * node + 1);
}

ll query(int l, int r, int node, int cur_l, int cur_r) {

	if (cur_r < l || r < cur_l) return 0;
	if (l <= cur_l && cur_r <= r) return segtree[node];

	int mid = (cur_l + cur_r) / 2;

	return query(l, r, 2 * node, cur_l, mid) + query(l, r, 2 * node + 1, mid + 1, cur_r);

}

void update(int target, int num,int size) {

	target = size + target - 1;
	segtree[target] = num;
	target /= 2;
	while (target > 0) {
		segtree[target] = segtree[target * 2] + segtree[target * 2 + 1];
		target /= 2;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &A[i]);
	for (int i = 1; i <= n; i++) {
		ll tmp;
		scanf("%lld", &tmp);
		B[tmp] = i;
	}

	int size;
	for(size=1;size<MAX;size*=2){}

	init(1, size, 1);
	ll total = 0;
	for (int i = 1; i <= n; i++) {
		int L = B[A[i]];
		total += query(L, n, 1, 1, size);
		update(L, 1, size);
	}
	printf("%lld", total);
}


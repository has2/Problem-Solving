//BOJ
//ID : 1275 // segment tree
//2017/09/23

#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
int n, m;
ll arr[100001], seg[400001];

ll init(int l, int r, int node) {

	if (l == r) return seg[node] = arr[l];

	int mid = (l + r) / 2;

	return seg[node] = init(l, mid, 2 * node) + init(mid + 1, r, 2 * node + 1);

}

ll query(int l, int r, int cl, int cr, int node) {

	if (l <= cl && cr <= r) return seg[node];

	if (r < cl || l > cr) return 0;

	int mid = (cl + cr) / 2;

	return query(l, r, cl, mid, 2 * node) + query(l, r, mid + 1, cr, 2 * node + 1);
}

void update(int pos, ll num, int size) {

	pos += size - 1;

	seg[pos] = num;
	while (pos > 1) {
		pos /= 2;
		seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);

	int size;
	for (size = 1; size <= n; size *= 2) {}

	init(1, size, 1);

	while (m--) {
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		if (x > y) printf("%lld\n", query(y, x, 1, size, 1));
		else printf("%lld\n", query(x, y, 1, size, 1));
		update(a, b, size);
	}
}


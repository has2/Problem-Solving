//BOJ
//ID : 5676 / Segment Tree
//2017/07/31

#include <cstdio>
#include <cstring>
#include <algorithm>

int n, k,size,tree[400001];
int seq[200001];

int init(int l, int r, int node) {

	if (l == r) {
		tree[node] = seq[l] > 0 ? 1 : -1;
		if (seq[l] == 0) tree[node] = 0;
		return tree[node];
	}
	
	int mid = (l + r) / 2;
	return tree[node] = init(l, mid, 2 * node) * init(mid + 1, r, 2 * node + 1);

}

int query(int l, int r, int node, int cur_l, int cur_r) {

	if (l > cur_r || r < cur_l) return 1;
	if (l <= cur_l && cur_r <= r) return tree[node];
	int mid = (cur_l + cur_r) / 2;
	return query(l, r, 2 * node, cur_l, mid) * query(l, r, 2 * node + 1, mid + 1, cur_r);
}

void update(int pos, int val) {
	pos = size + pos - 1;
	tree[pos] = val;
	pos /= 2;
	while (pos > 0) {
		tree[pos] = tree[2*pos] * tree[2*pos + 1];
		pos /= 2;
	}
}

int main() {

	while (scanf("%d%d", &n, &k) != EOF) {

		for(size=1;size<n;size*=2){}
		for (int i = 1; i <= n;i++) 
			scanf("%d", &seq[i]);

		for (int i = n + 1; i <= size; i++)
			seq[i] = 1;

		init(1, size, 1);
		while (k--) {

			char q;
			int a, b;
			scanf(" %c%d%d", &q, &a, &b);
			if (q == 'C') {
				if (b > 0) b = 1;
				else if (b < 0) b = -1;
				else b = 0;
				update(a, b);
			}
			else {
				int ret = query(a, b, 1, 1, size);
				if (ret > 0) printf("+");
				else if (ret < 0) printf("-");
				else printf("0");
			}
		}
		printf("\n");
	}
}

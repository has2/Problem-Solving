//BOJ
//ID : 3635 / Fenwick Tree
//2017/07/31

#include <cstdio>
#include <cstring>
const int MAX = 100000;
int n,m,fenwick[2*MAX+1];
int pos[MAX + 1],up;

int sum(int p) {
	int ret = 0;
	while (p > 0) {
		ret += fenwick[p];
		p &= (p - 1);
	}
	return ret;
}

void update(int p, int val) {

	while (p <= n + m) {
		fenwick[p] += val;
		p += (p&-p);
	}
}

int main() {
	int c;
	scanf("%d",&c);
	while (c--) {
		scanf("%d%d", &n, &m);
		up = m;
		for (int i = 1; i <= n; i++) {
			update(m+i, 1);
			pos[i] = m+i;
		}
		for (int i = 0; i < m; i++) {
			int mv;
			scanf("%d", &mv);
			printf("%d ", sum(pos[mv])-1);
			update(pos[mv], -1);
			pos[mv] = up--;
			update(pos[mv], 1);
		}
		memset(fenwick, 0, sizeof(fenwick));
	}
}


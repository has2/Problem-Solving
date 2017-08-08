//BOJ
//ID : 1717 / Disjoint Set
//2017/08/01

#include <cstdio>

int n, m,parent[1000001],rank[1000001];

int find(int u) {
	if (parent[u] == u) return u;

	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {

	u = find(u);  v = find(v);
	
	if (u == v) return;

	if (rank[u] > rank[v]) parent[v] = u;
	else if(rank[u] < rank[v]) parent[u] = v;
	else {
		parent[v] = u;
		rank[u]++;
	}
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		rank[i] = 1;
	}

	while (m--) {
		
		int q, a, b;
		scanf("%d%d%d", &q, &a, &b);

		if (q == 0) merge(a, b);
		else {
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}

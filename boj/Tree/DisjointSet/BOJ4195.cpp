//BOJ
//ID : 4195 / Disjoint Set
//2017/08/01
// char[]로 받아서 string에 할당 가능 while문안에 cin 있을시 무조건 scanf로

#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
using namespace std;
const int MAX = 200000;
int n, parent[MAX + 1],tmp;
int sz[MAX + 1];
int rk[MAX + 1];

int find(int u) {

	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {

	u = find(u);
	v = find(v);
	if (u == v) return;
	
	if (rk[u] < rk[v]) SWAP(u, v, tmp);

	if (rk[u] == rk[v]) rk[u]++;

	parent[v] = u;
	sz[u] += sz[v];
}

int main() {

	int t;
	scanf("%d", &t);
	map<string, int> mp;

	while (t--) {

		for (int i = 1; i <= MAX; i++) {
			rk[i] = 1;
			sz[i] = 1;
			parent[i] = i;
		}

		char u[21], v[21];
		int cnt = 1;
		scanf("%d", &n);
		while (n--) {
			scanf("%s %s", u, v);
			int uidx, vidx;
			if (mp[u] == 0) mp[u] = cnt++;
			uidx = mp[u];
			if (mp[v] == 0) mp[v] = cnt++;
			vidx = mp[v];

			merge(uidx, vidx);
			printf("%d\n", sz[find(uidx)]);
		}
		mp.clear();
	}
}

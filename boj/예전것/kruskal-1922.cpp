#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> Edge;
int parent[1001],total_cost=0;

bool mycompare(const Edge &lhs, const Edge &rhs) {
	return get<2>(lhs) < get<2>(rhs);
}

int FindSet(int x) {
	
	if (x == parent[x]) {
		return x;
	}
	else {
		return FindSet(parent[x]);
	}
}

void UNION(int u, int v) {
	int x = FindSet(u),y = FindSet(v);
	parent[x] = y;
}

void INITSET(int M) {
	for (int i = 1; i <= M; i++)
		parent[i] = i;
}

int main() {
	int N, M;
	vector<Edge> edge;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w); 
		edge.push_back(make_tuple(u, v, w));
	}

	sort(edge.begin(), edge.end(), mycompare);
	INITSET(N);
	//printf("%d %d", FindSet(get<0>(edge[0])), FindSet(get<1>(edge[0])));
	int count = 0;
	for (int i = 0; i < M; i++) {
		int u = get<0>(edge[i]), v = get<1>(edge[i]),w=get<2>(edge[i]);
		if (FindSet(u) != FindSet(v)) {
			printf("%d-%d", u, v);
			UNION(u, v);
			total_cost += w;
			count++;
			printf("c:%d\n", count);
			if (count == N - 1) {
				printf("%d\n", total_cost);
				return 0;
			}
		}
	}
}